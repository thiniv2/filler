/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tags_and_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 12:56:05 by thinguye          #+#    #+#             */
/*   Updated: 2021/09/17 12:56:05 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_tags	*read_arg_type(t_tags *ids)
{
	if (ids->current_type == 'd' || ids->current_type == 'i')
		print_d(ids);
	return (ids);
}

static t_tags	*call_identifier_readers(t_tags *ids)
{
	ids->i++;
	create_tmp_ids(ids);
	scan_flags(ids);
	scan_minwth(ids);
	scan_period_maxwth(ids);
	scan_modifier(ids);
	scan_arg_type(ids);
	read_arg_type(ids);
	return (ids);
}

int	read_format(t_tags *ids)
{
	while (ids->format[ids->i])
	{
		if (ids->format[ids->i] == '%' && ids->format[ids->i + 1] == '%')
		{
			write(1, &ids->format[ids->i], 1);
			ids->i += 2;
			ids->printed_chars++;
		}
		else if (ids->format[ids->i] == '%')
			call_identifier_readers(ids);
		else
		{
			write(1, &ids->format[ids->i], 1);
			ids->printed_chars++;
			ids->i++;
		}
	}
	return (0);
}
