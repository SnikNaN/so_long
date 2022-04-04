/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <eshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 02:31:04 by eshana            #+#    #+#             */
/*   Updated: 2021/10/05 02:31:04 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	size;
	size_t	i;
	char	*res;

	size = ft_strlen(str);
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
