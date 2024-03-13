/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_buildin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:35:17 by fgacougn          #+#    #+#             */
/*   Updated: 2024/03/13 12:16:25 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_get_buildin(void)
{
	if (!s()->u.current)
		return (SUCCESS);
	if (s()->u.current->argv)
	{
		printf("GET BI %s ", s()->u.current->argv[0]);
		if (!ft_strcmp(s()->u.current->argv[0], "echo"))
			s()->u.current->buildin = MS_ECHO;
		else if (!ft_strcmp(s()->u.current->argv[0], "env"))
		{
			s()->u.current->buildin = MS_ENV;
			printf("paf");
		}
		else if (!ft_strcmp(s()->u.current->argv[0], "pwd"))
			s()->u.current->buildin = MS_PWD;
		else if (!ft_strcmp(s()->u.current->argv[0], "export"))
		{
			s()->u.current->buildin = MS_EXPORT;
			printf("? %d ", MS_EXPORT);
		}
		else if (!ft_strcmp(s()->u.current->argv[0], "unset"))
			s()->u.current->buildin = MS_UNSET;
		else if (!ft_strcmp(s()->u.current->argv[0], "exit"))
			s()->u.current->buildin = MS_EXIT;
		else if (!ft_strcmp(s()->u.current->argv[0], "cd"))
			s()->u.current->buildin = MS_CD;
		else
			s()->u.current->buildin = MS_NOBI;
		printf("BUILDIN %d\n", s()->u.current->buildin);
	}
	ft_next_cmd();
	return (ft_get_buildin());
}