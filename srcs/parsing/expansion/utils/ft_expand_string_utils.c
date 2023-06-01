/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_string_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:49:36 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/01 18:05:51 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strchr_alt(const char *s, int c)
{
	int		i;
	char	mode;

	mode = '\0';
	i = 0;
	if (c < 0)
		return (NULL);
	while (s[i])
	{
		if (mode == 0 && s[i] == '\'')
			mode = '\'';
		else if (mode == '\'' && s[i] == '\'')
			mode = '\0';
		else if (mode == 0 && s[i] == '\"')
			mode = '\"';
		else if (mode == '\"' && s[i] == '\"')
			mode = '\0';
		else if (mode == '\0' || mode == '\"')
			if (s[i] == c % 256 && (ft_isalnum(s[i + 1]) || s[i + 1] == '?'))
				return ((char *)(s + i));
		i++;
	}
	if (c == 0)
		return ((char *)(s + i));
	return (NULL);
}

static int	ft_strlen_alt(const char *str)
{
	char	mode;
	int		size;
	int		i;

	size = 0;
	mode = '\0';
	i = 0;
	while (str[i])
	{
		if (mode == 0 && str[i] == '\'')
			mode = '\'';
		else if (mode == '\'' && str[i] == '\'')
			mode = '\0';
		else if (mode == 0 && str[i] == '\"')
			mode = '\"';
		else if (mode == '\"' && str[i] == '\"')
			mode = '\0';
		else if (str[i] == '$' && (mode == '\0' || mode == '\"'))
			break ;
		size++;
		i++;
	}
	return (size);
}

int	ft_strlcat_alt(char *dst, const char *src, int dstsize)
{
	int	src_len;
	int	dst_len;
	int	i;

	if (!src && !dst)
		return (0);
	if (!dst && dstsize == 0)
		return (ft_strlen_alt(src));
	i = 0;
	src_len = ft_strlen_alt(src);
	dst_len = ft_strlen(dst);
	if (dst_len > dstsize)
		return (src_len + dstsize);
	while (dst_len + i + 1 < dstsize && i < src_len)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dstsize != 0)
		dst[dst_len + i] = '\0';
	return (src_len + dst_len);
}
