/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 18:04:10 by adesgran          #+#    #+#             */
/*   Updated: 2021/12/26 19:30:09 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static unsigned int	read_letter(char c)
{
	if (c >= '0' && c <= '9')
		return ((unsigned int)(c - '0'));
	if (c >= 'a' && c <= 'f')
		return ((unsigned int)(c - 'a' + 10));
	if (c >= 'A' && c <= 'F')
		return ((unsigned int)(c - 'A' + 10));
	return (0);
}

unsigned int	ft_atoi_hex(char *s)
{
	unsigned int	res;

	if (!s)
		return (0);
	if (s[0] == '0' && s[1] == 'x')
		s += 2;
	res = 0;
	while (ft_isalnum(*s) && *s)
	{
		res *= 16;
		res += read_letter(*s);
		s++;
	}
	return (res);
}
