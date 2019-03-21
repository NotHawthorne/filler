/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 01:57:45 by alkozma           #+#    #+#             */
/*   Updated: 2019/03/20 15:46:12 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "includes/ftgnl.h"
# include "includes/ftprintf.h"
# include "includes/libft.h"

typedef struct			s_filler
{
	char				**map;
	int					**piece;
	int					max_x;
	int					max_y;
	int					max_piece_x;
	int					max_piece_y;
	int					player;
	int					left_linked;
	int					right_linked;
	int					top_linked;
	int					bot_linked;
}						t_filler;

int						read_input(t_filler *f);
char					**read_map(int max_x, int max_y);
int						**read_piece(int max_x, int max_y);
int						owner(int y, int x, t_filler *f);
int						can_place(int x, int y, t_filler *f);
int						place(t_filler *f);
int						is_edge(int x, int y, t_filler *f);

int						move_towards_point(t_filler *f, int x, int y);

int						check_area(t_filler *f, int x, int y, int area);

int						glomp(t_filler *f);

int						*create_piece(int x, int y);
void					free_piece(t_filler *f);

#endif
