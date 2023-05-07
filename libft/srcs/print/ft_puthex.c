/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:04:38 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/07 16:44:42 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_transformer(unsigned int nbr, char *base, int fd)
{
	static int	size;

	if (nbr > 15)
	{
		ft_transformer(nbr / 16, base, fd);
		ft_transformer(nbr % 16, base, fd);
	}
	else
	{
		size++;
		ft_putchar_fd(base[nbr % 16], fd);
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
