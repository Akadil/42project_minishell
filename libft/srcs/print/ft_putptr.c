/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:40:16 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/07 16:46:59 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*





						The problem could be in a repetitive calls for different purpsese!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1












*/
static int	ft_putptr_rec(long unsigned int nbr, int fd)
{
	int	len;

	len = 0;
	if (nbr > 15)
	{
		len += ft_putptr_rec(nbr / 16, fd);
		len += ft_putptr_rec(nbr % 16, fd);
	}
	else
	{
		len += ft_putchar_fd_upd("0123456789abcdef"[nbr % 16], fd);
	}
	return (len);
}

int	ft_putptr(long unsigned int nbr, int fd)
{
	int	len;

	len = 0;
	if (nbr == 0)
		len += ft_putstr_fd("(nil)", fd);
	else
	{
		len += ft_putstr_fd("0x", fd);
		len += ft_putptr_rec(nbr, fd);
	}
	return (len);
}
