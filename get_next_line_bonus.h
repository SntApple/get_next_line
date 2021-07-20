/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flurk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 11:14:10 by flurk             #+#    #+#             */
/*   Updated: 2021/01/10 11:14:21 by flurk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

int		get_next_line(int fd, char **line);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	ft_bzero(void *s, size_t n);
char	*ft_strjoin(char *s1, const char *s2, size_t len);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
#endif
