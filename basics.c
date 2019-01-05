/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 17:58:37 by mguerrea          #+#    #+#             */
/*   Updated: 2019/01/05 16:22:14 by mguerrea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char **ft_tabdup(char **dest, char **src)
{
	int i;

	i = 0;
	while (src[i])
		i++;
	if (!(dest = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	i = 0;
	while (src[i])
	{
		if (!(dest[i] = ft_strdup(src[i])))
			return (NULL);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}

char	**ft_addentry(char **tab, int size, char *str)
{
	char **newtab;
	int i;

	i = 0;
//	ft_putstr_color(str, "blue");
	if (!(newtab = (char **)malloc(sizeof(char *) * (size + 2))))
		return (NULL);
	while (tab[i])
	{
	//	printf("tab[%d] = %s\n", i, tab[i]);
		if (!(newtab[i] = ft_strdup(tab[i])))
			return (NULL);
		i++;
	}
	if (!(newtab[i] = ft_strdup(str)))
		return (NULL);
	newtab[i + 1] = NULL;
	if (tab)
		free_tab(tab);
	return (newtab);
}

void	ft_delentry(char ***tab, int pos)
{
	ft_strdel(&((*tab)[pos]));
//	printf("pos = %d\n", pos);
	while ((*tab)[pos + 1])
	{
		(*tab)[pos] = ft_strdup((*tab)[pos + 1]);
		ft_strdel(&((*tab)[pos + 1]));
		pos++;
	}
	if ((*tab)[pos])
		ft_strdel(&((*tab)[pos]));
}

char	*ft_strjoin3(char *s1, char *s2, char *s3)
{
	int		len;
	char	*str;

	len = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
	if (!(str = ft_strnew(len)))
		return (NULL);
	str = ft_strcat(str, s1);
	str = ft_strcat(str, s2);
	str = ft_strcat(str, s3);
	return (str);
}

/*char *get_line(int fd)
{
	char *line;
	char buf[BUFF_SIZE];
	t_list *list;
	int ret;
	char *tmp;

	line = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (NULL);
		buf[ret] = '\0';
		ft_lstaddback(&list, ft_lstnew(buf, ret + 1));
		if (ft_strchr(buf, '\n'))
			break ;
	}
	tmp = ft_list_to_str(list);
	line = ft_strnew(ft_strchr(tmp, '\n') - tmp);
	line = ft_strdup()
}*/