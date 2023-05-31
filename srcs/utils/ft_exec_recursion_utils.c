/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_recursion_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:25:22 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/31 19:23:34 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_operator(int exit_code, char *str)
{
	if (ft_strcmp(str, "&&") == 0)
	{
		if (exit_code == 0)
			return (0);
		return (1);
	}
	if (exit_code == 0)
		return (1);
	return (0);
}
