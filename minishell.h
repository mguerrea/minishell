/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 14:46:04 by mguerrea          #+#    #+#             */
/*   Updated: 2019/01/04 00:05:04 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <sys/param.h>
# include "libft/libft.h"

#define NB_BUILTIN 6

typedef int	(*t_built_in)(char **, char ***);

void	print_prompt(char **environ);
int		ft_cd(char **args, char ***environ);
int		ft_exit(char **args, char ***environ);
int		ft_echo(char **args, char ***environ);
int		ft_env(char **args, char ***environ);
char	**ft_setvar(char **environ, char *var, char *value);
int		ft_setenv(char **args, char ***environ);
char	**ft_tabdup(char **dest, char **src);
char	**ft_getenv(char **environ, char *var);
char	**ft_addentry(char **tab, int size, char *str);
void	ft_delentry(char ***tab, int pos);
int		ft_unsetenv(char **args, char ***environ);
int		launch_bin(char **args, char ***envriton);
void	error_cd(char *errors);
char	*ft_strjoin3(char *s1, char *s2, char *s3);
void	error_cmd(char *str);
char	**format_args(char **args, char **environ);
void	free_tab(char **tab);

#endif