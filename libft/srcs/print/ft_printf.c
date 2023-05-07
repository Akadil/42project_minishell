/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:55:57 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/07 16:40:02 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_handle_percent(va_list ptr, char c)
{
	int	size;

	if (c == 'c')
		size = ft_putchar_fd(va_arg(ptr, int), 1);
	else if (c == 's')
		size = ft_putstr_fd(va_arg(ptr, char *), 1);
	else if (c == 'p')
		size = ft_putptr(va_arg(ptr, long unsigned int), 1);
	else if (c == 'd')
		size = ft_putnbr_fd(va_arg(ptr, int), 1);
	else if (c == 'i')
		size = ft_putnbr_fd(va_arg(ptr, int), 1);
	else if (c == 'u')
		size = ft_putunbr(va_arg(ptr, unsigned int), 1);
	else if (c == 'x')
		size = ft_puthex(va_arg(ptr, unsigned int), 'x', 1);
	else if (c == 'X')
		size = ft_puthex(va_arg(ptr, unsigned int), 'X', 1);
	else
		size = ft_putchar_fd('%', 1);
	return (size);
}

int	ft_printf(const char *s, ...)
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
			ft_putchar_fd(s[i], 1);
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
