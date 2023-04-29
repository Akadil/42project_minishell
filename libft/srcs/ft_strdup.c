/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:32:22 by akalimol          #+#    #+#             */
/*   Updated: 2022/12/03 12:32:23 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*returner;
	int		i;
	int		s1_size;

	s1_size = (int)ft_strlen(s1);
	returner = (char *) malloc(s1_size + 1);
	if (!returner)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		returner[i] = s1[i];
		i++;
	}
	returner[i] = '\0';
	return (returner);
}
