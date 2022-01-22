/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 10:57:11 by adesgran          #+#    #+#             */
/*   Updated: 2022/01/22 13:48:40 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	*free_tab(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < vars->row)
	{
		free(vars->tab[i]);
		i++;
	}
	free(vars->tab);
	return (NULL);
}

static void	stop_display(t_vars *vars)
{
	mlx_loop_end(vars->mlx);
}

void	*free_vars(t_vars *vars)
{
	free_tab(vars);
	stop_display(vars);
	return (NULL);
}
