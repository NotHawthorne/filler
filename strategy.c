/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 17:49:33 by alkozma           #+#    #+#             */
/*   Updated: 2019/03/20 14:48:16 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		glomp(t_filler *f)
{
	int		x;
	int		y;
	int		end_found;

	x = 0;
	y = 0;
	end_found = 0;
	while (y < f->max_y)
	{
		if (owner(x, y, f) == 2)
		{
			if (owner(x - 1, y, f) == 0)
				return (move_towards_point(f, x, y));
			y++;
			end_found = x;
			x = -1;
		}
		y += ++x / (f->max_x - 1);
		x %= (f->max_x - 1);
	}
	return (move_towards_point(f, f->max_x, f->max_y));
}
