/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:34:22 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/07 16:40:38 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putdigit(int n, int fd)
{
	char	c;

	c = n + 48;
	write(fd, &c, 1);
}

int	ft_putunbr(unsigned int nbr, int fd)
{
	int	len;

	len = 0;
	if (nbr > 9)
	{
		len += ft_putunbr(nbr / 10, fd);
		len += ft_putunbr(nbr % 10, fd);
	}
	else
	{
		ft_putdigit(nbr, fd);
		len++;
	}
	return (len);
}
