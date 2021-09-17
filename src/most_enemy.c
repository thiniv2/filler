/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   most_enemy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 14:04:58 by thinguye          #+#    #+#             */
/*   Updated: 2021/09/15 15:40:03 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	top_left(t_map *map, int y, int x)
{
	int		count;

	count = 0;
	while (y + 1 < map->height / 2)
	{
		while (x + 1 < map->width / 2)
		{
			if (map->board[y][x] == map->enemy[0]
				|| map->board[y][x] == map->enemy[1])
				count++;
			x++;
		}
		y++;
		x = 0;
	}
	return (count);
}

int	top_right(t_map *map, int y, int x)
{
	int	count;

	count = 0;
	while (y + 1 < map->height / 2)
	{
		while (x < map->width)
		{
			if (map->board[y][x] == map->enemy[0]
				|| map->board[y][x] == map->enemy[1])
				count++;
			x++;
		}
		y++;
		x = map->width / 2;
	}
	return (count);
}

int	bottom_left(t_map *map, int y, int x)
{
	int	count;

	count = 0;
	while (y < map->height)
	{
		while (x + 1 < map->width / 2)
		{
			if (map->board[y][x] == map->enemy[0]
				|| map->board[y][x] == map->enemy[1])
				count++;
			x++;
		}
		y++;
		x = 0;
	}
	return (count);
}

int	bottom_right(t_map *map, int y, int x)
{
	int	count;

	count = 0;
	while (y < map->height)
	{
		while (x < map->width)
		{
			if (map->board[y][x] == map->enemy[0]
				|| map->board[y][x] == map->enemy[1])
				count++;
			x++;
		}
		y++;
		x = map->width / 2;
	}
	return (count);
}

int	most_enemy(t_map *map, int max, int res)
{
	res = top_left(map, 0, 0);
	if (max < res)
	{
		max = res;
		map->most_enemy = UPLEFT;
	}
	res = top_right(map, 0, map->width / 2);
	if (max < res)
	{
		max = res;
		map->most_enemy = UPRIGHT;
	}
	res = bottom_left(map, map->height / 2, 0);
	if (max < res)
	{
		max = res;
		map->most_enemy = DOWNLEFT;
	}
	res = bottom_right(map, map->height / 2, map->width / 2);
	if (max < res)
	{
		max = res;
		map->most_enemy = DOWNRIGHT;
	}
	return (map->most_enemy);
}
