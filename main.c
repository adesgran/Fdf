/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:04:25 by adesgran          #+#    #+#             */
/*   Updated: 2022/01/22 13:57:00 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	update_win(t_vars *vars)
{
	print_all(vars);
	return (0);
}

int	get_key(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESCAPE)
	{
		free_vars(vars);
		return (0);
	}
	else if (keycode == KEY_UP)
		vars->img->x_ang += M_PI / 40;
	else if (keycode == KEY_DOWN)
		vars->img->x_ang -= M_PI / 40;
	else if (keycode == KEY_LEFT)
		vars->img->y_ang += M_PI / 40;
	else if (keycode == KEY_RIGHT)
		vars->img->y_ang -= M_PI / 40;
	else if (keycode == KEY_ZOOM_IN)
		vars->img->zoom *= 1.2;
	else if (keycode == KEY_ZOOM_OUT)
		vars->img->zoom /= 1.2;
	else if (keycode == KEY_ROT_LEFT)
		vars->img->z_ang += M_PI / 80;
	else if (keycode == KEY_ROT_RIGHT)
		vars->img->z_ang -= M_PI / 80;
	else
		ft_printf("Key : %d\n", keycode);
	print_all(vars);
	return (0);
}

static t_vars	*init_vars(char **av)
{
	t_vars	*vars;
	t_list	*list;

	vars = malloc(sizeof(t_vars));
	if (!vars)
		return (NULL);
	vars->mlx = mlx_init();
	vars->win = NULL;
	vars->img = window_init(vars->mlx, &vars->win);
	vars->col = 0;
	vars->row = 0;
	list = read_input(*av, &vars->row, &vars->col);
	if (list)
		vars->tab = get_3dcoord_tab(list, vars->col);
	if (!vars->tab)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		free(vars);
		vars = NULL;
	}
	return (vars);
}

int	main(int ac, char **av)
{
	t_vars	*vars;

	if (ac != 2)
	{
		ft_printf("Wrong number of arguments\n");
		return (1);
	}
	vars = init_vars(av + 1);
	if (!vars)
	{
		ft_printf("Can't read file\n");
		return (2);
	}
	print_all(vars);
	mlx_hook(vars->win, 2, 1L << 0, get_key, vars);
	mlx_loop(vars->mlx);
	mlx_destroy_image(vars->mlx, vars->img->img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free(vars->img);
	free(vars);
	return (0);
}
