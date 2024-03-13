/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uparse_setup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:32:24 by fgacougn          #+#    #+#             */
/*   Updated: 2024/03/13 10:32:31 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_uparse_setup(void)
{
	s()->u.f_parse[0] = &ft_cmd;
	s()->u.f_parse[1] = &ft_less;
	s()->u.f_parse[2] = &ft_more;
	s()->u.f_parse[3] = &ft_pipe;
	s()->u.f_parse[4] = &ft_openpar;
	s()->u.f_parse[5] = &ft_closepar;
	s()->u.f_parse[6] = &ft_and;
	s()->u.f_parse[7] = &ft_semicol;
	return (SUCCESS);
}