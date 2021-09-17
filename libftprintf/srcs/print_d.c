/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 12:55:32 by thinguye          #+#    #+#             */
/*   Updated: 2021/09/17 12:55:34 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_tags	*put_plusminus(t_tags *ids, intmax_t nbr)
{
	if (nbr < 0)
		write(1, "-", 1);
	if (nbr >= 0)
		write(1, "+", 1);
	ids->printed_chars++;
	return (ids);
}

t_tags	*print_d(t_tags *ids)
{
	intmax_t	nbr;
	char		*str;

	nbr = (int)va_arg(ids->arguments, int);
	str = ft_itoa(nbr);
	ft_putstr(str);
	free(str);
	return (ids);
}
