/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 13:05:01 by thinguye          #+#    #+#             */
/*   Updated: 2021/09/17 13:05:01 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	t;

	i = 0;
	t = 0;
	if (needle[t] == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		t = 0;
		while (haystack[i + t] == needle[t])
		{
			t++;
			if (needle[t] == '\0')
				return ((char *)haystack + (i));
		}
		i++;
	}
	return (NULL);
}
