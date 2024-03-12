/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_isbin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:07:54 by fgacougn          #+#    #+#             */
/*   Updated: 2024/03/08 16:44:08 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exec_isbin(void)
{
	if (!s()->e.argv || !s()->e.argv[0])
		return (ERR_BAD_PNTR);
	if (s()->e.binpath)
		s()->e.temp1 = ft_strbuild(s()->e.binpath, "/", s()->e.argv[0], 0);
	else
		s()->e.temp1 = ft_strdup(s()->e.argv[0]);
	if (!s()->e.temp1)
		return (ERR_MALLOC);
	// printf("test %s\n", s()->e.temp1);
	if (access(s()->e.temp1, F_OK) == -1)
	{
		free(s()->e.temp1);
		s()->e.temp1 = 0;
		return (ERR_BAD_ARGS);
	}
	if (access(s()->e.temp1, X_OK) == -1)
	{
		free(s()->e.temp1);
		s()->e.temp1 = 0;
		return (ERR_BAD_FILE);
	}
	return (SUCCESS);
}