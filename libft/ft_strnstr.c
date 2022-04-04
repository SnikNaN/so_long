/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <eshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 02:32:15 by eshana            #+#    #+#             */
/*   Updated: 2021/10/05 02:32:15 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!(s2[i]))
		return ((char *)s1);
	while (s1[i] && (i < n))
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			while (s1[i + j] && ((i + j) < n) && (s1[i + j] == s2[j]) && s2[j])
				j++;
			if (s2[j] == '\0')
				return ((char *)s1 + i);
		}
		i++;
	}
	return (NULL);
}
