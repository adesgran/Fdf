/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 12:40:56 by adesgran          #+#    #+#             */
/*   Updated: 2022/01/14 11:25:21 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	*free_node_tab(t_node **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static t_node	**init_tab(void)
{
	struct s_node	**tab;
	t_node			*temp;
	int				i;
	int				j;

	tab = (t_node **)malloc(sizeof(*tab) * (long int)W_HEIGHT);
	if (!tab)
		return (NULL);
	i = -1;
	while (++i < W_HEIGHT)
	{
		temp = (t_node *)malloc(sizeof(**tab) * (W_WIDTH));
		tab[i] = temp;
		if (!tab[i])
			return (free_node_tab(tab));
		j = -1;
		while (++j < W_WIDTH)
		{
			tab[i][j].z = -2000;
			tab[i][j].color = 0x00222222;
		}
		temp = NULL;
	}
	tab[i] = NULL;
	return (tab);
}

static void	put_curr_tab(t_vars *vars, t_node **tab)
{
	int		i;
	int		j;
	t_node	temp;

	i = 0;
	while (i < W_HEIGHT)
	{
		j = 0;
		while (j < W_WIDTH)
		{
			temp = tab[i][j];
			put_pixel(vars->img, j, i, temp.color);
			j++;
		}
		i++;
	}
}

void	put_tab(t_vars *vars, t_3dcoord **tab)
{
	t_node	**curr_tab;
	int		i;
	int		j;

	curr_tab = init_tab();
	j = 0;
	while (j < vars->row)
	{
		i = 0;
		while (i < vars->col)
		{
			if (i != vars->col - 1)
				add_line(curr_tab, tab[j][i], tab[j][i + 1]);
			if (j != vars->row - 1)
				add_line(curr_tab, tab[j][i], tab[j + 1][i]);
			i++;
		}
		j++;
	}
	put_curr_tab(vars, curr_tab);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	free_node_tab(curr_tab);
}
