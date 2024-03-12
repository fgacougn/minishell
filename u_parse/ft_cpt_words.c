/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpt_words.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:52:42 by fgacougn          #+#    #+#             */
/*   Updated: 2024/03/04 16:20:02 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cpt_words(void)
{
	(s()->u.start) = s()->u.p_parse;
	s()->u.start += 1;
	printf("start %s\n", s()->u.start);
	s()->u.cpt_words = 1;
	while (*(s()->u.start) && ft_is_in(DEVIDERS, *(s()->u.start)) == -1)
	{
		if (ft_is_in(WHITESPACES, *(s()->u.start)) == -1
			&& ft_is_in(WHITESPACES, *(s()->u.start - 1)) != -1)
			s()->u.cpt_words++;
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