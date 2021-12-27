/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 11:45:00 by adesgran          #+#    #+#             */
/*   Updated: 2021/12/27 19:45:03 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static unsigned int	get_color(int index, int size, unsigned int color1, unsigned int color2)
{
	unsigned int	res;

	if (color1 == color2 || size == 0)
		return (color1);
	res = color_gradient(index, size, color1, color2);
	return (res);
}

static void	put_x(t_3dcoord start, t_3dcoord end, t_node **tab)
{
	t_3dcoord		curr;
	float			len;
	float			sign;
	float			coeff;
	float			origin;

	sign = 1;
	curr.x = start.x;
	if (end.x == start.x)
		coeff = 2000000000;
	else
		coeff = (end.y - start.y) / (end.x - start.x);
	origin = start.y - coeff * start.x;
	if (start.x > end.x)
		sign = -1;
	len = sign * (end.x - start.x);
	while (curr.x - end.x >= 0.5 || curr.x - end.x < -0.5)
	{
		curr.y = origin + coeff * curr.x;
		curr.z = start.z + sign * (curr.x * start.z / start.x);
		curr.color = get_color(abs((int)curr.x - (int)start.x), (int)len, start.color, end.color);
		add_pixel(tab, curr);
		curr.x += sign;
	}
}

static void	put_y(t_3dcoord start, t_3dcoord end, t_node **tab)
{
	t_3dcoord		curr;
	float			len;
	float			sign;
	float			coeff;
	float			origin;

	sign = 1;
	curr.y = start.y;
	if (end.x == start.x)
		coeff = 2000000000;
	else
		coeff = (end.y - start.y) / (end.x - start.x);
	origin = start.y - coeff * start.x;
	if (start.y > end.y)
		sign = -1;
	len = sign * (end.y - start.y);
	while (curr.y - end.y >= 0.5 || curr.y - end.y < -0.5)
	{
		curr.x = (curr.y - origin) / coeff;
		curr.z = start.z + sign * (curr.y * start.z / start.y);
		curr.color = get_color(abs((int)curr.y - (int)start.y), (int)len, start.color, end.color);
		add_pixel(tab, curr);
		curr.y += sign;
	}
}

void	add_line(t_node **tab, t_3dcoord start, t_3dcoord end)
{
	float	coeff;

	if (end.x == start.x)
		coeff = 2000000000;
	else
		coeff = (end.y - start.y) / (end.x - start.x);
	if (coeff <= 1 && coeff >= -1)
		put_x(start, end, tab);
	else
		put_y(start, end, tab);
	if (end.x == start.x && end.y == start.y)
	{
		if (tab[(int)start.y][(int)start.x].z < start.z)
		{
			tab[(int)start.y][(int)start.x].z = start.z;
			tab[(int)start.y][(int)start.x].color = start.color;
		}
	}
}
