/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_flush_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:31:06 by fgacougn          #+#    #+#             */
/*   Updated: 2024/03/04 17:47:49 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lst_flush_cmd(void)
{
	s()->u.current = s()->u.first;
	while (s()->u.current)
	{
		if (s()->u.current->dep == 0)
		{
			s()->u.first = s()->u.current->next;
			s()->u.tofree = s()->u.current;
			ft_lst_free_cmd();
			free(s()->u.tofree);
			s()->u.current = s()->u.first;
		}
		else
		{
			s()->u.tofree = s()->u.current;
			while (s()->u.tofree->dep || s()->u.tofree->next)
			{
				while (s()->u.tofree->dep)
					s()->u.tofree = s()->u.tofree->dep;
				while (s()->u.tofree->next)
					s()->u.tofree = s()->u.tofree->next;
			}
			ft_lst_free_cmd();
			free(s()->u.tofree);
		}
	}
	return (SUCCESS);
}