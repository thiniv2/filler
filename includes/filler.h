/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:35:28 by thinguye          #+#    #+#             */
/*   Updated: 2021/09/15 15:55:27 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libftprintf/includes/ft_printf.h"

# define UPRIGHT 1
# define UPLEFT 2
# define DOWNRIGHT 3
# define DOWNLEFT 4

typedef struct s_map
{
	char			**board;
	char			*me;
	char			*enemy;
	int				player;
	int				height;
	int				width;
	int				own_x;
	int				own_y;
	int				enemy_x;
	int				enemy_y;
	int				direction;
	int				phase;
	int				most_enemy;
	double			contacts;	
	int				put_x;
	int				put_y;
	int				stop;
}					t_map;

typedef struct s_piece
{
	char			**piece;
	int				height;
	int				width;
	int				y_start;
	int				y_end;
	int				x_start;
	int				x_end;
}					t_piece;

int					read_output(t_map *map, t_piece *piece, int x);
int					read_piece(t_map *map, t_piece *piece, int x);
int					own_char(t_map *map, char board);
int					count_contacts(t_map *map, int y, int x);
int					most_enemy(t_map *map, int max, int res);
int					check_fit(t_map *map, t_piece *piece, int y, int x);
void				get_positions(t_map *map, int y, int x);
void				reach_enemy(t_map *map, t_piece *piece, int y, int x);
void				place_piece(t_map *map, t_piece *piece, int y, int x);
void				place_prior_y(t_map *map, t_piece *piece, int x, int y);
int					set_increment(t_piece *piece, char c, int y, int x);

#endif
