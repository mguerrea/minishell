/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 22:07:24 by mguerrea          #+#    #+#             */
/*   Updated: 2019/01/04 00:11:31 by mguerrea         ###   ########.fr       */
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

char *format_var(char *var, char **environ)
{
	char *value;

	value = ft_getenv(environ, var)[0];
//	free(var);
	var = value;
	return (var);

}

char **format_args(char **args, char **environ)
{
	int i;
	char *tmp;

	i = 0;
	while (args[i])
	{
		tmp = ft_strtrim(args[i]);
		ft_strdel(&args[i]);
		args[i] = ft_trimquotes(tmp);
		ft_strdel(&tmp);
		if (args[i][0] == '$')
			args[i] = format_var(args[i] + 1, environ);
		i++;
	}
	return (args);
}