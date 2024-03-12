/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_startwith.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 12:47:36 by fgacougn          #+#    #+#             */
/*   Updated: 2023/12/08 18:33:30 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_startwith(char *insearch, char *tosearch)
{
	int	i;

	if (!tosearch || !insearch)
		return (ERR_NUL_STR);
	i = 0;
	while (insearch[i] == tosearch[i] && insearch)
		i++;
	if (tosearch[i])
		return (FAILURE);
	return (SUCCESS);
}
