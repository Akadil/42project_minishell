/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akadilkalimoldayev <akadilkalimoldayev@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:09:41 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/09 16:48:54 by akadilkalim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_handle_percent(va_list ptr, char c)
{
	int	size;

	if (c == 'c')
		size = ft_putchar_fd(va_arg(ptr, int), 2);
	else if (c == 's')
		size = ft_putstr_fd(va_arg(ptr, char *), 2);
	else if (c == 'p')
		size = ft_putptr(va_arg(ptr, long unsigned int), 2);
	else if (c == 'd')
		size = ft_putnbr_fd(va_arg(ptr, int), 2);
	else if (c == 'i')
		size = ft_putnbr_fd(va_arg(ptr, int), 2);
	else if (c == 'u')
		size = ft_putunbr(va_arg(ptr, unsigned int), 2);
	else if (c == 'x')
		size = ft_puthex(va_arg(ptr, unsigned int), 'x', 2);
	else if (c == 'X')
		size = ft_puthex(va_arg(ptr, unsigned int), 'X', 2);
	else
		size = ft_putchar_fd('%', 2);
	return (size);
}

int	ft_printf2(const char *s, ...)
{
	va_list	ptr;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(ptr, s);
	while (s[i])
	{
		if (s[i] != '%')
		{
			ft_putchar_fd(s[i], 2);
			i++;
			len++;
		}
		else
		{
			len += ft_handle_percent(ptr, s[i + 1]);
			i = i + 2;
		}
	}
	va_end(ptr);
	return (len);
}
