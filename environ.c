/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 16:45:44 by mguerrea          #+#    #+#             */
/*   Updated: 2019/01/03 18:19:48 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_addentry(char **tab, int size, char *str)
{
	char **newtab;
	int i;

	i = 0;
//	printf("size = %d\n", size);
	if (!(newtab = (char **)malloc(sizeof(char *) * (size + 2))))
		return (NULL);
	while (tab[i])
	{
		if (!(newtab[i] = ft_strdup(tab[i])))
			return (NULL);
		i++;
	}
	if (!(newtab[i] = ft_strdup(str)))
		return (NULL);
	newtab[i + 1] = NULL;
	return (newtab);
}

char	**ft_setvar(char **environ, char *var, char *value)
{
	int i;
	char *str;

	i = 0;
	while (environ[i] && ft_strncmp(environ[i], var, ft_strlen(var)))
		i++;
	if (!(str = ft_strnew(ft_strlen(var) + ft_strlen(value) + 1)))
		return (NULL);
	ft_strcat(str, var);
	ft_strcat(str, "=");
	ft_strcat(str, value);
	if (!environ[i])
		environ = ft_addentry(environ, i, str);
	else
		environ[i] = str;
	return (environ);
}

int		ft_setenv(char **args, char ***environ)
{
	if (args[1] && args[2])
		*environ = ft_setvar(*environ, args[1], args[2]);
	else
		ft_putendl("too few arguments");
	return (1);
}