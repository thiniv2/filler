/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 13:01:22 by thinguye          #+#    #+#             */
/*   Updated: 2021/09/17 13:01:22 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	k;

	k = n;
	if (k < 0)
	{
		ft_putchar_fd('-', fd);
		k = k * -1;
	}
	if (k / 10 > 0)
	{
		ft_putnbr_fd(k / 10, fd);
	}
	ft_putchar_fd('0' + k % 10, fd);
}
