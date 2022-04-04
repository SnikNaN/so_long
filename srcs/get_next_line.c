/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <eshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 16:02:37 by eshana            #+#    #+#             */
/*   Updated: 2021/10/05 02:23:59 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_prcs_rest(char **rest, char **new_line)
{
	size_t	i;
	char	*new_rest;

	if (!new_line || !(*rest))
		return (-1);
	i = 0;
	while (*rest && (*rest)[i])
	{
		if ((*rest)[i] == '\n')
		{
			*new_line = ft_substr_gnl(*rest, 0, i);
			if (!(*new_line))
				return (-1);
			new_rest = ft_substr_gnl(*rest, i + 1, ft_strlen_gnl(*rest) - i);
			if (!new_rest)
				return (-1);
			free(*rest);
			*rest = new_rest;
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_free_gnl(char **s1, char **s2, int ret_value)
{
	if (s1 && *s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (s2 && *s2)
	{
		free(*s2);
		*s2 = NULL;
	}
	return (ret_value);
}

int	get_next_line(int fd, char **line)
{
	static char	*rest;
	char		*buf;
	ssize_t		cnt;

	if ((read(fd, 0, 0) < 0) || !line)
		return (ft_free_gnl(&rest, NULL, -1));
	cnt = 1;
	while (cnt > 0)
	{
		if (rest)
			cnt = ft_prcs_rest(&rest, line);
		if (cnt == -1)
			return (ft_free_gnl(&rest, &buf, -1));
		if (rest && cnt)
			return (1);
		buf = ft_calloc_gnl(BUFFER_SIZE + 1, sizeof(char));
		if (!buf)
			return (ft_free_gnl(&rest, NULL, -1));
		cnt = read(fd, buf, BUFFER_SIZE);
		rest = ft_strjoin_gnl(&rest, &buf);
		if (!rest || cnt < 0)
			return (ft_free_gnl(&rest, &buf, -1));
	}
	*line = ft_strdup_gnl(rest);
	return (ft_free_gnl(&rest, &buf, ft_prcs_rest(line, line)));
}
