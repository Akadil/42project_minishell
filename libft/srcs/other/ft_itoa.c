/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:28:40 by akalimol          #+#    #+#             */
/*   Updated: 2022/12/10 19:24:31 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_size(int n)
{
	int	returner;

	if (n == 0)
		return (1);
	returner = 0;
	while (n != 0)
	{
		n = n / 10;
		returner++;
	}
	return (returner);
}

static int	ft_check_negativity(int n)
{
	int	returner;

	if (n < 0)
		returner = 1;
	else
		returner = 0;
	return (returner);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	else
		return (n);
}

char	*ft_itoa(int n)
{
	char	*returner;
	int		size;
	int		i;
	int		minus_check;
	int		i_am_super_lazy;

	size = ft_get_size(n);
	minus_check = ft_check_negativity(n);
	returner = malloc(size + minus_check + 1);
	if (!returner)
		return (NULL);
	i = size + minus_check - 1;
	i_am_super_lazy = 0;
	while (n != 0 || i_am_super_lazy == 0)
	{
		returner[i--] = (char)(ft_abs(n % 10) + 48);
		i_am_super_lazy = 1;
		n = n / 10;
	}
	if (minus_check == 1)
		returner[0] = '-';
	returner[size + minus_check] = '\0';
	return (returner);
}
