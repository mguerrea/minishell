/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 14:37:54 by mguerrea          #+#    #+#             */
/*   Updated: 2019/01/03 18:19:59 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"
#include "minishell.h"

void	fill_built(t_built_in *builtin_fct)
{
	builtin_fct[0] = ft_cd;
	builtin_fct[1] = ft_exit;
	builtin_fct[2] = ft_echo;
	builtin_fct[3] = ft_env;
	builtin_fct[4] = ft_setenv;
}

int execute(char **args, const char **builtin_lst, t_built_in *builtin_fct, char ***environ)
{
	int i;
	int ret;

	i = 0;
	while (i < NB_BUILTIN)
	{
		if (ft_strcmp(args[0], builtin_lst[i]) == 0)
			return (builtin_fct[i](args, environ));
		i++;
	}
	return (1);
}

int main(int argc, char **argv, char **environ)
{
	char *line;
	char **args;
	char **env;
	int run;
	int i;
	t_built_in builtin_fct[NB_BUILTIN];
	const char *builtin_lst[] = {
		"cd",
		"exit",
		"echo",
		"env",
		"setenv"
	};

	run = 1;
	i = 0;
	fill_built(builtin_fct);
	env = ft_tabdup(env, environ);
	while (run)
	{
		print_prompt();
		get_next_line(0, &line);
		args = ft_strsplit(line, ' ');
		run = execute(args, builtin_lst, builtin_fct, &env);
		free(line);
		free(args);
	}
}