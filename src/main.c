/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:34:26 by thinguye          #+#    #+#             */
/*   Updated: 2021/08/24 14:46:32 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	get_player(t_map *map)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "thinguye.filler"))
		{
			if (ft_strstr(line, "p1"))
			{
				map->player = 1;
				map->me = ft_strdup("Oo");
				map->enemy = ft_strdup("Xx");
			}
			else
			{
				map->player = 2;
				map->me = ft_strdup("Xx");
				map->enemy = ft_strdup("Oo");
			}
		}
	}
}

void	initialize(t_map *map)
{
	map->player = 0;
	map->size_y = 0;
	map->size_x = 0;
}

int	main(void)
{
	t_map	*map;
	t_piece	*piece;

	map = (t_map *)malloc(sizeof(t_map));
	piece = (t_piece *)malloc(sizeof(t_piece));
	initialize(map);
	get_player(map);
	while (1)
	{
		get_map(map, piece);
		break ;
	}
	return (0);
}
