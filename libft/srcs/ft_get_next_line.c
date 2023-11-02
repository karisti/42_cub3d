/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karisti- <karisti-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:05:51 by karisti-          #+#    #+#             */
/*   Updated: 2021/09/10 18:49:30 by karisti-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	del_buff(char **s)
{
	if (s)
	{
		free(*s);
		*s = NULL;
	}
}

int	get_end_pos(const char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

int	put_line(char **s, char **line)
{
	int		end_pos;
	char	*tmp;

	end_pos = get_end_pos(*s);
	if ((*s)[end_pos] == '\n')
	{
		*line = ft_substr(*s, 0, end_pos);
		tmp = ft_substr(*s, end_pos + 1, ft_strlen(*s));
		free(*s);
		*s = tmp;
		return (1);
	}
	else
	{
		*line = ft_substr(*s, 0, ft_strlen(*s));
		del_buff(s);
		return (0);
	}
}

int	read_line(char **s, int fd, char **line, int retrn)
{
	char	buff[BUFFER_SIZE + 1];
	char	*tmp;

	retrn = read(fd, buff, BUFFER_SIZE);
	while (retrn > 0)
	{
		buff[retrn] = '\0';
		if (!s[fd])
			s[fd] = ft_substr("", 0, 0);
		tmp = ft_strjoin(s[fd], buff);
		free(s[fd]);
		s[fd] = tmp;
		if (ft_strchr(s[fd], '\n'))
			return (put_line(&s[fd], line));
		retrn = read(fd, buff, BUFFER_SIZE);
	}
	if (retrn < 0)
		return (-1);
	else if (retrn == 0 && !s[fd])
	{
		*line = ft_substr("", 0, 0);
		return (0);
	}
	else
		return (put_line(&s[fd], line));
}

int	ft_get_next_line(int fd, char **line)
{
	static char		*saved[4096];
	int				retrn;

	retrn = 0;
	if (fd < 0 || !line)
		return (-1);
	if (saved[fd] && ft_strchr(saved[fd], '\n'))
		return (put_line(&saved[fd], line));
	else
		return (read_line(saved, fd, line, retrn));
}
