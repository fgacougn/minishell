/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_more.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:33:41 by fgacougn          #+#    #+#             */
/*   Updated: 2024/03/05 16:40:31 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_more(void)
{
	s()->u.p_parse++;
	if (*(s()->u.p_parse) == '>')
	{
		s()->u.i = O_APPEND;
		s()->u.p_parse++;
	}
	else
		s()->u.i = O_TRUNC;
	if (s()->u.current->isoutfile)
	{
		if (s()->u.current->str_outfile)
			free(s()->u.current->str_outfile);
		close(s()->u.current->fd_outfile);
	}
	printf("P %p %p \n", s()->u.start, s()->u.p_parse);
	ft_get_endarg();
	printf("P2 %p %p  %s\n", s()->u.start, s()->u.p_parse, s()->u.p_parse);
	if (s()->u.start != s()->u.p_parse)
	{
		s()->u.current->isoutfile = 1;
		s()->u.current->str_outfile = ft_strndup(s()->u.p_parse, s()->u.start
				- s()->u.p_parse);
		if (s()->u.current->str_outfile == 0)
			return (ERR_MALLOC);
		if (ft_is_in(DEVIDERS, s()->u.current->str_outfile[s()->u.start
				- s()->u.p_parse]) != -1)
			s()->u.current->str_outfile[s()->u.start - s()->u.p_parse] = 0;
		printf("outfile %s\n", s()->u.current->str_outfile);
		s()->u.current->fd_outfile = open(s()->u.current->str_outfile,
				O_WRONLY | O_CREAT | s()->u.i, 0644);
	}
	s()->u.p_parse = s()->u.start;
	return (SUCCESS);
}