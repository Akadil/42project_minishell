/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:34:22 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/13 19:14:30 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putdigit(int n, int std)
{
	char	c;

	c = n + 48;
	write(std, &c, 1);
}

int	ft_putunbr(unsigned int nbr, int std)
{
	int	len;

	len = 0;
	if (nbr > 9)
	{
		len += ft_putunbr(nbr / 10, std);
		len += ft_putunbr(nbr % 10, std);
	}
	else
	{
		ft_putdigit(nbr, std);
		len++;
	}
	return (len);
}
