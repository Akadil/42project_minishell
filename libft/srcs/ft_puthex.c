/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:04:38 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/13 19:21:31 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_transformer(unsigned int nbr, char *base, int *len, int std)
{
	if (nbr > 15)
	{
		ft_transformer(nbr / 16, base, len, std);
		ft_transformer(nbr % 16, base, len, std);
	}
	else
	{
		*len = *len + 1;
		ft_putchar_fd_upd(base[nbr % 16], std);
	}
}

int	ft_puthex(unsigned int nbr, char c, int std)
{
	int	len;

	len = 0;
	if (c == 'x')
		ft_transformer(nbr, "0123456789abcdef", &len, std);
	else
		ft_transformer(nbr, "0123456789ABCDEF", &len, std);
	return (len);
}
