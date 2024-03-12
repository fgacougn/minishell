/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitcpy_plus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:26:02 by fgacougn          #+#    #+#             */
/*   Updated: 2024/01/31 16:29:10 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_splitcpy_plus(char **split, char *stradd)
{
	int i;
	char **ret;

	i = 0;
	ret = split;
	while (ret[i] != 0)
		i++;
	ret = malloc((i + 2) * sizeof(char *));
	if (!ret)
		return (0);
	ft_bzero(ret, (i + 2) * sizeof(char *));
	i--;
	ret[i + 1] = ft_strdup(stradd);
	if (!ret[i + 1])
	{
		free(ret);
		return (0);
	}
	while (i >= 0)
	{
		ret[i] = ft_strdup(split[i]);
		if (!ret[i])
		{
			ft_free_split(ret);
			return (0);
		}
		i--;
	}
	return (ret);
}