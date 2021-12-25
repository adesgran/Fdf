/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 13:07:20 by adesgran          #+#    #+#             */
/*   Updated: 2021/12/25 19:30:08 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define W_WIDTH 1000
# define W_HEIGHT 1000

# include <libft.h>
# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_data {
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_coord {
	float	x;
	float	y;
}	t_coord;

typedef struct s_3dcoord {
	float	x;
	float	y;
	float	z;
}	t_3dcoord;

t_data	*window_init(void *mlx, void **mlx_win);
void	put_pixel(t_data *img, int x, int y);
void	put_line(t_data *img, t_coord start, t_coord end);
void	rotate_x(t_3dcoord *p, float angle);
void	rotate_y(t_3dcoord *p, float angle);
void	rotate_z(t_3dcoord *p, float angle);
t_coord	projection_2d(t_3dcoord p, float ratio);
t_list	*read_input(char *filename, int *n_line, int *n_col);
t_3dcoord	**get_3dcoord_tab(t_list *list, int len);
t_coord	**matrix_application(t_3dcoord **tab, int size);
#endif
