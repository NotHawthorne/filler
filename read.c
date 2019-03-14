/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 01:56:37 by alkozma           #+#    #+#             */
/*   Updated: 2019/03/13 23:29:05 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <fcntl.h>
#include <stdio.h>

int		read_input(void)
{
	char		*line;
	t_filler	*f;
	int			i;
	char		**elems;

	line = NULL;
	if (get_next_line(0, &line) > 0)
	{
		f = (t_filler*)malloc(sizeof(t_filler));
		i = -1;
		f->max_x = ft_atoi(ft_strsplit(line, ' ')[2]);
		f->max_y = ft_atoi(ft_strsplit(line, ' ')[1]);
		get_next_line(0, &line);
		f->map = read_map(f->max_x, f->max_y);
		get_next_line(0, &line);
		elems = ft_strsplit(line, ' ');
		f->max_piece_x = ft_atoi(elems[1]);
		f->max_piece_y = ft_atoi(elems[2]);
		f->piece = read_piece(f->max_piece_x, f->max_piece_y);
		return (move_right_up(f));
	}
	return (0);
}

char	**read_map(int max_x, int max_y)
{
	char	**ret;
	char	*line;
	int		y;
	int		i;

	i = 0;
	y = 0;
	if (!(ret = (char**)malloc(sizeof(char*) * 2)) ||
			!(ret[0] = (char*)malloc(sizeof(char) * ((max_x * max_y) / 8))) ||
			!(ret[1] = (char*)malloc(sizeof(char) * ((max_x * max_y) / 8))))
		return (NULL);
	while (get_next_line(0, &line) > 0)
	{
		line += 3;
		while (*(++line))
		{
			ret[0][i / 8] = (ret[0][i / 8] << 1) + (*line == 'O');
			ret[1][i / 8] = (ret[1][i / 8] << 1) + (*line == 'X');
			i++;
		}
		if (++y == max_y)
			break ;
	}
	if (i % 8 > 0)
	{
		ret[0][(i - 1) / 8] <<= (8 - (i % 8));
		ret[1][(i - 1) / 8] <<= (8 - (i % 8));
	}
	return (ret);
}

int		**read_piece(int max_x, int max_y)
{
	int			**ret;
	char		*line;
	int			x;
	int			y;
	int			i;

	x = 0;
	y = 0;
	i = 0;
	if (!(ret = (int**)malloc(sizeof(int*) * ((max_x * max_y) + 1))))
		return (NULL);
	while (get_next_line(0, &line) > 0)
	{
		while (*line)
		{
			if (*line++ != '.')
			{
				if (!(ret[i] = (int*)malloc(sizeof(int) * 2)))
					return (NULL);
				ret[i][0] = x;
				ret[i++][1] = y;
			}
			x = (x + 1) % max_y;
		}
		y++;
		if (y >= max_x)
			break ;
	}
	ret[i] = NULL;
	return (ret);
}
