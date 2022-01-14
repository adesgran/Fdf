/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 13:06:22 by adesgran          #+#    #+#             */
/*   Updated: 2022/01/14 11:30:33 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_data	*window_init(void *mlx, void **mlx_win)
{
	t_data	*img;

	*mlx_win = mlx_new_window(mlx, W_WIDTH, W_HEIGHT, "Fdf");
	img = malloc(sizeof(t_data));
	img->img = mlx_new_image(mlx, W_WIDTH, W_HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, \
		&img->line_length, &img->endian);
	img->x_ang = M_PI / 9;
	img->y_ang = -M_PI / 9;
	img->z_ang = 0;
	img->zoom = 1;
	return (img);
}
