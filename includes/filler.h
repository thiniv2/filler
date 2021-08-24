/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:35:28 by thinguye          #+#    #+#             */
/*   Updated: 2021/08/24 14:46:03 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "../ft_printf/includes/ft_printf.h"
#include <fcntl.h>

typedef struct		s_map
{
	int				player;
	char			*me;
	char			*enemy;
	int				size_y;
	int				size_x;
}					t_map;

typedef struct		s_piece
{
	char			**piece;
}					t_piece;

void				get_map(t_map *map, t_piece *piece);

#endif
