/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 17:58:37 by mguerrea          #+#    #+#             */
/*   Updated: 2019/01/03 20:11:57 by mguerrea         ###   ########.fr       */
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
	if (!(newtab = (char **)malloc(sizeof(char *) * (size + 2))))
		return (NULL);
	while (tab[i])
	{
		if (!(newtab[i] = ft_strdup(tab[i])))
			return (NULL);
		free(tab[i]);
		i++;
	}
	if (!(newtab[i] = ft_strdup(str)))
		return (NULL);
	newtab[i + 1] = NULL;
	free(tab);
	return (newtab);
}

void	ft_delentry(char ***tab, int pos)
{
	free((*tab)[pos]);
	while ((*tab)[pos + 1])
	{
		(*tab)[pos] = (*tab)[pos + 1];
		pos++;
	}
	(*tab)[pos] = NULL;
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