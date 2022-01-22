/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 14:24:59 by adesgran          #+#    #+#             */
/*   Updated: 2022/01/22 14:08:32 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_3dcoord	projection_2d(t_vars *vars, t_3dcoord p, float ratio)
{
	t_3dcoord	res;

	res.x = (p.x * ratio) + W_WIDTH / 2;
	res.y = (p.y * ratio) + W_HEIGHT / 2;
	(void)vars;
	res.z = p.z;
	res.color = p.color;
	return (res);
}

void	rotate_x(t_3dcoord *p, float angle)
{
	t_3dcoord	res;
	float		cosa;
	float		sina;

	cosa = cos(angle);
	sina = sin(angle);
	res.y = (p->y * cosa) - (p->z * sina);
	res.z = (p->y * sina) + (p->z * cosa);
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
	res.x = (p->x * cosa) + (p->z * sina);
	res.z = (-1 * p->x * sina) + (p->z * cosa);
	p->x = res.x;
	p->z = res.z;
}

void	rotate_z(t_3dcoord *p, float angle)
{
	t_3dcoord	res;
	float		cosa;
	float		sina;

	cosa = cos(angle);
	sina = sin(angle);
	res.x = (p->x * cosa) - (p->y * sina);
	res.y = (p->x * sina) + (p->y * cosa);
	p->x = res.x;
	p->y = res.y;
}
