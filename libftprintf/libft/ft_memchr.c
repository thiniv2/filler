/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 13:00:19 by thinguye          #+#    #+#             */
/*   Updated: 2021/09/17 13:00:19 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	a;

	i = 0;
	a = (unsigned char)c;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == a)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
