/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 15:40:16 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/13 19:15:57 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putptr_rec(long unsigned int nbr, int std)
{
	int	len;

	len = 0;
	if (nbr > 15)
	{
		len += ft_putptr_rec(nbr / 16, std);
		len += ft_putptr_rec(nbr % 16, std);
	}
	else
	{
		len += ft_putchar_fd_upd("0123456789abcdef"[nbr % 16], std);
	}
	return (len);
}

int	ft_putptr(long unsigned int nbr, int std)
{
	int	len;

	len = 0;
	if (nbr == 0)
		len += ft_putstr_fd_upd("(nil)", std);
	else
	{
		len += ft_putstr_fd_upd("0x", std);
		len += ft_putptr_rec(nbr, std);
	}
	return (len);
}
