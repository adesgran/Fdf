/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 12:40:56 by adesgran          #+#    #+#             */
/*   Updated: 2021/12/26 14:11:14 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	init_img(t_data *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < W_HEIGHT)
	{
		j = 0;
		while (j < W_WIDTH)
		{
			put_pixel(img, j, i, 0x00000000);
			j++;
		}
		i++;
	}
}

void	put_tab(t_vars *vars, t_coord **tab)
{
	int	i;
	int	j;

	init_img(vars->img);
	j = 0;
	while (j < vars->row)
	{
		i = 0;
		while (i < vars->col)
		{
			if (i != vars->col - 1)
				put_line(vars->img, tab[j][i], tab[j][i + 1]);
			if (j != vars->row - 1)
				put_line(vars->img, tab[j][i], tab[j + 1][i]);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
}

