/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 13:54:08 by adesgran          #+#    #+#             */
/*   Updated: 2022/01/22 13:30:09 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	check_values(t_data *img)
{
	if (img->x_ang < -2 * M_PI)
		img->x_ang += 4 * M_PI;
	if (img->y_ang < -2 * M_PI)
		img->y_ang += 4 * M_PI;
	if (img->z_ang < -2 * M_PI)
		img->z_ang += 4 * M_PI;
	if (img->x_ang >= 2 * M_PI)
		img->x_ang -= 4 * M_PI;
	if (img->y_ang >= 2 * M_PI)
		img->y_ang -= 4 * M_PI;
	if (img->z_ang >= 2 * M_PI)
		img->z_ang -= 4 * M_PI;
}

void	print_all(t_vars *vars)
{
	t_3dcoord	**temp;
	t_3dcoord	**proj_tab;

	check_values(vars->img);
	proj_tab = matrix_application(vars, vars->tab, vars->col);
	if (!proj_tab)
		return ;
	put_tab(vars, proj_tab);
	temp = proj_tab;
	while (*temp)
	{
		free(*temp);
		temp++;
	}
	free(proj_tab);
}
