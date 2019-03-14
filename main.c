/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 02:26:14 by alkozma           #+#    #+#             */
/*   Updated: 2019/03/14 01:48:23 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	char		*line;
	t_filler	*f;

	f = (t_filler*)malloc(sizeof(t_filler));
	f->top_linked = 0;
	f->bot_linked = 0;
	f->left_linked = 0;
	f->right_linked = 0;
	line = NULL;
	get_next_line(0, &line);
	while (1)
	{
		if (read_input(f) == 0)
			return (0);
	}
	return (0);
}
