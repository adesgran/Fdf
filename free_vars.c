/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 10:57:11 by adesgran          #+#    #+#             */
/*   Updated: 2022/01/14 11:16:11 by adesgran         ###   ########.fr       */
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
	return (NULL);
}

void	*free_vars(t_vars *vars)
{
	free_tab(vars);
	free(vars);
	return (NULL);
}
