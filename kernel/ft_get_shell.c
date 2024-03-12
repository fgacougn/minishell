/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_shell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:14:02 by fgacougn          #+#    #+#             */
/*   Updated: 2024/01/31 11:34:15 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell *ft_get_shell()
{
	static t_minishell minishell;
	
	return (&minishell);
}

t_minishell *s()
{
	return (ft_get_shell());
}