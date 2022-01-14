/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesgran <adesgran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 15:05:41 by adesgran          #+#    #+#             */
/*   Updated: 2022/01/14 11:41:18 by adesgran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static size_t	line_length(char *line)
{
	size_t	i;

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

static char	*read_line(char *line, t_node *res, int *i)
{
	if (*line >= '0' && *line <= '9')
	{
		res[*i].z = (float)atoi(line);
		while (*line <= '9' && *line >= '0')
			line++;
		if (*line == ',')
		{
			res[*i].color = ft_atoi_hex(line + 1);
			line += 9;
		}
		else
			res[*i].color = set_default_color(res[*i].z);
		*i += 1;
	}
	while (*line && (*line > '9' || *line < '0'))
		line++;
	return (line);
}

static t_node	*parse_line(char *line, int *n_col)
{
	int		size;
	t_node	*res;
	int		i;

	size = line_length(line);
	*n_col = size;
	res = malloc(sizeof(t_node) * (size + 1));
	i = 0;
	while (*line)
	{
		line = read_line(line, res, &i);
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
