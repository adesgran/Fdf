/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 15:05:41 by adesgran          #+#    #+#             */
/*   Updated: 2021/12/25 19:22:09 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static int	line_length(char *line)
{
	int	i;
	
	i = 0;
	while (*line)
	{
		if (*line >= '0' && *line <= '9')
		{
			i++;
			while (*line <= '9' && *line >= '0')
				line++;
		}
		if (*line == ',')
			line += 9;
		while (*line && (*line > '9' || *line < '0'))
			line++;
	}
	return (i);
}

static float	*parse_line(char *line, int *n_col)
{
	int		size;
	float	*res;
	int		i;

	size = line_length(line);
	*n_col = size;
	res = malloc(sizeof(float) * size);
	i = 0;
	while (*line)
	{
		if (*line >= '0' && *line <= '9')
		{
			res[i] = (float)atoi(line);
			i++;
			while (*line <= '9' && *line >= '0')
				line++;
		}
		if (*line == ',')
			line += 9;
		while (*line && (*line > '9' || *line < '0'))
			line++;
	}
	return (res);
}



static t_list	*read_file(char *filename, int *n_col)
{
	t_list	*res;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	line = ft_get_next_line(fd);
	if (!line)
		return (NULL);
	res = ft_lstnew(parse_line(line, n_col));
	free(line);
	line = ft_get_next_line(fd);
	while (line)
	{
		ft_lstadd_back(&res, ft_lstnew(parse_line(line, n_col)));
		free(line);
		line = ft_get_next_line(fd);
	}
	return (res);
}

t_list	*read_input(char *filename, int *n_line, int *n_col)
{
	t_list	*file;

	file = read_file(filename, n_col);
	*n_line = ft_lstsize(file);
	return (file);
}
