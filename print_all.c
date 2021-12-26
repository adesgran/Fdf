/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 13:54:08 by adesgran          #+#    #+#             */
/*   Updated: 2021/12/26 14:14:32 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	print_all(t_vars *vars)
{
	t_coord		**temp;
	t_coord		**proj_tab;

	proj_tab = matrix_application(vars, vars->tab, vars->col);
	if (!proj_tab)
		return ;
	put_tab(vars, proj_tab);
	temp = proj_tab;
	while (*temp)
	{
		free(*temp);
		temp++;
	}
	free(proj_tab);
}
