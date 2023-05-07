/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:27:28 by akalimol          #+#    #+#             */
/*   Updated: 2022/12/12 13:27:15 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_skip_isspace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '\f' || str[i] == '\n')
		{
			i++;
			continue ;
		}
		if (str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		{
			i++;
			continue ;
		}
		break ;
	}
	return (i);
}

static int	ft_check_the_sign(const char *str, int *pos)
{
	int	sign;

	if (!str[*pos])
		sign = 1;
	else if (str[*pos] == '-')
	{
		*pos = *pos + 1;
		sign = -1;
	}
	else if (str[*pos] == '+')
	{
		*pos = *pos + 1;
		sign = 1;
	}
	else
		sign = 1;
	return (sign);
}

int	ft_atoi(const char *str)
{
	size_t	returner;
	int		i;
	int		sign;

	i = ft_skip_isspace(str);
	sign = ft_check_the_sign(str, &i);
	returner = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		returner = returner * 10 + str[i] - 48;
		i++;
	}
	return ((int)returner * sign);
}
