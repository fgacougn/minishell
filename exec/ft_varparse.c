/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_varparse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:33:49 by fgacougn          #+#    #+#             */
/*   Updated: 2024/03/11 10:54:45 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// echo "$HOME$HOME" "salut$HOME$HOME" "$HOMEsalut$HOME" "$HOME$HOME,salut"
int	ft_varparse(void)
{
	ft_printf("varparse\n");
	ft_printf_split(s()->e.argv);
	s()->e.exec_argv = s()->e.argv;
	s()->e.ret_val = SUCCESS;
	// printf("1 %s 2 %s 3 %s 4%s\n", s()->e.temp1, s()->e.temp2, s()->e.temp3,
	// 	s()->e.temp4);
	s()->e.ret_val = SUCCESS;
	while (*(s()->e.exec_argv) && s()->e.ret_val == SUCCESS)
	{
		if (ft_varparse_line() != SUCCESS)
			return (ERR_MALLOC);
		s()->e.exec_argv++;
	}
	return (s()->e.ret_val);
}