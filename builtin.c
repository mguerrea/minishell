/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:54:28 by mguerrea          #+#    #+#             */
/*   Updated: 2019/01/03 23:41:00 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_cd(char **args, char ***environ)
{
	char *dir;
	char buf[PATH_MAX];
	char *home;

	if (args[1] == NULL)
	{
		if (!(dir = ft_getenv(*environ, "HOME")[0]))
			ft_putendl("cd: HOME not set");
	}
	else if (ft_strcmp(args[1], "-") == 0)
	{
		if (!(dir = ft_getenv(*environ, "OLDPWD")[0]))
			ft_putendl("cd: OLDPWD not set");
		else
			ft_putendl(dir);
	}
	else if (args[1][0] == '~')
	{
		if(!(home = ft_getenv(*environ, "HOME")[0]))
			ft_putendl("cd: HOME not set");
		dir = ft_strjoin(home, args[1] + 1);
		free(home);
	}
	else
		dir = ft_strdup(args[1]);
	getcwd(buf, PATH_MAX);
	ft_setvar(*environ, "OLDPWD", buf);
	if (dir && chdir(dir) != 0)
		error_cd(dir);
	getcwd(buf, PATH_MAX);
	ft_setvar(*environ, "PWD", buf);
	free (dir);
	return (1);
}

int ft_exit(char **args, char ***environ)
{
	(void)args;
	return (0);
}

int	ft_echo(char **args, char ***environ)
{
	int i;
	int n;

	if (args[1] == NULL)
	{
		ft_putchar('\n');
		return (1);
	}
	n = ft_strcmp(args[1], "-n");
	i = 1;
	if (n == 0)
		i++;
	while (args[i])
	{
		if (i > 2 || (i > 1 && n != 0))
			ft_putchar(' ');
		ft_putstr(args[i]);
		i++;
	}
	if (n != 0)
		ft_putchar('\n');
	return (1);
}

int ft_env(char **args, char ***environ)
{
	int i;

	i = 0;
	while ((*environ)[i])
	{
		ft_putendl((*environ)[i]);
		i++;
	}
	return (1);
}