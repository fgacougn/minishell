/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_semicol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:39:02 by fgacougn          #+#    #+#             */
/*   Updated: 2024/03/05 16:34:30 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_semicol(void)
{
	if (ft_lst_new_cmd() != SUCCESS)
		return (ERR_MALLOC);
	s()->u.last->next = s()->u.current;
	s()->u.last = s()->u.last->next;
	(s()->u.p_parse)++;
	return (SUCCESS);
}