/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_shell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <fgacougn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:16:13 by fgacougn          #+#    #+#             */
/*   Updated: 2024/03/08 17:34:17 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_shell(void)
{
	ft_free_parsing();
	rl_clear_history();
	ft_free_exec();
	ft_free_uparse();
	if (s()->tabenv)
		free(s()->tabenv);
}