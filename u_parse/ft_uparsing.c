/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uparsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:00:17 by fgacougn          #+#    #+#             */
/*   Updated: 2024/03/13 11:37:37 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_uparsing(void)
{
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
		while (ft_is_in(WHITESPACES, *(s()->u.p_parse)) != -1)
			s()->u.p_parse++;
	}
	if (s()->u.line)
	{
		free(s()->u.line);
		s()->u.line = 0;
	}
	s()->u.current = s()->u.first;
	ft_get_buildin();
	return (SUCCESS);
}