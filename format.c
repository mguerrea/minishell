/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 22:07:24 by mguerrea          #+#    #+#             */
/*   Updated: 2019/01/05 18:41:22 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *ft_trimquotes(char *s)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] == '"')
		i++;
	j = ft_strlen((char *)s) - 1;
	while ((s[j] == '"') && j > i)
		j--;
	if (!(str = ft_strnew(j - i + 1)))
		return (NULL);
	k = -1;
	while (++k < j - i + 1)
		str[k] = s[i + k];
	return (str);
}

int format_var(char **var, char **environ)
{
	char **value;

	if (!(value = ft_getenv(environ, *(var) + 1)))
		return (-1);
	ft_strdel(var);
	if(!(*var = ft_strdup(value[0])))
		return (-1);
	free_tab(value);
	return (1);

}

int format_tilde(char ***args, int i, char **environ)
{
	char **var;
	char *temp;
	char *home;

	if (!(var = ft_getenv(environ, "HOME")))
		home = getpwuid(getuid())->pw_dir;
	else
		home = var[0];
	temp = ft_strjoin(home, (*args)[i] + 1);
//	ft_strdel(args[i]);
	(*args)[i] = temp;
//	ft_strdel(&temp);
//	free_tab(var);
	return (1);
}

void format_args(char ***args, char **environ)
{
	int i;
	char *tmp;

	i = 0;
	while ((*args)[i])
	{
		tmp = ft_strtrim((*args)[i]);
		ft_strdel(&((*args)[i]));
		(*args)[i] = ft_trimquotes(tmp);
		ft_strdel(&tmp);
		if ((*args)[i][0] == '$')
			format_var(&((*args)[i]), environ);
		else if ((*args)[i][0] == '~')
			format_tilde(args, i, environ);
		i++;
	}
//	return (args);
}