/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_positions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 10:03:40 by thinguye          #+#    #+#             */
/*   Updated: 2021/09/15 14:40:24 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	get_directions(t_map *map)
{
	if (map->own_y > map->height / 2 && map->own_x > map->width / 2)
		map->direction = UPLEFT;
	else if (map->own_y > map->height / 2 && map->own_x < map->width / 2)
		map->direction = UPRIGHT;
	else if (map->own_y < map->height / 2 && map->own_x < map->width / 2)
		map->direction = DOWNRIGHT;
	else if (map->own_y < map->height / 2 && map->own_x > map->width / 2)
		map->direction = DOWNLEFT;
}

void	set_player(t_map *map)
{
	if (map->player == 1)
	{
		map->me = "Oo";
		map->enemy = "Xx";
	}
	else
	{
		map->me = "Xx";
		map->enemy = "Oo";
	}
}

void	get_positions(t_map *map, int y, int x)
{
	if (map->me != NULL && map->enemy != NULL)
		return ;
	set_player(map);
	while (map->board[y] != NULL)
	{
		while (map->board[y][x] != '\0')
		{
			if (map->board[y][x] == map->me[0])
			{
				map->own_y = y;
				map->own_x = x;
			}
			if (map->board[y][x] == map->enemy[0])
			{
				map->enemy_y = y;
				map->enemy_x = x;
			}
			x++;
		}
		x = 0;
		y++;
	}
	get_directions(map);
}
