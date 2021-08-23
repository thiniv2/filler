/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:34:26 by thinguye          #+#    #+#             */
/*   Updated: 2021/08/23 13:50:03 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int	main(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	map->own_char = 'O';
	map->enemy_char = 'X';
	read_output(map);
	return (0);
}
