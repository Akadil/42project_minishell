/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdigit_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:31:23 by akalimol          #+#    #+#             */
/*   Updated: 2022/12/03 12:31:24 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putdigit_fd(int n, int fd)
{
	char	c;

	c = n + 48;
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb < 0 && nb != -2147483648)
	{
		write(fd, "-", 1);
		nb *= -1;
	}
	if (nb == -2147483648)
		write (fd, "-2147483648", 11);
	else if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
	else
		ft_putdigit_fd(nb, fd);
}
