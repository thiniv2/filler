/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 13:04:42 by thinguye          #+#    #+#             */
/*   Updated: 2021/09/17 13:04:42 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	t;

	i = 0;
	t = 0;
	if (needle[t] == '\0')
		return ((char *)(haystack));
	while (haystack[i])
	{
		t = 0;
		while (haystack[i + t] == needle[t] && ((i + t) < len))
		{
			t++;
			if (needle[t] == '\0')
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
