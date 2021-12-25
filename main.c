/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:04:25 by adesgran          #+#    #+#             */
/*   Updated: 2021/12/25 14:02:48 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static	t_coord	new_coord(float x, float y)
{
	t_coord res;

	res.x = x;
	res.y = y;
	return (res);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	*img;

	mlx = mlx_init();
	mlx_win = NULL;
	img = window_init(mlx, &mlx_win);
	printf("cos(pi) : %f\n", cos(M_PI));
	printf("Adresses:\n -mlx : %p\n -win : %p\n -img : %p\n", mlx, mlx_win, img->addr);

	put_line(img, new_coord(0, 0), new_coord(W_WIDTH, W_HEIGHT));
	put_line(img, new_coord(W_WIDTH, 0), new_coord(0, W_HEIGHT));
	put_line(img, new_coord(400, 30), new_coord(200, 200));
	put_line(img, new_coord(200, 100), new_coord(100, 100));
	put_line(img, new_coord(200, 200), new_coord(200, 300));
	mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
	mlx_loop(mlx);
	(void)mlx_win;
	ft_printf("HERE\n");
	return (0);
}
