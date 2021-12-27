/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 13:07:20 by adesgran          #+#    #+#             */
/*   Updated: 2021/12/27 16:16:51 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define KEY_UP 119
# define KEY_LEFT 97
# define KEY_DOWN 115
# define KEY_RIGHT 100
# define KEY_ESCAPE 65307
# define KEY_ZOOM_IN 65451
# define KEY_ZOOM_OUT 65453
# define KEY_ROT_LEFT 113
# define KEY_ROT_RIGHT 101

# define DEBUG ft_printf("HERE\n");

# define W_WIDTH 1000
# define W_HEIGHT 1000

# include <libft.h>
# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_data {
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	float	x_ang;
	float	y_ang;
	float	z_ang;
	float	zoom;
}	t_data;

typedef struct s_coord {
	float			x;
	float			y;
	unsigned int	color;
}	t_coord;

typedef struct	s_node {
	float			z;
	unsigned int	color;
}	t_node;

typedef struct s_3dcoord {
	float			x;
	float			y;
	float			z;
	unsigned int	color;
}	t_3dcoord;

typedef struct	s_vars {
	void		*mlx;
	void		*win;
	t_data		*img;
	t_3dcoord	**tab;
	int			row;
	int			col;
}	t_vars;

t_data			*window_init(void *mlx, void **mlx_win);
void			put_pixel(t_data *img, int x, int y, ...);
void			add_pixel(t_node **tab, t_3dcoord curr);
void			add_line(t_node **tab, t_3dcoord start, t_3dcoord end);
void			rotate_x(t_3dcoord *p, float angle);
void			rotate_y(t_3dcoord *p, float angle);
void			rotate_z(t_3dcoord *p, float angle);
t_3dcoord		projection_2d(t_vars *vars, t_3dcoord p, float ratio);
t_list			*read_input(char *filename, int *n_line, int *n_col);
t_3dcoord		**get_3dcoord_tab(t_list *list, int len);
t_3dcoord		**matrix_application(t_vars *vars, t_3dcoord **tab, int size);
void			put_tab(t_vars *var, t_3dcoord **tab);
void			print_all(t_vars *vars);
unsigned int	set_default_color(int z);
unsigned int	ft_atoi_hex(char *s);
unsigned int	color_gradient(int index, int size, unsigned int c1, unsigned int c2);

#endif
