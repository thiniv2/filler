/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 13:05:13 by thinguye          #+#    #+#             */
/*   Updated: 2021/09/17 13:05:13 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_iswhtspc(int c)
{
	if (c == 9 || c == 10 || c == 32)
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s)
{
	int		i;
	int		end;
	char	*trim;

	if (!s)
		return (NULL);
	i = (int)(ft_strlen(s) - 1);
	while (ft_iswhtspc(s[i]))
		i--;
	end = i + 1;
	if (end == 0)
	{
		trim = ft_strnew((size_t)end);
		return (trim);
	}
	i = 0;
	while (ft_iswhtspc(s[i]))
		i++;
	trim = ft_strsub(s, i, (size_t)(end - i));
	return (trim);
}
