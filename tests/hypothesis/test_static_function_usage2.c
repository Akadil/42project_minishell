/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_static_function_usage2.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:15:20 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/07 16:19:54 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static void  ft_function(void)
{
    printf("function from port\n");
}

void    ft_port(void)
{
    ft_function();
}