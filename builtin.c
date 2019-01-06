/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 15:54:28 by mguerrea          #+#    #+#             */
/*   Updated: 2019/01/06 15:05:52 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
//		ft_putstr("env : i = ");
//		ft_putnbr(i);
//		printf("env[i] = %p\n", (*environ)[i]);
		ft_putendl((*environ)[i]);
		i++;
	}
//	ft_putstr_color("hello\n", "blue");
	return (1);
}