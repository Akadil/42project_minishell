/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:34:00 by akalimol          #+#    #+#             */
/*   Updated: 2022/12/12 12:55:08 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_in(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_beg(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] && ft_in(s1[i], set) == 1)
		i++;
	return (i);
}

static int	ft_end(char const *s1, char const *set, int beg)
{
	int	i;

	i = (int)ft_strlen(s1) - 1;
	if (i == beg)
		return (beg - 1);
	while (beg < i && s1[i] && ft_in(s1[i], set) == 1)
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*returner;
	int		i;
	int		beg;
	int		end;

	if (!s1)
		return (NULL);
	beg = ft_beg(s1, set);
	end = ft_end(s1, set, beg);
	returner = (char *) malloc(end - beg + 1 + 1);
	if (!returner)
		return (NULL);
	i = beg;
	while (i <= end)
	{
		returner[i - beg] = s1[i];
		i++;
	}
	returner[i - beg] = '\0';
	return (returner);
}
