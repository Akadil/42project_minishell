/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:31:41 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/07 16:13:44 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	size;

	if (!s)
	{
		size = ft_putstr_fd("(null)", fd);
	}
	else
	{
		size = 0;
		while (s[size])
		{
			ft_putchar_fd(s[size], fd);
			size++;
		}
	}
	return (size);
}
