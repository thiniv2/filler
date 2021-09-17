/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 13:03:36 by thinguye          #+#    #+#             */
/*   Updated: 2021/09/17 13:03:36 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		a;
	int		b;
	int		x;
	char	*joint;

	if (!s1 || !s2)
		return (NULL);
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	x = 0;
	joint = ft_strnew(a + b);
	joint = ft_strcpy(joint, s1);
	while (x < b)
	{
		joint[a + x] = s2[x];
		x++;
	}
	return (joint);
}
