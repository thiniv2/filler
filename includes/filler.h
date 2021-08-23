/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:35:28 by thinguye          #+#    #+#             */
/*   Updated: 2021/08/23 14:00:44 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "../ft_printf/includes/ft_printf.h"
#include <fcntl.h>

typedef struct		s_map
{
	char			own_char;
	char			enemy_char;
}					t_map;

void	read_output(t_map *map);

#endif