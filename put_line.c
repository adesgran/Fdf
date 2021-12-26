/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 11:45:00 by adesgran          #+#    #+#             */
/*   Updated: 2021/12/26 23:11:59 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static float	get_coeff(t_coord start, t_coord end)
{
	if (end.x == start.x)
		return (2000000000);
	return ((end.y - start.y) / (end.x - start.x));
}

static float	get_origin(t_coord start, float coeff)
{
	return (start.y - coeff * start.x);
}

static unsigned int	get_color(int index, int size, unsigned int color1, unsigned int color2)
{
	unsigned int	res;

	if (color1 == color2 || size == 0)
		return (color1);
	res = color_gradient(index, size, color1, color2);
	return (res);
}

void	put_line(t_data *img, t_coord start, t_coord end)
{
	float	increment;
	float	coeff;
	float	origin;
	float	x;
	float	y;
	unsigned int	color;

	x = start.x;
	y = start.y;
	increment = 1;
	if (start.x > end.x)
		increment = -1;
	coeff = get_coeff(start, end);
	origin = get_origin(start, coeff);
	while ((x - end.x >= 0.5 || x - end.x < -0.5) && (coeff <= 1 && coeff >= -1))
	{
		color = get_color(abs((int)start.x - (int)x), abs((int)start.x - (int)end.x), start.color, end.color);
		put_pixel(img, (int)(x), (int)(0.5 + origin + coeff * x), color);
		x += increment;
	}
	while ((y - end.y >= 0.5 || y - end.y < -0.5) && (coeff > 1 || coeff < -1))
	{
		color = get_color(abs((int)start.y - (int)y), abs((int)start.y - (int)end.y), start.color, end.color);
		put_pixel(img, (int)(0.5 + ((y - origin) / coeff)), y, color);
		if (start.y > end.y)
			y -= 1;
		else
			y += 1;
	}
	if (x == start.x && y == start.y)
		put_pixel(img, (int)x, (int)(0.5 + origin + coeff * x), start.color);
}
