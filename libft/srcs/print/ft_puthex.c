/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akadilkalimoldayev <akadilkalimoldayev@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:04:38 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/09 16:36:51 by akadilkalim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_transformer(unsigned int nbr, char *base, int fd)
{
	int	size;

	size = 0;
	if (nbr > 15)
	{
		size += ft_transformer(nbr / 16, base, fd);
		size += ft_transformer(nbr % 16, base, fd);
	}
	else
	{
		size += ft_putchar_fd(base[nbr % 16], fd);
	}
	return (size);
}

int	ft_puthex(unsigned int nbr, char c, int fd)
{
	int	size;

	if (c == 'x')
		size = ft_transformer(nbr, "0123456789abcdef", fd);
	else
		size = ft_transformer(nbr, "0123456789ABCDEF", fd);
	return (size);
}
