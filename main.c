/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:04:25 by adesgran          #+#    #+#             */
/*   Updated: 2021/12/25 19:29:15 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

/*static	t_3dcoord	new_3dcoord(float x, float y, float z)
{
	t_3dcoord res;

	res.x = x;
	res.y = y;
	res.z = z;
	return (res);
}

static	t_coord	new_coord(float x, float y)
{
	t_coord res;

	res.x = x;
	res.y = y;
	return (res);
}*/

int	main(int ac, char **av)
{
	void	*mlx;
	void	*mlx_win;
	t_data	*img;
	mlx = mlx_init();
	mlx_win = NULL;
	img = window_init(mlx, &mlx_win)
	;
	int row, col;
	if (ac == 1)
		return (1);
	t_list *res = read_input(av[1], &row, &col);
	t_3dcoord **res_bis = get_3dcoord_tab(res, col);
	t_coord **proj = matrix_application(res_bis, col);
	ft_printf("col : %d row : %d\n",col, row);
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			if (i != col - 1)
				put_line(img, proj[j][i], proj[j][i + 1]);
			if (j != row - 1)
				put_line(img, proj[j][i], proj[j + 1][i]);
		}
	}
	printf("END\n");
	mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
	mlx_loop(mlx);
	(void)mlx_win;
	ft_printf("HERE\n");
	
	return (0);
}
