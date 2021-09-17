/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 12:59:46 by thinguye          #+#    #+#             */
/*   Updated: 2021/09/17 12:59:47 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	size_t		count;
	long		nbr;
	char		*str;

	nbr = (long)n;
	count = ft_nbrcount((intmax_t)n);
	str = ft_strnew(count);
	count--;
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	while (nbr > 0)
	{
		str[count] = nbr % 10 + '0';
		nbr /= 10;
		count--;
	}
	return (str);
}
