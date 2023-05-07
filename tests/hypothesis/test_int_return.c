/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_int_return.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:05:57 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/07 16:15:51 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/*
    Hypothesis:     If I am returning something from the function, do I have 
                    to catch it?

    Results:        It is not mandatory

    Tester:         cc -Wall -Wextra -Werror test_int_return.c && ./a.out && rm a.out
*/

char  *ft_function(void)
{
    char *str;

    str = malloc(1);
    printf("My name is Akadil!\n");
    return (str);
}

int main(void)
{
    ft_function();
    return (0);
}