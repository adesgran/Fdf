/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_application.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 18:02:31 by adesgran          #+#    #+#             */
/*   Updated: 2021/12/25 19:35:28 by adesgran         ###   ########.fr       */
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

static t_coord	*transform_matrix(t_3dcoord *coord, int len, int max_height)
{
	int			i;
	t_coord		*res;
	t_3dcoord	temp;

	res = malloc(sizeof(t_coord) * len);
	if (!res)
		return (res);
	i = 0;
	while (i < len)
	{
		temp.x = coord[i].x;
		temp.y = coord[i].y;
		temp.z = coord[i].z * len / (10 * max_height);
		rotate_x(&temp, M_PI / 3);
		rotate_y(&temp, -M_PI / 13);
		rotate_z(&temp, 0);
		res[i] = projection_2d(temp, W_HEIGHT / (len * 1.2));
		i++;
	}
	(void)max_height;
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

t_coord	**matrix_application(t_3dcoord **tab, int size)
{
	int			i;
	int			max_height;
	t_coord		**res;
	t_3dcoord	*temp;

	ft_printf("Tab_size : %d\n", tab_size(tab));
	if (tab_size(tab) < 1)
		return (NULL);
	res = malloc(sizeof(t_coord *) * (tab_size(tab) + 1));
	if (!res)
		return (NULL);
	max_height = get_max_height(tab, size);
	i = 0;
	while (*tab)
	{
		temp = *tab;
		res[i] = transform_matrix(temp, size, max_height);
		if (!res[i])
			return (NULL);
		tab++;
		i++;
	}
	return (res);
}
