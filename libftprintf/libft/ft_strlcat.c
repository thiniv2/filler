/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 13:03:41 by thinguye          #+#    #+#             */
/*   Updated: 2021/09/17 13:03:41 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dlen;
	size_t	slen;
	size_t	x;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	x = 0;
	if (dstsize <= dlen)
		return (dstsize + slen);
	while (src[x] != '\0' && x < dstsize - dlen - 1)
	{
		dst[dlen + x] = src[x];
		x++;
	}
	dst[dlen + x] = '\0';
	return (dlen + slen);
}
