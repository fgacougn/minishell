/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_printe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:12:47 by fgacougn          #+#    #+#             */
/*   Updated: 2024/03/11 11:10:04 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_export_printe(void)
{
	s()->e.temp1 = ft_strbuild("\033[1;31mMinishell: export: `",
			*s()->e.exec_argv, "': not a valid identifier\033[0m\n", 0);
	if (!s()->e.temp1)
		return (ERR_MALLOC);
	ft_puterror(s()->e.temp1);
	free(s()->e.temp1);
	s()->e.temp1 = 0;
	return (ERR_BAD_ARGS);
}

int	ft_acess_printe(void)
{
	s()->e.temp1 = ft_strbuild("\033[1;31mMinishell: ",
			*s()->e.argv, ": command not found\033[0m\n", 0);
	if (!s()->e.temp1)
		return (ERR_MALLOC);
	ft_puterror(s()->e.temp1);
	free(s()->e.temp1);
	s()->e.temp1 = 0;
	return (ERR_BAD_ARGS);
}

int ft_exec_printe()
{
	s()->e.temp1 = ft_strbuild("\033[1;31mMinishell: ",
			*s()->e.argv, ": Permission denied\033[0m\n", 0);
	if (!s()->e.temp1)
		return (ERR_MALLOC);
	ft_puterror(s()->e.temp1);
	free(s()->e.temp1);
	s()->e.temp1 = 0;
	return (ERR_BAD_ARGS);
}