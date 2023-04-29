/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:31:00 by akalimol          #+#    #+#             */
/*   Updated: 2022/12/11 18:55:26 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*my_dst;
	char	*my_src;
	size_t	i;

	i = len;
	my_dst = (char *)dst;
	my_src = (char *)src;
	if (my_dst == my_src)
		return (my_dst);
	else if (my_dst > my_src)
	{
		while (i-- > 0)
			my_dst[i] = my_src[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			my_dst[i] = my_src[i];
			i++;
		}
	}
	return (my_dst);
}
