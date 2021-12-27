/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_application.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 18:02:31 by adesgran          #+#    #+#             */
/*   Updated: 2021/12/27 16:05:29 by adesgran         ###   ########.fr       */
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

static t_3dcoord	*transform_matrix(t_vars *vars, t_3dcoord *coord, int len, int max_height)
{
	int			i;
	t_3dcoord	*res;
	t_3dcoord	temp;

	res = malloc(sizeof(t_3dcoord) * len);
	if (!res)
		return (res);
	i = 0;
	while (i < len)
	{
		temp.x = coord[i].x;
		temp.y = coord[i].y;
		temp.z = coord[i].z * len / (10 * max_height);
		temp.color = coord[i].color;
		rotate_x(&temp, vars->img->x_ang);
		rotate_y(&temp, vars->img->y_ang);
		rotate_z(&temp, vars->img->z_ang);
		res[i] = projection_2d(vars, temp,  vars->img->zoom * W_HEIGHT / (len * 1.2));
		i++;
	}
	return (res);
}
	
static int	get_max_height(t_3dcoord **tab, int size)
{
	int	res;
	int	i;

	res = tab[0]->z;
	while (*tab)
	{
		i = 0;
		while (i < size)
		{
			if (tab[0][i].z > res)
				res = tab[0][i].z;
			i++;
		}
		tab++;
	}
	return (res);
}

t_3dcoord	**matrix_application(t_vars *vars, t_3dcoord **tab, int size)
{
	int			i;
	int			max_height;
	t_3dcoord	**res;
	t_3dcoord	*temp;
	int			height;


	height = tab_size(tab);
	if (tab_size(tab) < 1)
		return (NULL);
	res = malloc(sizeof(t_3dcoord *) * (height + 1));
	if (!res)
		return (NULL);
	max_height = get_max_height(tab, size);
	i = 0;
	while (tab[i])
	{
		temp = tab[i];
		res[i] = transform_matrix(vars, temp, size, max_height);
		if (!res[i])
			return (NULL);
		i++;
	}
	res[i] = NULL;
	return (res);
}
