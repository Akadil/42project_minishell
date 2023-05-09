/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akadilkalimoldayev <akadilkalimoldayev@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:34:22 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/09 16:40:04 by akadilkalim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putdigit(int n, int fd)
{
	char	c;

	c = n + 48;
	return (write(fd, &c, 1));
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
		len += ft_putdigit(nbr, fd);
	return (len);
}
