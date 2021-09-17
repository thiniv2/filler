/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_contacts.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 13:15:24 by thinguye          #+#    #+#             */
/*   Updated: 2021/09/14 16:40:55 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	further_corners(t_map *map, int y, int x)
{
	double	count;

	count = 0;
	if (y > 1 && x > 1
		&& (map->board[y - 2][x - 2] == map->enemy[0]
		|| map->board[y - 2][x - 2] == map->enemy[1]))
		count += 0.5;
	if (y > 1 && x + 2 < map->width
		&& (map->board[y - 2][x + 2] == map->enemy[0]
		|| map->board[y - 2][x + 2] == map->enemy[1]))
		count += 0.5;
	if (y + 2 < map->height && x > 1
		&& (map->board[y + 2][x - 2] == map->enemy[0]
		|| map->board[y + 2][x - 2] == map->enemy[1]))
		count += 0.5;
	if (y + 2 < map->height && x + 2 < map->width
		&& (map->board[y + 2][x + 2] == map->enemy[0]
		|| map->board[y + 2][x + 2] == map->enemy[1]))
		count += 0.5;
	map->contacts += count;
}

void	further_contacts(t_map *map, int y, int x)
{
	double	count;

	count = 0;
	if (x + 3 < map->width
		&& (map->board[y][x + 3] == map->enemy[0]
		|| map->board[y][x + 3] == map->enemy[1]))
		count += 0.5;
	if (x > 2
		&& (map->board[y][x - 3] == map->enemy[0]
		|| map->board[y][x - 3] == map->enemy[1]))
		count += 0.5;
	if (y + 3 < map->height
		&& (map->board[y + 3][x] == map->enemy[0]
		|| map->board[y + 3][x] == map->enemy[1]))
		count += 0.5;
	if (y > 2
		&& (map->board[y - 3][x] == map->enemy[0]
		|| map->board[y - 3][x] == map->enemy[1]))
		count += 0.5;
	map->contacts += count;
	further_corners(map, y, x);
}

void	count_corners(t_map *map, int y, int x)
{
	int		count;

	count = 0;
	if (y > 0 && x > 0
		&& (map->board[y - 1][x - 1] == map->enemy[0]
		|| map->board[y - 1][x - 1] == map->enemy[1]))
		count++;
	if (y > 0 && x + 1 < map->width
		&& (map->board[y - 1][x + 1] == map->enemy[0]
		|| map->board[y - 1][x + 1] == map->enemy[1]))
		count++;
	if (y + 1 < map->height && x > 0
		&& (map->board[y + 1][x - 1] == map->enemy[0]
		|| map->board[y + 1][x - 1] == map->enemy[1]))
		count++;
	if (y + 1 < map->height && x + 1 < map->width
		&& (map->board[y + 1][x + 1] == map->enemy[0]
		|| map->board[y + 1][x + 1] == map->enemy[1]))
		count++;
	map->contacts += count;
}

int	count_contacts(t_map *map, int y, int x)
{
	int	count;

	count = 0;
	if (x + 2 < map->width
		&& (map->board[y][x + 2] == map->enemy[0]
		|| map->board[y][x + 2] == map->enemy[1]))
		count++;
	if (x > 1
		&& (map->board[y][x - 2] == map->enemy[0]
		|| map ->board[y][x - 2] == map->enemy[1]))
		count++;
	if (y + 2 < map->height
		&& (map->board[y + 2][x] == map->enemy[0]
		|| map->board[y + 2][x] == map->enemy[1]))
		count++;
	if (y > 1
		&& (map->board[y - 2][x] == map->enemy[0]
		|| map->board[y - 2][x] == map->enemy[1]))
		count++;
	map->contacts += count;
	count_corners(map, y, x);
	further_contacts(map, y, x);
	return (1);
}
