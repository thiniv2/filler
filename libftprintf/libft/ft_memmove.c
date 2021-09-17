/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 13:00:41 by thinguye          #+#    #+#             */
/*   Updated: 2021/09/17 13:00:41 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*destin;
	unsigned char	*source;
	size_t			i;

	destin = (unsigned char *)dst;
	source = (unsigned char *)src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (source < destin)
	{
		while (i++ < len)
			destin[len - i] = source[len - i];
	}
	else
	{
		while (i < len)
		{
			destin[i] = source[i];
			i++;
		}
	}
	return ((void *)destin);
}
