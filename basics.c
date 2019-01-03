/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mguerrea <mguerrea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 17:58:37 by mguerrea          #+#    #+#             */
/*   Updated: 2019/01/03 18:02:06 by mguerrea         ###   ########.fr       */
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