/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <eshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 02:30:47 by eshana            #+#    #+#             */
/*   Updated: 2021/10/05 02:30:47 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	size;

	size = 0;
	while (*s)
	{
		if (c == *s)
			s++;
		else
		{
			size++;
			while (*s && (*s != c))
				s++;
		}
	}
	return (size);
}

static unsigned int	ft_next_word(char const *s, char c, unsigned int last)
{
	unsigned int	i;

	i = last;
	if (!last)
	{
		while (s[i] == c)
			i++;
		return (i);
	}
	while (s[i])
	{
		while (s[i] && (s[i] != c))
			i++;
		while (s[i] == c)
			i++;
		return (i);
	}
	return (i);
}

static size_t	ft_word_len(char const *s, char c, unsigned int word)
{
	size_t	len;

	len = 0;
	while (s[word] && (s[word] != c))
	{
		len++;
		word++;
	}	
	return (len);
}

static char	**ft_free_on_error(char **s)
{
	size_t	i;

	if (s)
	{
		i = 0;
		while (s[i])
		{
			free(s[i]);
			i++;
		}
		free(s);
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char			**res;
	size_t			i;
	size_t			size;
	unsigned int	word;

	if (!s)
		return (NULL);
	size = ft_count_words(s, c);
	res = (char **)ft_calloc(size + 1, sizeof(char *));
	if (res && size)
	{
		i = 0;
		word = 0;
		while (i < size)
		{
			word = ft_next_word(s, c, word);
			res[i] = ft_substr(s, word, ft_word_len(s, c, word));
			if (!(res[i]))
				return (ft_free_on_error(res));
			i++;
			word++;
		}
	}
	return (res);
}
