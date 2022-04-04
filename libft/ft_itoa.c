/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <eshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 02:27:10 by eshana            #+#    #+#             */
/*   Updated: 2021/10/05 02:27:10 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_digits(int n)
{
	if (n < 10 && n > -10)
		return (1);
	else
		return (1 + ft_count_digits(n / 10));
}

static int	ft_abs(int n)
{
	if (n >= 0)
		return (n);
	return (-n);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		sgn;
	size_t	size;

	sgn = 0;
	size = ft_count_digits(n);
	if (n < 0)
		sgn = 1;
	str = (char *)ft_calloc(size + sgn + 1, sizeof(char));
	if (str)
	{
		if (sgn)
			str[0] = '-';
		if (n == 0)
			str[0] = '0';
		while (n)
		{
			str[sgn + size - 1] = '0' + ft_abs(n % 10);
			size--;
			n /= 10;
		}
	}
	return (str);
}
