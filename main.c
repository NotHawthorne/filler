/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 02:26:14 by alkozma           #+#    #+#             */
/*   Updated: 2019/03/20 15:06:44 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <limits.h>

int		main(void)
{
	char		*line;
	t_filler	*f;

	f = (t_filler*)malloc(sizeof(t_filler));
	line = NULL;
	get_next_line(0, &line);
	f->player = ft_strstr(line, "p1") == NULL ? 1 : 0;
	while (1)
	{
		if (read_input(f) == 0)
			return (0);
	}
	return (0);
}
