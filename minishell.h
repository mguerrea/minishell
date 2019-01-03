/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 14:46:04 by mguerrea          #+#    #+#             */
/*   Updated: 2019/01/03 18:14:53 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <sys/param.h>
# include "libft/libft.h"

#define NB_BUILTIN 5

typedef int	(*t_built_in)(char **, char ***);

void	print_prompt(void);
int		ft_cd(char **args, char ***environ);
int		ft_exit(char **args, char ***environ);
int		ft_echo(char **args, char ***environ);
int		ft_env(char **args, char ***environ);
char	**ft_setvar(char **environ, char *var, char *value);
int		ft_setenv(char **args, char ***environ);
char	**ft_tabdup(char **dest, char **src);

#endif