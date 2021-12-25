/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 14:03:34 by adesgran          #+#    #+#             */
/*   Updated: 2021/12/25 14:16:11 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

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
