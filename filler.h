/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 01:57:45 by alkozma           #+#    #+#             */
/*   Updated: 2019/03/13 23:27:54 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "includes/ftgnl.h"
#include "includes/ftprintf.h"
#include "includes/libft.h"

typedef struct			s_filler
{
	char				**map;
	int					**piece;
	int					max_x;
	int					max_y;
	int					max_piece_x;
	int					max_piece_y;
}						t_filler;

int		read_input(void);
char	**read_map(int max_x, int max_y);
int		**read_piece(int max_x, int max_y);
int		owner(int y, int x, t_filler *f);
int		can_place(int x, int y, t_filler *f);
int		place(t_filler *f);

int		move_right_down(t_filler *f);
int		move_left_down(t_filler *f);
int		move_right_up(t_filler *f);
int		move_left_up(t_filler *f);
#endif
