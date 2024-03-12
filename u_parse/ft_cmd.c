/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:32:22 by fgacougn          #+#    #+#             */
/*   Updated: 2024/03/05 15:00:51 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_cmd(void)
{
	ft_cpt_words();
	printf("cpt = %d, %s\n", s()->u.cpt_words, s()->u.p_parse);
	s()->u.current->argv = malloc((s()->u.cpt_words + 1) * sizeof(char *));
	if (!s()->u.current->argv)
		return (ERR_MALLOC);
	ft_bzero(s()->u.current->argv, (s()->u.cpt_words + 1) * sizeof(char *));
	s()->u.i_words = 0;
	while (s()->u.i_words < s()->u.cpt_words)
	{
		ft_get_endarg();
		s()->u.current->argv[s()->u.i_words] = malloc(s()->u.start
				- s()->u.p_parse + 1);
		ft_bzero(s()->u.current->argv[s()->u.i_words], s()->u.start
			- s()->u.p_parse + 1);
		if (!s()->u.current->argv[s()->u.i_words])
			return (ERR_MALLOC);
		s()->u.i = 0;
		while (*(s()->u.p_parse) && ft_is_in(WHITESPACES, *(s()->u.p_parse)) ==
			-1 && ft_is_in(DEVIDERS, *(s()->u.p_parse)) == -1)
		{
			printf("test %d %p\n", s()->u.i,
				s()->u.current->argv[s()->u.i_words]);
			s()->u.current->argv[s()->u.i_words][(s()->u.i)++] = *(s()->u.p_parse);
			if (*(s()->u.p_parse) == '"')
			{
				while (*(s()->u.p_parse) && *(++(s()->u.p_parse)) != '"')
					s()->u.current->argv[s()->u.i_words][(s()->u.i)++] = *(s()->u.p_parse);
				s()->u.current->argv[s()->u.i_words][(s()->u.i)++] = *(s()->u.p_parse);
			}
			if (*(s()->u.p_parse) && *(s()->u.p_parse) == '\'')
			{
				while (*(s()->u.p_parse) && *(++(s()->u.p_parse)) != '\'')
					s()->u.current->argv[s()->u.i_words][(s()->u.i)++] = *(s()->u.p_parse);
				s()->u.current->argv[s()->u.i_words][(s()->u.i)++] = *(s()->u.p_parse);
			}
			(s()->u.p_parse)++;
		}
		s()->u.i_words++;
	}
	return (SUCCESS);
}