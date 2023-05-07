/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:33:41 by akalimol          #+#    #+#             */
/*   Updated: 2022/12/04 16:20:50 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	if (c < 0)
		return (NULL);
	i = ft_strlen(s) - 1;
	if (c == 0)
		return ((char *)(s + i + 1));
	while (i != -1)
	{
		if (s[i] == c % 256)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}
