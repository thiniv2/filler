/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thinguye <thinguye@student.42.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:12:28 by thinguye          #+#    #+#             */
/*   Updated: 2021/09/17 12:48:40 by thinguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int	ft_new_line(int fd, char **line, char **str)
{
	int		len;
	char	*tmp;

	len = 0;
	while (str[fd][len] != '\n' && str[fd][len] != '\0')
		len++;
	if (str[fd][len] == '\n')
	{
		*line = ft_strsub(str[fd], 0, len);
		tmp = ft_strdup(str[fd] + len + 1);
		free(str[fd]);
		str[fd] = tmp;
	}
	else if (str[fd][len] == '\0')
	{
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	int				ret;
	static char		*str[MAX_FD];
	char			*ptr;
	char			buf[BUFF_SIZE + 1];

	if (fd < 0 || line == NULL || BUFF_SIZE < 1 || fd > MAX_FD)
		return (-1);
	if (str[fd] == NULL)
		str[fd] = ft_strnew(0);
	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		ptr = ft_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = ptr;
		if (ft_strchr(str[fd], '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (str[fd][0] == '\0'))
		return (0);
	return (ft_new_line(fd, line, str));
}
