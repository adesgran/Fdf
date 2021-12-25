/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 13:06:22 by adesgran          #+#    #+#             */
/*   Updated: 2021/12/25 10:57:54 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_data	*window_init(void *mlx, void **mlx_win)
{
	t_data	*img;

	*mlx_win = mlx_new_window(mlx, W_WIDTH, W_HEIGHT, "Fdf");
	img = malloc(sizeof(t_data));
	img->img = mlx_new_image(mlx, W_WIDTH, W_HEIGHT);
	img->addr=mlx_get_data_addr(img->img, &img->bits_per_pixel,\
		&img->line_length, &img->endian);
	return (img);
}
