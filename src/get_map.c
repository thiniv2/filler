/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 12:44:55 by thinguye          #+#    #+#             */
/*   Updated: 2021/08/24 14:52:43 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	map_size(t_map *map, char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		while (line[i] >= '0' && line[i] <= '9')
		{
			if (map->size_y == 0)
			{
				map->size_y = ft_atoi(line + i);
				i += count_nbr(map->size_y);
			}
			else if (map->size_x == 0)
			{
				map->size_x = ft_atoi(line + i);
				i += count_nbr(map->size_x);
			}
			else
				i++;
		}
		i++;
	}
}

void	get_map(t_map *map, t_piece *piece)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (strncmp(line, "Plateau", 6) == 0)
		{
			map_size(map, line);
			//init_map(map);
		}
	}
}
