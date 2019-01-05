/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:54:28 by mguerrea          #+#    #+#             */
/*   Updated: 2019/01/05 14:20:20 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_cd(char **args, char ***environ)
{
	char *dir;
	char buf[PATH_MAX];
	char *home;
	char **var;

	dir = NULL;
	if (args[1] == NULL)
	{
//		printf("cd ?\n");
		if (!(var = ft_getenv(*environ, "HOME")) || !(dir = var[0]))
			ft_putendl("cd: HOME not set");
//		printf("getenv ?\n");
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
		if(!(var = ft_getenv(*environ, "HOME")) || !(var[0]))
			ft_putendl("cd: HOME not set");
		else
			dir = ft_strjoin(var[0], args[1] + 1);
		free_tab(var);
	}
	else
		dir = ft_strdup(args[1]);
	getcwd(buf, PATH_MAX);
//	ft_putstr_color("oui ?\n", "red");
	*environ = ft_setvar(*environ, "OLDPWD", buf);
//	ft_putstr_color("setvar ?\n", "red");
	if (dir && chdir(dir) != 0)
		error_cd(dir);
	getcwd(buf, PATH_MAX);
	*environ = ft_setvar(*environ, "PWD", buf);
//	ft_putstr_color("setvar 2 ?\n", "red");
	if (dir)
		ft_strdel(&dir);
	return (1);
}

int ft_exit(char **args, char ***environ)
{
	(void)args;
	(void)environ;
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
	//	ft_putnbr(i);
		ft_putendl((*environ)[i]);
		i++;
	}
	return (1);
}