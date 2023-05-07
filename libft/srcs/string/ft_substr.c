/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:34:09 by akalimol          #+#    #+#             */
/*   Updated: 2022/12/10 13:12:55 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*returner;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		returner = (char *) malloc(sizeof(char) * (1));
	else if (s_len - start > len)
		returner = (char *) malloc(sizeof(char) * (len + 1));
	else
		returner = (char *) malloc(sizeof(char) * (s_len - start + 1));
	if (!returner)
		return (NULL);
	i = 0;
	while (i + start < s_len && s[i + start] && i < len)
	{
		returner[i] = s[start + i];
		i++;
	}
	returner[i] = '\0';
	return (returner);
}
