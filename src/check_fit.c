/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:57:46 by thinguye          #+#    #+#             */
/*   Updated: 2021/09/15 14:39:36 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	own_c(t_map *map, char board)
{
	return (board == map->me[0] || board == map->me[1]);
}

int	check_fit(t_map *map, t_piece *piece, int y, int x)
{
	int		py;
	int		px;
	int		overlap;

	py = -1;
	px = -1;
	overlap = 0;
	map->contacts = 0;
	while (++py < piece->height)
	{
		while (piece->piece[py][++px] != '\0')
		{
			if (piece->piece[py][px] == '*'
				&& own_c(map, map->board[y][x]) && count_contacts(map, y, x))
				overlap++;
			if (overlap > 1 || (piece->piece[py][px] == '*'
				&& !(own_c(map, map->board[y][x])) && map->board[y][x] != '.'))
				return (0);
			x++;
		}
		y++;
		px = -1;
		x -= piece->width;
	}
	return (overlap == 1);
}
