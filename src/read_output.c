/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 11:43:17 by thinguye          #+#    #+#             */
/*   Updated: 2021/09/27 15:11:30 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	duplicate_board(t_map *map, int y)
{
	char	*line;

	get_next_line(0, &line);
	free(line);
	while (y < map->height && get_next_line(0, &line))
	{
		map->board[y] = ft_strsub(line, 4, map->width);
		if (!map->board[y])
			return (-1);
		free(line);
		y++;
	}
	map->board[y] = NULL;
	return (1);
}

void	get_player(t_map *map, char *line)
{
	if (ft_strstr(line, "p1"))
		map->player = 1;
	else
		map->player = 2;
}

int	read_output(t_map *map, t_piece *piece, int x)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (ft_strstr(line, "thinguye.filler"))
			get_player(map, line);
		if (ft_strstr(line, "Plateau"))
		{
			while (!(ft_isdigit(line[x])))
				x++;
			map->height = ft_atoi(&(line[x]));
			x += ft_nbrcount(map->height) + 1;
			map->width = ft_atoi(&(line[x]));
			map->board = (char **)malloc(sizeof(char *) * (map->height + 1));
			if (!map->board)
				return (-1);
			free(line);
			break ;
		}
		free(line);
	}
	if (duplicate_board(map, 0) == -1)
		return (-1);
	read_piece(map, piece, 0);
	return (1);
}
