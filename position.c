/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 04:26:30 by alkozma           #+#    #+#             */
/*   Updated: 2019/03/20 15:51:09 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_area(t_filler *f, int x, int y, int area)
{
	int	i;

	i = area + 1;
	while (--i >= -area)
	{
		if (can_place(x + area, y + i, f))
			return (ft_printf("%d %d\n", y + i, x + area));
		else if (can_place(x + area, y - i, f))
			return (ft_printf("%d %d\n", y - i, x + area));
		else if (can_place(x - area, y + i, f))
			return (ft_printf("%d %d\n", y + i, x - area));
		else if (can_place(x - area, y - i, f))
			return (ft_printf("%d %d\n", y - i, x - area));
		else if (can_place(x + i, y + area, f))
			return (ft_printf("%d %d\n", y + area, x + i));
		else if (can_place(x - i, y + area, f))
			return (ft_printf("%d %d\n", y + area, x - i));
		else if (can_place(x + i, y - area, f))
			return (ft_printf("%d %d\n", y - area, x + i));
		else if (can_place(x - i, y - area, f))
			return (ft_printf("%d %d\n", y - area, x - i));
	}
	return (0);
}

int		move_towards_point(t_filler *f, int x, int y)
{
	int		area;
	int		ret;

	area = 1;
	ret = 0;
	if (owner(x, y, f) == 1 && can_place(x, y, f))
	{
		ft_printf("%d %d\n", y, x);
		is_edge(x, y, f);
		return (1);
	}
	else
	{
		while ((ret = check_area(f, x, y, area)) == 0)
		{
			if (area++ + x >= f->max_x * 2)
				break ;
		}
	}
	return (ret == 0 ? 0 : 1);
}
