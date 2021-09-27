/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_piece.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:12:05 by thinguye          #+#    #+#             */
/*   Updated: 2021/09/17 13:57:15 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	piece_values(t_map *map, t_piece *piece, int y, int x)
{
	int	first_x;

	first_x = piece->width - 1;
	while (piece->piece[y] != NULL)
	{
		while (piece->piece[y][x] != '\0')
		{
			if (piece->piece[y][x] == '*' && piece->y_start > 0)
				piece->y_start = 0 - y;
			if (piece->piece[y][x] == '*' && first_x > x)
				first_x = x;
			if (piece->piece[y][x] == '*' && piece->x_end <= x)
				piece->x_end = map->width - x - 1;
			if (piece->piece[y][x] == '*')
				piece->y_end = map->height - y - 1;
			x++;
		}
		x = 0;
		y++;
	}
	piece->x_start = 0 - first_x;
}

int	duplicate_piece(t_piece *piece, int y)
{
	char	*line;

	while (y < piece->height && get_next_line(0, &line))
	{
		piece->piece[y] = ft_strdup(line);
		free(line);
		y++;
	}
	piece->piece[y] = NULL;
	return (1);
}

int	read_piece(t_map *map, t_piece *piece, int x)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (ft_strstr(line, "Piece"))
		{
			while (!(ft_isdigit(line[x])))
				x++;
			piece->height = ft_atoi(&(line[x]));
			x += ft_nbrcount(piece->height) + 1;
			piece->width = ft_atoi(&(line[x]));
			piece->piece = (char **)malloc(sizeof(char *)
					* (piece->height + 1));
			free(line);
			break ;
		}
		free(line);
	}
	if (!(duplicate_piece(piece, 0)))
		return (0);
	piece_values(map, piece, 0, 0);
	return (1);
}
