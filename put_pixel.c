/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 11:27:11 by adesgran          #+#    #+#             */
/*   Updated: 2021/12/26 13:22:57 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	put_pixel(t_data *img, int x, int y, ...)
{
	va_list	args;
	char	*dst;
	
	va_start(args, y);
	if (x < 0 || y < 0)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = va_arg(args, unsigned int);
	if (!*dst)
		*(unsigned int *)dst = 0x00000000;
}
