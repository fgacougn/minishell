/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hach_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:10:52 by fgacougn          #+#    #+#             */
/*   Updated: 2024/02/15 12:16:58 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_hach_find(char *tofind, char **hach_map)
{
	char *st;
	char *temp;
	int i;

	if (!(tofind || !hach_map))
		return (0);
	st = ft_strjoin(tofind, "=");
	if (!st)
		return (0);
	i = 0;
	while (hach_map[i])
	{
		if (ft_strncmp(st, hach_map[i], ft_strlen(st)) == 0)
		{
			temp = ft_strtruetrim(hach_map[i], st);
			free(st);
			return (temp);
		}
		i++;
	}
	free(st);
	return (0);
}