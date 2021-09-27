/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:34:26 by thinguye          #+#    #+#             */
/*   Updated: 2021/09/27 14:38:42 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	free_all(t_map *map, t_piece *piece)
{
	int		y;

	y = 0;
	while (y <= map->height)
	{
		ft_strdel(&(map->board[y]));
		y++;
	}
	free(map->board);
	y = 0;
	while (y <= piece->height)
	{
		ft_strdel(&(piece->piece[y]));
		y++;
	}
	free(piece->piece);
}

void	reset_piece(t_piece *piece)
{
	piece->height = 0;
	piece->width = 0;
	piece->y_start = 1;
	piece->y_end = 0;
	piece->x_start = 0;
	piece->x_end = 0;
}

int	main(void)
{
	t_map	*map;
	t_piece	*piece;

	map = (t_map *)malloc(sizeof(t_map));
	piece = (t_piece *)malloc(sizeof(t_piece));
	if (!map || !piece)
		return (-1);
	map->phase = 0;
	map->me = NULL;
	map->enemy = NULL;
	while (1)
	{
		reset_piece(piece);
		if (!(read_output(map, piece, 0)))
			return (-1);
		get_positions(map, 0, 0);
		reach_enemy(map, piece, 0, 0);
		free_all(map, piece);
		if (map->stop == 1)
			break ;
	}
	free(piece);
	free(map);
	return (0);
}
