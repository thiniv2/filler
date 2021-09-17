/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 13:05:07 by thinguye          #+#    #+#             */
/*   Updated: 2021/09/17 13:05:07 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	size_t			i;
	unsigned int	index;

	if (!s)
		return (NULL);
	sub = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	index = 0;
	if (!sub || start > ft_strlen(s))
		return (NULL);
	while (s[start] != '\0' && i < len)
	{
		sub[index] = s[start];
		index++;
		start++;
		i++;
	}
	sub[index] = '\0';
	return (sub);
}
