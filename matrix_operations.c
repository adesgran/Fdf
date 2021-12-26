/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 14:24:59 by adesgran          #+#    #+#             */
/*   Updated: 2021/12/26 14:53:35 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_coord	projection_2d(t_vars *vars, t_3dcoord p, float ratio)
{
	t_coord	res;

	res.x = p.x * ratio + 0.5 * (W_WIDTH - (cos(vars->img->y_ang) * ratio * ((float)vars->col - 1)));
	res.y = p.y * ratio + 0.5 * (W_HEIGHT - (cos(vars->img->x_ang) * ratio * ((float)vars->row - 1)));
	return (res);
}

void	rotate_x(t_3dcoord *p, float angle)
{
	t_3dcoord	res;
	float		cosa;
	float		sina;

	cosa = cos(angle);
	sina = sin(angle);
	res.x = p->x;
	res.y = p->y * cosa - p->z * sina;
	res.z = p->y * sina + p->z * cosa;

	p->x = res.x;
	p->y = res.y;
	p->z = res.z;
}

void	rotate_y(t_3dcoord *p, float angle)
{
	t_3dcoord	res;
	float		cosa;
	float		sina;

	cosa = cos(angle);
	sina = sin(angle);
	res.x = p->x * cosa + p->z * sina;
	res.y = p->y;
	res.z = -1 * p->x * sina + p->z * cosa;

	p->x = res.x;
	p->y = res.y;
	p->z = res.z;
}

void	rotate_z(t_3dcoord *p, float angle)
{
	t_3dcoord	res;
	float		cosa;
	float		sina;

	cosa = cos(angle);
	sina = sin(angle);
	res.x =	p->x * cosa - p->y * sina;
	res.y = p->x * sina + p->y * cosa;
	res.z = p->z;

	p->x = res.x;
	p->y = res.y;
	p->z = res.z;
}
