/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 13:07:20 by adesgran          #+#    #+#             */
/*   Updated: 2021/12/24 14:08:40 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define W_WIDTH 500
# define W_HEIGHT 500

# include <libft.h>
# include <mlx.h>
# include <stdio.h>

typedef struct s_data {
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

t_data	*window_init(void *mlx);

#endif
