/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 13:00:52 by thinguye          #+#    #+#             */
/*   Updated: 2021/08/23 13:49:50 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	read_output(t_map *map)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		ft_printf("%s\n", line);
	}
}