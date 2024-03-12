/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:03:23 by fgacougn          #+#    #+#             */
/*   Updated: 2024/03/11 11:53:06 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_free_exec(void)
{
	if (s()->e.env)
		ft_free_split(s()->e.env);
	if (s()->e.envp)
		free(s()->e.envp);
	if (s()->e.temp1)
		free(s()->e.temp1);
	if (s()->e.temp2)
		free(s()->e.temp2);
	if (s()->e.temp3)
		free(s()->e.temp3);
	if (s()->e.temp4)
		free(s()->e.temp4);
	if (s()->e.binpath)
		free(s()->e.binpath);
	if (s()->e.argv)
		ft_free_split(s()->e.argv);
	return (SUCCESS);
}