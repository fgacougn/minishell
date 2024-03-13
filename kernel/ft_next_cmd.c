/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:13:03 by fgacougn          #+#    #+#             */
/*   Updated: 2024/03/13 12:14:58 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_next_cmd(void)
{
	if (s()->u.current->dep)
	{
		s()->u.current = s()->u.current->dep;
		return (SUCCESS);
	}
	if (s()->u.current->next)
	{
		s()->u.current = s()->u.current->next;
		return (SUCCESS);
	}
	if (s()->u.current->from)
	{
		s()->u.current = s()->u.current->from;
		return (SUCCESS);
	}
	s()->u.current = 0;
	return (SUCCESS);
}