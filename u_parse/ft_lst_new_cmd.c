/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_new_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:01:35 by fgacougn          #+#    #+#             */
/*   Updated: 2024/03/04 14:13:22 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lst_new_cmd(void)
{
	s()->u.current = malloc(sizeof(t_cmd));
	if (!s()->u.current)
		return (ERR_MALLOC);
	ft_bzero(s()->u.current, sizeof(t_cmd));
	return (SUCCESS);
}