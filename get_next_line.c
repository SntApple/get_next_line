/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_get_next_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flurk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:24:00 by flurk             #+#    #+#             */
/*   Updated: 2020/12/03 19:25:05 by flurk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		has_nl(const char *buf)
{
	size_t	i;

	i = 0;
	while (buf[i])
		if (buf[i++] == '\n')
			return (1);
	return (0);
}

char	*get_str(char **line, char *buf, ssize_t rc)
{
	size_t	len;
	char	*ans;
	size_t	i;

	len = 0;
	i = 0;
	while (buf[i++] != '\n')
		len++;
	ans = ft_strjoin(*line, buf, len);
	if (!ans)
		return (0);
	if (rc == 0)
		rc = ft_strlen(buf);
	ft_memmove(buf, buf + len + 1, rc - len - 1);
	buf[rc - len - 1] = '\0';
	return (ans);
}

char	*get_buf(ssize_t *rc, int fd, int *q)
{
	char	*new_buf;

	new_buf = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!new_buf)
		return (0);
	*rc = read(fd, new_buf, BUFFER_SIZE);
	if (*rc < 0)
		return (0);
	if (*rc == 0)
		*q = 0;
	new_buf[*rc] = '\0';
	return (new_buf);
}

int		get_line(char **line, char **buf, ssize_t rc, int fd)
{
	int q;

	q = 1;
	while (!has_nl(*buf))
	{
		*line = ft_strjoin(*line, *buf, ft_strlen(*buf));
		if (*buf)
		{
			free(*buf);
			*buf = NULL;
		}
		if (!*line)
			return (-1);
		*buf = get_buf(&rc, fd, &q);
		if (!*buf || rc < 0)
			return (-1);
		if (!q)
		{
			free(*buf);
			*buf = NULL;
			return (0);
		}
	}
	*line = get_str(line, *buf, rc);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*buf;
	ssize_t		rc;
	int			q;
	int			ans;

	if (fd < 0 || BUFFER_SIZE < 1 || !line || (read(fd, 0, 0) == -1))
		return (-1);
	*line = (char*)malloc(1);
	*line[0] = '\0';
	rc = 0;
	q = 1;
	if (!buf)
		buf = get_buf(&rc, fd, &q);
	if (!buf || rc < 0)
		return (-1);
	ans = get_line(line, &buf, rc, fd);
	if (ans == -1)
		return (-1);
	if (!ans)
		return (0);
	if (!*line)
		return (-1);
	return (1);
}
