/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 02:54:15 by alkozma           #+#    #+#             */
/*   Updated: 2019/03/14 01:01:14 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		owner(int x, int y, t_filler *f)
{
	int magic_formula;

	magic_formula = (y * f->max_x) + x;
	if ((f->map[0][magic_formula / 8] >> (7 - (magic_formula % 8))) & 1)
		return (1);
	if ((f->map[1][magic_formula / 8] >> (7 - (magic_formula % 8))) & 1)
		return (2);
	return (0);
}

int		can_place(int x, int y, t_filler *f)
{
	int	i;
	int	linked;
	int	cell_owner;

	i = 0;
	linked = 0;
	while (f->piece[i])
	{
		cell_owner = -1;
		if ((f->piece[i][0] + x >= 0 && f->piece[i][0] + x < f->max_x) &&
				(f->piece[i][1] + y >= 0 && f->piece[i][1] + y < f->max_y))
			cell_owner = owner(f->piece[i][0] + x, f->piece[i][1] + y, f);
		else
			return (0);
		if (cell_owner == 2)
			return (0);
		else if (cell_owner == 1)
			linked++;
		i++;
	}
	if (linked > 1)
		return (0);
	return (linked);
}

int		place(t_filler *f)
{
	int	x;
	int	y;

	x = 0;
	while (x <= f->max_x - f->max_piece_y)
	{
		y = 0;
		while (y <= f->max_y - f->max_piece_x)
		{
			if (can_place(x, y, f))
			{
				ft_printf("%d %d\n", y, x);
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}

int		is_edge(int x, int y, t_filler *f)
{
	int	i;

	i = 0;
	while (f->piece[i])
	{
		if (f->piece[i][0] + x == 0)
			return ((f->left_linked = 1));
		else if (f->piece[i][0] + x == f->max_x - 1)
			return ((f->right_linked = 1));
		else if (f->piece[i][1] + y == 0)
			return ((f->top_linked = 1));
		else if (f->piece[i++][1] + y == f->max_y - 1)
			return ((f->bot_linked = 1));
	}
	return (0);
}
