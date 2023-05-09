/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akadilkalimoldayev <akadilkalimoldayev@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:31:30 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/09 16:47:31 by akadilkalim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putendl_fd(char *s, int fd)
{
	int	size;

	size = 0;
	if (s)
	{
		size += ft_putstr_fd(s, fd);
		size += ft_putchar_fd('\n', fd);
	}
	return (size);
}
