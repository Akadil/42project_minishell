/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:32:48 by akalimol          #+#    #+#             */
/*   Updated: 2022/12/12 18:03:53 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	if (!src && !dst)
		return (0);
	if (!dst && dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	src_len = 0;
	while (src[src_len])
		src_len++;
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
