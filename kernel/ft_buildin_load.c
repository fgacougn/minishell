/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildin_load.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 16:06:47 by fgacougn          #+#    #+#             */
/*   Updated: 2024/03/08 18:00:15 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_buildin_load(void)
{
	printf("pop\n");
	s()->e.f_buildin[MS_ECHO] = &ft_echo;
	s()->e.f_buildin[MS_PWD] = &ft_pwd;
	s()->e.f_buildin[MS_EXPORT] = &ft_export;
	s()->e.f_buildin[MS_UNSET] = &ft_unset;
	s()->e.f_buildin[MS_ENV] = &ft_env;
	s()->e.f_buildin[MS_EXIT] = &ft_exit;
	s()->e.f_buildin[MS_CD] = &ft_cd;
	s()->e.buildin = MS_NOBI;
	return (SUCCESS);
}