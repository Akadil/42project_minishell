/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:30:27 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/31 19:23:40 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_clean.h"
#include "ft_error.h"

void	ft_error_exit(int exit_code)
{
	ft_error();
	exit(exit_code);
}

void	ft_perror_exit(char *str, int exit_code)
{
	ft_perror(str);
	exit(exit_code);
}

void	ft_merror_exit(char *str, char *param, int exit_code)
{
	ft_merror(str, param);
	exit(exit_code);
}
