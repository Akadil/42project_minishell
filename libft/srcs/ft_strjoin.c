/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:32:40 by akalimol          #+#    #+#             */
/*   Updated: 2022/12/12 13:27:49 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*returner;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	if (!s1 || !s2)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	returner = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!returner)
		return (0);
	i = 0;
	while (i < s1_len + s2_len)
	{
		if (i < s1_len)
			returner[i] = s1[i];
		else
			returner[i] = s2[i - s1_len];
		i++;
	}
	returner[i] = '\0';
	return (returner);
}
