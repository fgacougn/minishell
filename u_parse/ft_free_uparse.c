/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_uparse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:39:54 by fgacougn          #+#    #+#             */
/*   Updated: 2024/03/05 14:42:37 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_free_uparse(void)
{
	if (s()->u.line)
		free(s()->u.line);
	if (s()->u.first)
		ft_lst_flush_cmd();
	return (SUCCESS);
}