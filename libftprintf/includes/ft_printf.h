/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 13:06:02 by thinguye          #+#    #+#             */
/*   Updated: 2021/09/17 13:06:03 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <limits.h>
# include "../libft/libft.h"
# include "get_next_line.h"

typedef struct s_identifiers
{
	const char	*format;
	char		*flag;
	size_t		minwth;
	size_t		period;
	size_t		maxwth;
	size_t		i;
	size_t		printed_chars;
	size_t		double_len;
	int			negative;
	char		*arg_type;
	char		*modifiers;
	char		current_flag[6];
	char		current_type;
	char		current_modifier[3];
	va_list		arguments;
}				t_tags;

t_tags			*scan_flags(t_tags *ids);
t_tags			*scan_minwth(t_tags *ids);
t_tags			*scan_period_maxwth(t_tags *ids);
t_tags			*scan_modifier(t_tags *ids);
t_tags			*scan_arg_type(t_tags *ids);
t_tags			*create_tmp_ids(t_tags *ids);
t_tags			*read_arg_type(t_tags *ids);
t_tags			*print_d(t_tags *ids);
t_tags			*put_zero_oxu(t_tags *ids, size_t len);
t_tags			*put_zero_df(t_tags *ids, size_t len);
t_tags			*put_zero_p(t_tags *ids, size_t len);
t_tags			*put_plusminus(t_tags *ids, intmax_t nbr);
t_tags			*minwth_print(t_tags *ids, size_t len);
t_tags			*period_zero(t_tags *ids);
int				ft_printf(const char *format, ...);
int				read_format(t_tags *ids);
intmax_t		base_nbrcount(intmax_t n, size_t base);
intmax_t		unsigned_base_nbrcount(uintmax_t n, size_t base);
#endif
