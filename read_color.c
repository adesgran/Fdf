/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 18:34:11 by adesgran          #+#    #+#             */
/*   Updated: 2021/12/29 16:28:13 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

unsigned int	set_default_color(int z)
{
	if (abs(z) == 0)
		return (0x0055FF00);
	if (abs(z) == 1)
		return (0x0066EE00);
	if (abs(z) == 2)
		return (0x0077DD00);
	if (abs(z) == 3)
		return (0x0088CC00);
	if (abs(z) == 4)
		return (0x0099BB00);
	if (abs(z) == 5)
		return (0x00AAAA00);
	if (abs(z) == 6)
		return (0x00BB9900);
	if (abs(z) == 7)
		return (0x00CC8800);
	if (abs(z) == 8)
		return (0x00DD7700);
	if (abs(z) == 9)
		return (0x00EE6600);
	if (abs(z) >= 10)
		return (0x00FF5500);
	return (0);
}

