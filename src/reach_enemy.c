/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reach_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 12:06:11 by thinguye          #+#    #+#             */
/*   Updated: 2021/09/15 15:43:15 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	set_direction(t_map *map, t_piece *piece, char c)
{
	if (map->direction < 3 && c == 'y')
		return (piece->y_start);
	else if (c == 'y')
		return (piece->y_end);
	if (map->direction % 2 == 0 && c == 'x')
		return (piece->x_start);
	else if (c == 'x')
		return (piece->x_end);
	return (0);
}

int	check_incre(t_piece *piece, int incre_x)
{
	int		x;

	x = 0;
	if (incre_x < 0)
		x = piece->x_end;
	else
		x = piece->x_start;
	return (x);
}

int	block_enemy(t_map *map, t_piece *piece, int x, int y)
{
	double	contacts;
	int		incre_x;
	int		incre_y;

	contacts = 0;
	incre_x = set_increment(piece, 'x', y, x);
	incre_y = set_increment(piece, 'y', y, x);
	while (y >= piece->y_start && y <= piece->y_end)
	{
		while (x >= piece->x_start && x <= piece->x_end)
		{
			if (check_fit(map, piece, y, x) && map->contacts > contacts)
			{
				map->put_x = x;
				map->put_y = y;
				contacts = map->contacts;
			}
			x += incre_x;
		}
		y += incre_y;
		x = check_incre(piece, incre_x);
	}
	return (contacts > 0);
}

void	reach_enemy(t_map *map, t_piece *piece, int y, int x)
{
	map->put_x = 0;
	map->put_y = 0;
	if (map->phase > 0)
		map->direction = most_enemy(map, 0, 0);
	y = set_direction(map, piece, 'y');
	x = set_direction(map, piece, 'x');
	if (map->phase > 0 && block_enemy(map, piece, x, y))
		ft_printf("%d %d\n", map->put_y, map->put_x);
	else if (map->phase > 0)
		place_prior_y(map, piece, x, y);
	else
		place_piece(map, piece, y, x);
}
