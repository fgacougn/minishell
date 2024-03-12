/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:40:12 by fgacougn          #+#    #+#             */
/*   Updated: 2024/01/31 15:50:39 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_printf_split(char **split)
{
	if (!split)
	 return ;
	while (*split)
	{
		ft_printf("%s \n", *split);
		split++;
	}
}