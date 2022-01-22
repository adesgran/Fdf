/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_application.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 18:02:31 by adesgran          #+#    #+#             */
/*   Updated: 2022/01/22 14:44:17 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static int	tab_size(t_3dcoord **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

static t_3dcoord	*trans_mat(t_vars *vars, t_3dcoord *coord, int len, int amp)
{
	int			i;
	float		zoom;
	t_3dcoord	*res;
	t_3dcoord	temp;

	res = malloc(sizeof(t_3dcoord) * len);
	if (!res)
		return (res);
	i = 0;
	zoom = vars->img->zoom;
	while (i < len)
	{
		temp.x = coord[i].x - ((float)vars->col / 2);
		temp.y = coord[i].y - ((float)vars->row / 2);
		temp.z = coord[i].z * len / (10 * amp);
		temp.color = coord[i].color;
		rotate_x(&temp, vars->img->x_ang);
		rotate_y(&temp, vars->img->y_ang);
		rotate_z(&temp, vars->img->z_ang);
		res[i] = projection_2d(vars, temp, zoom * W_HEIGHT / (len * 1.2));
		i++;
	}
	return (res);
}

static int	get_ampl(t_3dcoord **tab, int size)
{
	int	max;
	int	min;
	int	i;

	max = tab[0]->z;
	min = max;
	while (*tab)
	{
		i = 0;
		while (i < size)
		{
			if (tab[0][i].z > max)
				max = tab[0][i].z;
			if (tab[0][i].z < min)
				min = tab[0][i].z;
			i++;
		}
		tab++;
	}
	if (max == min)
		return (1);
	return (max - min);
}

t_3dcoord	**matrix_application(t_vars *vars, t_3dcoord **tab, int size)
{
	int			i;
	int			amplitude;
	t_3dcoord	**res;
	t_3dcoord	*temp;
	int			height;

	height = tab_size(tab);
	if (tab_size(tab) < 1)
		return (NULL);
	res = malloc(sizeof(t_3dcoord *) * (height + 1));
	if (!res)
		return (NULL);
	amplitude = get_ampl(tab, size);
	i = 0;
	while (tab[i])
	{
		temp = tab[i];
		res[i] = trans_mat(vars, temp, size, amplitude);
		if (!res[i])
			return (NULL);
		i++;
	}
	res[i] = NULL;
	return (res);
}
