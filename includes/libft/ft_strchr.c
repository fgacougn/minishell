/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgacougn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 13:08:19 by fgacougn          #+#    #+#             */
/*   Updated: 2023/11/06 13:08:23 by fgacougn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	c %= 256;
	while (*s && *s != c)
		s++;
	if (!*s && c != 0)
		return (0);
	return ((char *)s);
}