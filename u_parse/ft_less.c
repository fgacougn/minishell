/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_less.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:32:49 by fgacougn          #+#    #+#             */
/*   Updated: 2024/03/13 11:30:36 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_less(void)
{
	s()->u.p_parse++;
	if (*(s()->u.p_parse) == '<')
	{
		s()->u.p_parse++;
		return (ft_here_doc());
	}
	ft_closeinfile();
	printf("P %p %p \n", s()->u.start, s()->u.p_parse);
	ft_get_endarg();
	printf("P2 %p %p  %s\n", s()->u.start, s()->u.p_parse, s()->u.p_parse);
	if (s()->u.start != s()->u.p_parse)
	{
		s()->u.current->isinfile = 1;
		s()->u.current->str_infile = ft_strndup(s()->u.p_parse, s()->u.start
				- s()->u.p_parse - 1);
		if (s()->u.current->str_infile == 0)
			return (ERR_MALLOC);
		printf("infile /%s/\n", s()->u.current->str_infile);
		s()->u.current->fd_infile = open(s()->u.current->str_infile, O_RDONLY);
	}
	s()->u.p_parse = s()->u.start;
	return (SUCCESS);
}