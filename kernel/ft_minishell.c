/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:40:44 by fgacougn          #+#    #+#             */
/*   Updated: 2024/03/12 10:46:12 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_minishell(void)
{
	printf("%s\n", ft_get_shell()->argv[0]);
	// ft_buildin_load();
	s()->tabenv = ft_get_envp(s()->env);
	s()->e.pwd = s()->tabenv[ENVP_PWD];
	s()->e.env = ft_splitcpy(s()->env);
	if (s()->tabenv)
		while (!s()->e.exit)
		{
			// s()->e.line = get_next_line(1);
			s()->e.line = readline(MINIPROMPT);
			if (s()->e.line)
			{
				if (ft_strlen(s()->e.line) > 0)
					ft_parsing();
				ft_uparsing();
				ft_lst_print_cmd(s()->u.first);
				ft_printf_split(s()->u.current->argv);
				if (ft_strlen(s()->e.line) > 0)
				{
					ft_varparse();
					if (s()->e.buildin != MS_NOBI)
						// ft_buildin();
						s()->e.f_buildin[s()->e.buildin]();
					// ft_printf_split(s()->e.argv);
					ft_free_split(s()->e.argv);
				}
			}
			// printf("%s %d %d\n", s()->e.line, s()->ret, s()->e.buildin);
			if (s()->e.line)
				free(s()->e.line);
		}
	ft_free_shell();
}
