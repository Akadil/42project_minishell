/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akadilkalimoldayev <akadilkalimoldayev@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:31:23 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/09 16:38:36 by akadilkalim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_putdigit_fd(int n, int fd)
{
	char	c;

	c = n + 48;
	return (write(fd, &c, 1));
}

int	ft_putnbr_fd(int nb, int fd)
{
	int	size;

	size = 0;
	if (nb < 0 && nb != -2147483648)
	{
		size += write(fd, "-", 1);
		nb *= -1;
	}
	if (nb == -2147483648)
		size = write (fd, "-2147483648", 11);
	else if (nb > 9)
	{
		size += ft_putnbr_fd(nb / 10, fd);
		size += ft_putnbr_fd(nb % 10, fd);
	}
	else
	{
		size += ft_putdigit_fd(nb, fd);
	}
	return (size);
}
