/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 19:56:10 by mguerrea          #+#    #+#             */
/*   Updated: 2019/01/03 21:22:41 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_cd(char *errors)
{
		ft_putstr_fd("cd: ", 2);
		ft_putstr_fd(errors, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
}

void	error_cmd(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putendl_fd(": command not found", 2);
}