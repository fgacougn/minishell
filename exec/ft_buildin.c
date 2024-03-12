/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 11:47:57 by fgacougn          #+#    #+#             */
/*   Updated: 2024/02/01 11:55:33 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_buildin(void)
{
	if (s()->e.buildin == MS_ECHO)
		ft_echo();
	else if (s()->e.buildin == MS_PWD)
		ft_pwd();
	else if (s()->e.buildin == MS_EXPORT)
		ft_export();
	else if (s()->e.buildin == MS_UNSET)
		ft_unset();
	else if (s()->e.buildin == MS_ENV)
		ft_env();
	else if (s()->e.buildin == MS_EXIT)
		ft_exit();
	else if (s()->e.buildin == MS_CD)
		ft_cd();
	return (SUCCESS);
}