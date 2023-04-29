/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:30:51 by akalimol          #+#    #+#             */
/*   Updated: 2022/12/03 12:36:12 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char	*buffer_dst;
	char	*buffer_src;
	size_t	i;

	i = 0;
	buffer_dst = dst;
	buffer_src = (char *) src;
	while (i < n && (dst || src))
	{
		buffer_dst[i] = buffer_src[i];
		i++;
	}
	return (dst);
}
