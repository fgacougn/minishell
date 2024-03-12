/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_free_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:33:24 by fgacougn          #+#    #+#             */
/*   Updated: 2024/03/05 17:26:25 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lst_free_cmd(void)
{
	if (s()->u.tofree->argv)
		ft_free_split(s()->u.tofree->argv);
	ft_closeinfile();
	if (s()->u.current->isoutfile)
	{
		if (s()->u.current->str_outfile)
			free(s()->u.current->str_outfile);
		close(s()->u.current->fd_outfile);
	}
	if(s()->u.current->limiter)
		free(s()->u.current->limiter);
	return (SUCCESS);
}