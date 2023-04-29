/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_stderror.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:09:41 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/13 19:26:41 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_handle_percent(va_list ptr, char c)
{
	int	ret;

	if (c == 'c')
		ret = ft_putchar_fd_upd(va_arg(ptr, int), 2);
	else if (c == 's')
		ret = ft_putstr_fd_upd(va_arg(ptr, char *), 2);
	else if (c == 'p')
		ret = ft_putptr(va_arg(ptr, long unsigned int), 2);
	else if (c == 'd')
		ret = ft_putnbr_fd_upd(va_arg(ptr, int), 2);
	else if (c == 'i')
		ret = ft_putnbr_fd_upd(va_arg(ptr, int), 2);
	else if (c == 'u')
		ret = ft_putunbr(va_arg(ptr, unsigned int), 2);
	else if (c == 'x')
		ret = ft_puthex(va_arg(ptr, unsigned int), 'x', 2);
	else if (c == 'X')
		ret = ft_puthex(va_arg(ptr, unsigned int), 'X', 2);
	else
		ret = ft_putchar_fd_upd('%', 2);
	return (ret);
}

int	ft_printf_stderr(const char *s, ...)
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
