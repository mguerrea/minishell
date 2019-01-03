/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 14:37:54 by mguerrea          #+#    #+#             */
/*   Updated: 2019/01/03 23:38:30 by mguerrea         ###   ########.fr       */
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
	builtin_fct[5] = ft_unsetenv;
}

int execute(char **args, const char **builtin_lst, t_built_in *builtin_fct, char ***environ)
{
	int i;
	int ret;

	i = 0;
	if (args[0] == NULL)
		return (1);
	while (i < NB_BUILTIN)
	{
		if (ft_strcmp(args[0], builtin_lst[i]) == 0)
			return (builtin_fct[i](args, environ));
		i++;
	}
	return (launch_bin(args, environ));
}

int	wrong_quote(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		i++;
		if (str[i] == '"')
			count++;
	}
	return (count % 2);
}

char *ask_newline(char *line)
{
	char *tmp1;
	char *tmp2;

	ft_putstr("> ");
	get_next_line(0, &tmp1);
	tmp2 = line;
	line = ft_strjoin3(line, "\n", tmp1);
	free(tmp2);
	free(tmp1);
	return (line);
}

int main(int argc, char **argv, char **environ)
{
	char *line;
	char **args;
	char **env;
	char **cmd;
	int run;
	int i;
	t_built_in builtin_fct[NB_BUILTIN];
	const char *builtin_lst[] = {
		"cd",
		"exit",
		"echo",
		"env",
		"setenv",
		"unsetenv"
	};

	run = 1;
	fill_built(builtin_fct);
	env = ft_tabdup(env, environ);
	while (run)
	{
		i = 0;
		print_prompt(env);
		get_next_line(0, &line);
		while (wrong_quote(line))
			line = ask_newline(line);
		cmd = ft_strsplit(line, ';');
		while (cmd[i])
		{
			args = ft_strsplit(cmd[i], ' ');
			args = format_args(args, env);
			run = execute(args, builtin_lst, builtin_fct, &env);
			i++;
			free(args);
		}
		free(cmd);
		free(line);
	}
}