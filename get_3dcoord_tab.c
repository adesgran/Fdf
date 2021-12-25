/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_3dcoord_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 17:26:37 by adesgran          #+#    #+#             */
/*   Updated: 2021/12/25 17:50:06 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static t_3dcoord	*float_to_3d(float *content, int len, int index)
{
	t_3dcoord	*res;
	int			i;

	res = malloc(sizeof(t_3dcoord) * (len));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i].x = (float)i;
		res[i].y = (float)index;
		res[i].z = content[i];
		i++;
	}
	return (res);
}

t_3dcoord	**get_3dcoord_tab(t_list *list, int len)
{
	t_3dcoord	**res;
	int			i;
	t_list		*temp;

	res = malloc(sizeof(t_3dcoord *) * (ft_lstsize(list) + 1));
	if (!res)
		return (res);
	i = 0;
	while (list)
	{
		res[i] = float_to_3d((float *)list->content, len, i);
		temp = list;
		list = list->next;
		free(temp->content);
		free(temp);
		i++;
	}
	res[i] = NULL;
	return (res);
}
