/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:42:41 by fgacougn          #+#    #+#             */
/*   Updated: 2024/03/08 14:30:04 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_export_error(void)
{
	s()->e.temp1 = *s()->e.exec_argv;
	s()->e.temp2 = ft_strchr(s()->e.temp1, '=');
	if (s()->e.temp2 == 0)
	{
		s()->e.temp1 = 0;
		return (ft_export_printe());
	}
	while (ft_is_in(VAR_ESC, *s()->e.temp1) == -1
		&& s()->e.temp1 != s()->e.temp2)
	{
		(s()->e.temp1)+=1;
	}
	if (s()->e.temp1 != s()->e.temp2 && *s()->e.temp1 != '=')
	{
		if (*s()->e.temp1 == '+')
		{
			if (*(s()->e.temp1 + 1) == '=')
			{
				s()->e.temp1 = 0;
				s()->e.temp2 = 0;
				return (ft_export_printe());
			}
		}
		else
		{
			s()->e.temp1 = 0;
			s()->e.temp2 = 0;
			return (ft_export_printe());
		}
	}
	s()->e.temp1 = 0;
	s()->e.temp2 = 0;
	return (SUCCESS);
}