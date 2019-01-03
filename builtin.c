/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:54:28 by mguerrea          #+#    #+#             */
/*   Updated: 2019/01/03 18:17:55 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_cd(char **args, char ***environ)
{
	char *dir;
	char buf[PATH_MAX];

	if (args[1] == NULL)
	{
		if (!(dir = getenv("HOME")))
			ft_putendl("cd: HOME not set");
	}
	else if (ft_strcmp(args[1], "-") == 0)
	{
		if (!(dir = getenv("OLDPWD")))
			ft_putendl("cd: OLDPWD not set");
	}
	else
		dir = args[1];
	ft_setvar(*environ, "OLDPWD", getenv("PWD"));
	if (dir && chdir(dir) != 0)
		ft_putendl_fd("cd : error", 2);
	getcwd(buf, PATH_MAX);
	ft_setvar(*environ, "PWD", buf);
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
//	printf("i = %d\n", i);
//	ft_putstr_color(*environ[25], "red");
//	printf("environ = %s", environ[23]);
	return (1);
}