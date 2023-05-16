/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_passed_function.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:05:55 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/16 17:12:17 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/*
    How do I have to pass the free function

    Result:     &free
*/

void    ft_function(int size, void (*del)(void*))
{
    char *str;

    str = malloc(size);
    (*del)(str);
}

int main(void)
{
    ft_function(6, &free);
    return (0);
}