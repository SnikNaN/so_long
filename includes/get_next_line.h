/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshana <eshana@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 03:36:16 by eshana            #+#    #+#             */
/*   Updated: 2021/10/05 03:36:16 by eshana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 1024

int		get_next_line(int fd, char **line);
int		ft_free_gnl(char **s1, char **s2, int ret_value);
size_t	ft_strlen_gnl(const char *s);
void	*ft_calloc_gnl(size_t nmemb, size_t size);
char	*ft_strdup_gnl(const char *str);
char	*ft_substr_gnl(char const *s, unsigned int start, size_t len);
char	*ft_strjoin_gnl(char **s1, char **s2);

#endif
