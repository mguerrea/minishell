/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 14:45:44 by mguerrea          #+#    #+#             */
/*   Updated: 2019/01/03 22:39:06 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_prompt(char **environ)
{
	char buf[PATH_MAX];
	char *home;
	int len;

	getcwd(buf, PATH_MAX);
	home = ft_getenv(environ, "HOME")[0];
	len = (home) ? ft_strlen(home) : 0;
	if (home)
		ft_putchar('~');
	ft_putstr(buf + len);
	ft_putstr("$> ");
}