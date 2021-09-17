/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 12:55:48 by thinguye          #+#    #+#             */
/*   Updated: 2021/09/17 12:55:49 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_tags	*set_ids(t_tags *ids)
{
	ids->i = 0;
	ids->printed_chars = 0;
	ids->flag = "#0 +-";
	ids->arg_type = "%cCspdDiouxXf";
	ids->modifiers = "hlL";
	return (ids);
}

t_tags	*create_tmp_ids(t_tags *ids)
{
	ids->minwth = 0;
	ids->period = 0;
	ids->maxwth = 0;
	ids->negative = 1;
	ids->double_len = 0;
	ids->current_type = '\0';
	ids->current_flag[0] = '\0';
	ids->current_flag[1] = '\0';
	ids->current_flag[2] = '\0';
	ids->current_flag[3] = '\0';
	ids->current_flag[4] = '\0';
	ids->current_flag[5] = '\0';
	ids->current_modifier[0] = '\0';
	ids->current_modifier[1] = '\0';
	ids->current_modifier[2] = '\0';
	return (ids);
}

int	ft_printf(const char *format, ...)
{
	t_tags	*ids;

	ids = (t_tags *)malloc(sizeof(t_tags));
	ids->format = format;
	set_ids(ids);
	if (format)
	{
		va_start(ids->arguments, format);
		read_format(ids);
		va_end(ids->arguments);
	}
	free(ids);
	return (ids->printed_chars);
}
