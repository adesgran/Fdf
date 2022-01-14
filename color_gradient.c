/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_gradient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 22:22:57 by adesgran          #+#    #+#             */
/*   Updated: 2022/01/14 11:05:24 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static unsigned int	gradient_r(int i, int s, unsigned int c1, unsigned int c2)
{
	unsigned int	r1;
	unsigned int	r2;
	unsigned int	res;

	r1 = (c1 / (unsigned int)pow(16, 4)) % (unsigned int)pow(16, 2);
	r2 = (c2 / (unsigned int)pow(16, 4)) % (unsigned int)pow(16, 2);
	if (r1 > r2)
		res = r1 - i * ((r1 - r2) / s);
	else if (r1 < r2)
		res = r2 - i * ((r2 - r1) / s);
	else
		return (r1);
	return (res);
}

static unsigned int	gradient_g(int i, int s, unsigned int c1, unsigned int c2)
{
	unsigned int	g1;
	unsigned int	g2;
	unsigned int	res;

	g1 = (c1 / (unsigned int)pow(16, 2)) % (unsigned int)pow(16, 2);
	g2 = (c2 / (unsigned int)pow(16, 2)) % (unsigned int)pow(16, 2);
	if (g1 > g2)
		res = g1 - i * ((g1 - g2) / s);
	else if (g1 < g2)
		res = g2 - i * ((g2 - g1) / s);
	else
		return (g1);
	return (res);
}

static unsigned int	gradient_b(int i, int s, unsigned int c1, unsigned int c2)
{
	unsigned int	b1;
	unsigned int	b2;
	unsigned int	res;

	b1 = (c1 / (unsigned int)pow(16, 0)) % (unsigned int)pow(16, 2);
	b2 = (c2 / (unsigned int)pow(16, 0)) % (unsigned int)pow(16, 2);
	if (b1 > b2)
		res = b1 - i * ((b1 - b2) / s);
	else if (b1 < b2)
		res = b2 - i * ((b2 - b1) / s);
	else
		return (b1);
	return (res);
}

unsigned int	color_gradient(int i, int s, unsigned int c1, unsigned int c2)
{
	unsigned int	res;

	res = gradient_b(i, s, c1, c2);
	res += gradient_g(i, s, c1, c2) * (unsigned int)pow(16, 2);
	res += gradient_r(i, s, c1, c2) * (unsigned int)pow(16, 4);
	return (res);
}
