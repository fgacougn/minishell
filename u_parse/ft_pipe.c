/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:34:38 by fgacougn          #+#    #+#             */
/*   Updated: 2024/03/05 15:57:03 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pipe(void)
{
	s()->u.current->pipeout = 1;
	if (ft_lst_new_cmd() != SUCCESS)
		return (ERR_MALLOC);
	s()->u.last->next = s()->u.current;
	s()->u.last = s()->u.last->next;
	s()->u.current->pipein = 1;
	(s()->u.p_parse)++;
	return (SUCCESS);
}