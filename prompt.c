/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 14:45:44 by mguerrea          #+#    #+#             */
/*   Updated: 2019/01/05 16:07:32 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_prompt(char **environ)
{
	char buf[PATH_MAX];
	char **home;
	int len;

	getcwd(buf, PATH_MAX);
//	if (home = ft_getenv(environ, "HOME"))
/*	len = (home[0]) ? ft_strlen(home[0]) : 0;
	if (home[0])
		ft_putchar('~');
	ft_putstr(buf + len); */
	ft_putstr(ft_strrchr(buf, '/') + 1);
	ft_putstr(" $> ");
//	free_tab(home);
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

char *get_cmd(char **env)
{
	char *line;

	print_prompt(env);
	get_next_line(0, &line);
	while (wrong_quote(line))
		line = ask_newline(line);
	return (line);
}