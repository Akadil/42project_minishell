/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_upd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:14:48 by akalimol          #+#    #+#             */
/*   Updated: 2023/02/13 19:13:03 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd_upd(char *s, int std)
{
	int	len;

	len = 0;
	if (!s)
		len += ft_putstr_fd_upd("(null)", std);
	else
	{
		while (s[len])
		{
			ft_putchar_fd(s[len], std);
			len++;
		}
	}
	return (len);
}
