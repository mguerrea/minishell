/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 19:18:45 by mguerrea          #+#    #+#             */
/*   Updated: 2019/01/04 00:05:34 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	find_bin_path(char **environ, char **args)
{
	char **path_lst;
	int i;
	char *path;

	i = 0;
		path_lst = ft_getenv(environ, "PATH");
		while (path_lst[i])
		{
		if (!(path = ft_strjoin3(path_lst[i], "/", args[0])))
			return ;
		if (execve(path, args, environ) >= 0)
		{
			ft_strdel(&path);
			break ;
		}
		ft_strdel(&path);
		i++;
		}
		if (path_lst[i] == NULL)
			error_cmd(args[0]);
		free_tab(path_lst);
}

int		launch_bin(char **args, char ***environ)
{
	pid_t pid;
	char **path_lst;
	char *path;
	int i;

	i = 0;
	pid = fork();
	if (pid == -1)
	{
		ft_putendl_fd("fork error", 2);
		return (1) ;
	}
	else if (pid == 0)
	{
		if (ft_strchr(args[0], '/'))
		{
			if (execve(args[0], args, *environ) < 0)
				error_cmd(args[0]);
		}
		else
			find_bin_path(*environ, args);
		exit(0);
	}
	else
	{
		wait(NULL);
		return (1);
	}
}