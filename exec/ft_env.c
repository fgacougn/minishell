/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:59:59 by fgacougn          #+#    #+#             */
/*   Updated: 2024/02/01 12:01:03 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(void)
{
	printf("env\n");
	if (!s()->e.argv)
		return (ERR_BAD_PNTR);
	s()->e.exec_argv = s()->e.argv;
	if (ft_strncmp(*(s()->e.exec_argv), "env", 4))
		return (ERR_BAD_ARGS);
	ft_printf_split(s()->e.env);
	return (SUCCESS);
}