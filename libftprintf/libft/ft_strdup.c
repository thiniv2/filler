/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 13:03:14 by thinguye          #+#    #+#             */
/*   Updated: 2021/09/17 13:03:14 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		c;
	char	*dst;

	i = 0;
	c = 0;
	while (s1[i])
		i++;
	dst = (char *)ft_memalloc(sizeof(*dst) * (i + 1));
	if (!dst)
		return (NULL);
	while (c < i)
	{
		dst[c] = s1[c];
		c++;
	}
	dst[c] = '\0';
	return (dst);
}
