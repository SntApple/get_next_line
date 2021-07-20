/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flurk <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 11:15:06 by flurk             #+#    #+#             */
/*   Updated: 2021/01/10 11:15:08 by flurk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	char		*dd;
	const char	*ss;

	if (!dst && !src)
		return (0);
	d = dst;
	s = src;
	if (d < s)
		while (len-- && *s)
			*d++ = *s++;
	else
	{
		ss = s + (len - 1);
		dd = d + (len - 1);
		while (len-- && *ss)
			*dd-- = *ss--;
	}
	return (dst);
}

char	*ft_strjoin(char *s1, const char *s2, size_t len)
{
	size_t	size;
	char	*p;
	char	*d;
	char	*str;

	if (!s2)
		return (0);
	size = ft_strlen(s1);
	size += len;
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (0);
	p = (char*)s1;
	d = (char*)str;
	while (*p)
		*d++ = *p++;
	p = (char*)s2;
	while (len--)
		*d++ = *p++;
	*d = '\0';
	free(s1);
	return (str);
}

void	ft_bzero(void *s, size_t n)
{
	char *p;

	p = (char*)s;
	while (n--)
		*p++ = '\0';
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char *ans;

	ans = (void*)malloc(nmemb * size + 1);
	ft_bzero(ans, nmemb * size + 1);
	return (ans);
}
