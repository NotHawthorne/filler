/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkozma <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 13:20:46 by alkozma           #+#    #+#             */
/*   Updated: 2019/03/19 07:33:04 by alkozma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTGNL_H
# define FTGNL_H
# include "libft.h"

# define BUFF_SIZE 32

# define MEMCHK(m) if (!m) return (-1);
# define CONTENTCHK(c) if (!c) return (0);
# define NO_NEW_LINE -1

int		get_next_line(int fd, char **line);

#endif
