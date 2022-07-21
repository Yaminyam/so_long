/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikang <sikang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 19:01:04 by sikang            #+#    #+#             */
/*   Updated: 2022/07/21 09:34:29 by sikang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*split_line(char **store)
{
	char	*split_str;
	char	*cut;
	char	*temp;
	size_t	n;

	if (**store == 0 || *store == 0)
		return (NULL);
	cut = ft_strchr(*store, '\n');
	if (cut == 0)
		cut = ft_strchr(*store, 0);
	n = cut - *store + 1;
	split_str = ft_strndup(*store, n);
	if (split_str == 0)
		return (NULL);
	temp = ft_strndup(cut + 1, ft_strlen(cut + 1));
	if (temp == 0)
	{
		free(split_str);
		return (NULL);
	}
	free(*store);
	*store = temp;
	return (split_str);
}

char	*get_next_line(int fd)
{
	static char	*store[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	ssize_t		read_size;
	char		*temp;

	if (read(fd, buf, 0) == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	if (store[fd] == 0)
		store[fd] = ft_strndup("", 0);
	if (ft_strchr(store[fd], '\n'))
		return (split_line(&store[fd]));
	read_size = read(fd, buf, BUFFER_SIZE);
	while (read_size > 0)
	{
		buf[read_size] = 0;
		store[fd] = ft_strjoin_gnl(store[fd], buf);
		if (ft_strchr(store[fd], '\n'))
			return (split_line(&store[fd]));
		read_size = read(fd, buf, BUFFER_SIZE);
	}
	temp = split_line(&store[fd]);
	free(store[fd]);
	store[fd] = 0;
	return (temp);
}
