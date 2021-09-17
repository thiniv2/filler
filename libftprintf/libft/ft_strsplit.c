/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 13:04:55 by thinguye          #+#    #+#             */
/*   Updated: 2021/09/17 13:04:55 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(const char *str, int d)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if ((str[i] != d && str[i + 1] == d)
			|| (str[i] != d && str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

char	**ft_strsplit(char const *s, char c)
{
	unsigned int	i;
	size_t			start;
	char			**str;
	int				y;

	y = 0;
	i = 0;
	start = 0;
	if (!s)
		return (NULL);
	str = (char **)ft_memalloc(sizeof(char *) * (ft_count(s, (int)c) + 1));
	while (y < ft_count(s, (int)c))
	{
		while (s[i] == (int)c)
			i++;
		start = i;
		while (s[i] && s[i] != (int)c)
			i++;
		str[y] = ft_strsub(s, start, (i - start));
		i++;
		y++;
	}
	return (str);
}
