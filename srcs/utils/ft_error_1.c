/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:30:15 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/16 17:40:26 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"

void	ft_error(void)
{
	ft_printf2("%s\n", strerror(errno));
}

void	ft_perror(char *str)
{
	perror(str);
}

void	ft_merror(char *str, char *param)
{
	ft_printf2(str, param);
}