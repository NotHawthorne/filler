/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 22:09:34 by alkozma           #+#    #+#             */
/*   Updated: 2019/03/13 23:28:22 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		move_right_down(t_filler *f)
{
	int x;
	int y;
	
	x = f->max_x - f->max_piece_y;
	while (x >= 0)
	{	
		y = f->max_y - f->max_piece_x;
		while (y >= 0)
		{
			if (can_place(x, y, f))
			{
				ft_printf("%d %d\n", y, x);
				return (1);
			}
			y--;
		}
		x--;
	}
	return (0);
}

int		move_left_down(t_filler *f)
{
	int	x;
	int	y;

	x = 0;
	while (x <= f->max_x - f->max_piece_y)
	{
		y = f->max_y - f->max_piece_x;
		while (y >= 0)
		{
			if (can_place(x, y, f))
			{
				ft_printf("%d %d\n", y, x);
				return (1);
			}
			y--;
		}
		x++;
	}
	return (0);
}

int		move_left_up(t_filler *f)
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

int		move_right_up(t_filler *f)
{
	int	x;
	int	y;

	x = f->max_x - f->max_piece_y;
	while (x >= 0)
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
		x--;
	}
	return (0);
}
