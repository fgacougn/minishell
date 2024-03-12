/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 16:43:12 by fgacougn          #+#    #+#             */
/*   Updated: 2024/03/05 17:31:34 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_here_doc(void)
{
	ft_closeinfile();
	ft_get_endarg();
	s()->u.current->heredoc = 1;
	if (s()->u.current->limiter)
		free(s()->u.current->limiter);
	s()->u.current->limiter = 0;
	if (s()->u.start != s()->u.p_parse)
	{
		s()->u.current->limiter = ft_strndup(s()->u.p_parse, s()->u.start
				- s()->u.p_parse - 1);
		if (s()->u.current->limiter == 0)
			return (ERR_MALLOC);
		printf("limiter /%s/\n", s()->u.current->limiter);
		ft_read_hdoc();
	}
	return (SUCCESS);
}