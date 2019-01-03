/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 14:45:44 by mguerrea          #+#    #+#             */
/*   Updated: 2019/01/03 14:54:03 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_prompt(void)
{
	char buf[PATH_MAX];

	getcwd(buf, PATH_MAX);
	ft_putstr(buf);
	ft_putstr(" $> ");
}