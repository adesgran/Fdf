/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 11:45:00 by adesgran          #+#    #+#             */
/*   Updated: 2021/12/25 12:53:42 by adesgran         ###   ########.fr       */
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

void	put_line(t_data *img, t_coord start, t_coord end)
{
	float	increment;
	float	coeff;
	float	origin;
	float	x;
	float	y;

	x = start.x;
	y = start.y;
	increment = 1;
	if (start.x > end.x)
		increment = -1;
	coeff = get_coeff(start, end);
	origin = get_origin(start, coeff);
	printf("Line : x1 = %f y1 = %f x2 = %f y2 = %f  Equation : y = %fx + %f\n",start.x, start.y, end.x, end.y, coeff, origin);
	while (x != end.x)
	{
		put_pixel(img, (int)(x), (int)(0.5 + origin + coeff * x));
		x += increment;
	}
	while (y != end.y)
	{
		put_pixel(img, (int)(0.5 + ((y - origin) / coeff)), y);
		if (start.y > end.y)
			y -= 1;
		else
			y += 1;
	}
}
