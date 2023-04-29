/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:33:12 by akalimol          #+#    #+#             */
/*   Updated: 2022/12/12 12:55:33 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*returner;
	int		len;
	int		i;

	if (!s)
		return (NULL);
	len = (int) ft_strlen(s);
	returner = (char *) malloc(sizeof(char) * (len + 1));
	if (!returner)
		return (NULL);
	i = 0;
	while (i < len)
	{
		returner[i] = (*f)(i, s[i]);
		i++;
	}
	returner[i] = '\0';
	return (returner);
}
