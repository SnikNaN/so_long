/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <eshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 16:02:18 by eshana            #+#    #+#             */
/*   Updated: 2021/09/25 16:02:18 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc_gnl(size_t nmemb, size_t size)
{
	void	*res;
	size_t	i;

	res = malloc(nmemb * size);
	if (res)
	{
		i = 0;
		while (i < (nmemb * size))
		{
			((char *)res)[i] = '\0';
			i++;
		}
	}
	return (res);
}

char	*ft_strdup_gnl(const char *str)
{
	size_t	size;
	size_t	i;
	char	*res;

	size = ft_strlen_gnl(str);
	i = 0;
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (res)
	{
		while (str[i])
		{
			res[i] = str[i];
			i++;
		}
		res[i] = '\0';
	}
	return (res);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen_gnl(s))
		return (ft_strdup_gnl(""));
	if (len < (ft_strlen_gnl(s) - start))
		res = (char *)ft_calloc_gnl(len + 1, sizeof(char));
	else
		res = (char *)ft_calloc_gnl(ft_strlen_gnl(s) - start + 1, sizeof(char));
	if (res)
	{
		i = 0;
		while (i < len && s[start + i])
		{
			res[i] = s[start + i];
			i++;
		}
	}
	return (res);
}

char	*ft_strjoin_gnl(char **s1, char **s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	res = (char *)ft_calloc_gnl(ft_strlen_gnl(*s1)
			+ ft_strlen_gnl(*s2) + 1, sizeof(char));
	if (res)
	{
		i = 0;
		while (*s1 && (*s1)[i])
		{
			res[i] = (*s1)[i];
			i++;
		}
		j = 0;
		while (*s2 && (*s2)[j])
		{
			res[i + j] = (*s2)[j];
			j++;
		}
	}
	ft_free_gnl(s1, s2, 1);
	return (res);
}
