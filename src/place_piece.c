/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 11:44:57 by thinguye          #+#    #+#             */
/*   Updated: 2021/09/15 16:56:41 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	change_direction(t_map *map)
{
	int	row;

	row = 0;
	while (map->phase == 0 && row < map->height)
	{
		if (ft_strstr(map->board[row], "XO")
			|| ft_strstr(map->board[row], "OX")
			|| ft_strstr(map->board[row], "O.X")
			|| ft_strstr(map->board[row], "X.O")
			|| ft_strstr(map->board[row], "O..X")
			|| ft_strstr(map->board[row], "X..O")
			|| ft_strstr(map->board[0], "OO")
			|| ft_strstr(map->board[0], "XX")
			|| ft_strstr(map->board[map->height - 1], "OO")
			|| ft_strstr(map->board[map->height - 1], "XX"))
			map->phase = 1;
		row++;
	}
	if (map->height < 20 && map->player == 2
		&& (ft_strstr(map->board[0], ".................")))
		map->phase = 0;
}

int	set_increment(t_piece *piece, char c, int y, int x)
{
	if ((c == 'y' && y == piece->y_start)
		|| (c == 'x' && x == piece->x_start))
		return (1);
	else
		return (-1);
	return (0);
}

void	place_prior_y(t_map *map, t_piece *piece, int x, int y)
{
	int		incre_y;
	int		incre_x;

	incre_y = set_increment(piece, 'y', y, x);
	incre_x = set_increment(piece, 'x', y, x);
	while (!(check_fit(map, piece, y, x)))
	{
		y += incre_y;
		if (y < piece->y_start || y > piece->y_end)
		{
			x += incre_x;
			if (y < piece->y_start)
				y = piece->y_end;
			else
				y = piece->y_start;
		}
		if (x < piece->x_start || x > piece->x_end)
		{
			ft_printf("0 0\n");
			map->stop = 1;
			return ;
		}
	}
	ft_printf("%d %d\n", y, x);
}

int	set_x(t_piece *piece, int x)
{
	if (x < piece->x_start)
		x = piece->x_end;
	else
		x = piece->x_start;
	return (x);
}

void	place_piece(t_map *map, t_piece *piece, int y, int x)
{
	int		incre_y;
	int		incre_x;

	incre_x = set_increment(piece, 'x', y, x);
	incre_y = set_increment(piece, 'y', y, x);
	while (!(check_fit(map, piece, y, x)))
	{
		x += incre_x;
		if (x < piece->x_start || x > piece->x_end)
		{
			y += incre_y;
			x = set_x(piece, x);
		}
		if (y < piece->y_start || y > piece->y_end)
		{
			ft_printf("0 0\n");
			map->stop = 1;
			return ;
		}
	}
	if (map->phase < 1)
		change_direction(map);
	ft_printf("%d %d\n", y, x);
}
