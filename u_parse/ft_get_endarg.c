/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_endarg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:55:25 by fgacougn          #+#    #+#             */
/*   Updated: 2024/03/05 14:26:56 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_get_endarg(void)
{
	while (*(s()->u.p_parse) && ft_is_in(WHITESPACES, *(s()->u.p_parse)) != -1)
	{
		printf("whit\n");
		(s()->u.p_parse)++;
	}
	s()->u.start = s()->u.p_parse;
	while (*(s()->u.start) && ft_is_in(WHITESPACES, *(s()->u.start)) == -1
		&& ft_is_in(DEVIDERS, *(s()->u.start)) == -1)
	{
		if (*(s()->u.start) == '"')
			while (*(s()->u.start) && *(++(s()->u.start)) != '"')
				;
		if (*(s()->u.start) && *(s()->u.start) == '\'')
			while (*(s()->u.start) && *(++(s()->u.start)) != '\'')
				;
		s()->u.start++;
	}
	return (SUCCESS);
}