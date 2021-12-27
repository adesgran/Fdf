/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:04:25 by adesgran          #+#    #+#             */
/*   Updated: 2021/12/27 15:45:24 by adesgran         ###   ########.fr       */
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
*/
/*static t_coord	new_coord(float x, float y)
{
	t_coord res;

	res.x = x;
	res.y = y;
	return (res);
}*/

int	get_key(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESCAPE)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		return (0);
	}
	else if(keycode == KEY_UP)
		vars->img->x_ang += M_PI / 40;
	else if(keycode == KEY_DOWN)
		vars->img->x_ang -= M_PI / 40;
	else if(keycode == KEY_LEFT)
		vars->img->y_ang += M_PI / 40;
	else if(keycode == KEY_RIGHT)
		vars->img->y_ang -= M_PI / 40;
	else if(keycode == KEY_ZOOM_IN)
		vars->img->zoom *= 1.2;
	else if(keycode == KEY_ZOOM_OUT)
		vars->img->zoom /= 1.2;
	else if(keycode == KEY_ROT_LEFT)
		vars->img->z_ang += M_PI / 80;
	else if(keycode == KEY_ROT_RIGHT)
		vars->img->z_ang -= M_PI / 80;
	else
	{
		ft_printf("Key : %d\n", keycode);
		return (1);
	}
	print_all(vars);
	return (0);
}

int	close_win(int keycode, t_vars *vars)
{
	(void)keycode;
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}


int	main(int ac, char **av)
{
	void	*mlx;
	void	*mlx_win;
	t_data	*img;
	mlx = mlx_init();
	mlx_win = NULL;
	img = window_init(mlx, &mlx_win);
	int row, col;
	t_list *res = read_input(av[1], &row, &col);
	t_3dcoord **tab = get_3dcoord_tab(res, col);
	t_vars *vars;
	vars = malloc(sizeof(t_vars));
	vars->mlx = mlx;
	vars->img = img;
	vars->win = mlx_win;
	vars->tab = tab;
	vars->col = col;
	vars->row = row;
	print_all(vars);
	mlx_hook(vars->win, 2, 1L<<0, get_key, vars);

	mlx_loop(vars->mlx);
	(void)ac;	
	return (0);
}
