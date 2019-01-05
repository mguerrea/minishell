/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 16:45:44 by mguerrea          #+#    #+#             */
/*   Updated: 2019/01/05 13:09:14 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
//	printf("i = %d\n", i);
	if (!environ[i])
		environ = ft_addentry(environ, i, str);
	else
		environ[i] = ft_strdup(str);
	ft_strdel(&str);
	return (environ);
}

int		ft_setenv(char **args, char ***environ)
{
	if (args[1] && args[2])
	{
		if (ft_strchr(args[1], '='))
			ft_putendl("invalid name, cannot contain '='");
		else
			*environ = ft_setvar(*environ, args[1], args[2]);
	}
	else
		ft_putendl("too few arguments");
	return (1);
}

int		ft_unsetenv(char **args, char ***environ)
{
	int i;

	i = 0;
	if (args[1])
	{
		while ((*environ)[i] && ft_strncmp((*environ)[i], args[1], ft_strlen(args[1])))
			i++;
		if ((*environ)[i])
			ft_delentry(environ, i);
	}
	return (1);
}

char **ft_getenv(char **environ, char *var)
{
	int i;
	char **lst;
	int start;
	int size;
	int end;

	i = 0;
	lst = NULL;
	while (environ[i] && ft_strncmp(environ[i], var, ft_strlen(var)))
		i++;
	if (environ[i])
		lst = ft_strsplit(ft_strchr(environ[i], '=') + 1, ':');
//	printf("lst ?\n");
	return (lst);
}