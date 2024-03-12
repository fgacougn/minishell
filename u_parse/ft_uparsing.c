/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uparsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:00:17 by fgacougn          #+#    #+#             */
/*   Updated: 2024/03/05 14:55:37 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	setup(void)
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

int	ft_uparsing(void)
{
	setup();
	if (!s()->e.line)
		return (ERR_EMPTY);
	s()->u.p_parse = s()->e.line;
	ft_lst_flush_cmd();
	ft_lst_new_cmd();
	s()->u.first = s()->u.current;
	s()->u.last = s()->u.current;
	while (*(s()->u.p_parse) && *(s()->u.p_parse) == ' ')
		(s()->u.p_parse)++;
	printf("linge /%s/\n", s()->u.p_parse);
	s()->u.line = ft_strdup(s()->u.p_parse);
	s()->u.p_parse = s()->u.line;
	while (*(s()->u.p_parse))
	{
		while (*(s()->u.p_parse) && *(s()->u.p_parse) == ' ')
			(s()->u.p_parse)++;
		s()->u.token = ft_is_in(DEVIDERS, *(s()->u.p_parse));
		s()->u.err = s()->u.f_parse[s()->u.token + 1]();
		if (s()->u.err != SUCCESS)
			return (s()->u.err);
	}
	if (s()->u.line)
	{
		free(s()->u.line);
		s()->u.line = 0;
	}
	return (SUCCESS);
}