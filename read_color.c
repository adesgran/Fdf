/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 18:34:11 by adesgran          #+#    #+#             */
/*   Updated: 2021/12/26 23:13:38 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

unsigned int	set_default_color(int z)
{
	if (abs(z) == 0)
		return (0x0000FF00);
	if (abs(z) == 1)
		return (0x0000EE00);
	if (abs(z) == 2)
		return (0x0000DD00);
	if (abs(z) == 3)
		return (0x0000CC00);
	if (abs(z) == 4)
		return (0x0000BB00);
	if (abs(z) == 5)
		return (0x0000AA00);
	if (abs(z) == 6)
		return (0x00009900);
	if (abs(z) == 7)
		return (0x00008800);
	if (abs(z) == 8)
		return (0x00007700);
	if (abs(z) == 9)
		return (0x00006600);
	if (abs(z) >= 10)
		return (0x00005500);
	return (0);
}

