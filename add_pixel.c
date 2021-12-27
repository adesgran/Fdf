/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 14:53:52 by adesgran          #+#    #+#             */
/*   Updated: 2021/12/27 15:18:28 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	add_pixel(t_node **tab, t_3dcoord curr)
{
	int	x;
	int	y;

	x = (int)curr.x;
	y = (int)(0.5 + curr.y);
	if (x >= 0 && x < W_WIDTH && y >= 0 && y < W_HEIGHT)
	{
		if (curr.z > tab[x][y].z)
		{
			tab[y][x].z = curr.z;
			tab[y][x].color = curr.color;
		}
	}
}
