/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_closeinfile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 17:00:29 by fgacougn          #+#    #+#             */
/*   Updated: 2024/03/05 17:18:47 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_closeinfile(void)
{
	if (s()->u.current->isinfile)
	{
		if (s()->u.current->str_infile)
			free(s()->u.current->str_infile);
		if (s()->u.current->fd_infile > -1)
			close(s()->u.current->fd_infile);
		s()->u.current->isinfile = 0;
	}
	return (SUCCESS);
}