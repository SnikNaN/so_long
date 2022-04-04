/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <eshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 14:00:40 by eshana            #+#    #+#             */
/*   Updated: 2021/10/05 06:33:33 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_open(char *filename)
{
	int		fd;
	size_t	len;

	len = ft_strlen(filename);
	if (len < 4 || filename[len - 4] != '.' || filename[len - 3] != 'b'
		|| filename[len - 2] != 'e' || filename[len - 1] != 'r')
	{
		ft_putstr_fd("Error\nMap file must be in *.ber format\n", 2);
		exit(EXIT_FAILURE);
	}
	fd = open(filename, O_DIRECTORY);
	if (fd != -1)
	{
		ft_putstr_fd("Error\nIs a directory\n", 2);
		exit(EXIT_FAILURE);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

int	ft_close(int fd)
{
	int	ctl;

	ctl = close(fd);
	if (ctl == -1)
	{
		ft_putstr_fd("Error\nCan't close file\n", 2);
		return (-1);
	}
	return (0);
}
