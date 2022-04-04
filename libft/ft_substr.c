/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <eshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 02:32:38 by eshana            #+#    #+#             */
/*   Updated: 2021/10/05 02:32:38 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	res = (char *)ft_calloc(ft_min(ft_strlen(s) - start, len) + 1,
			sizeof(char));
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
