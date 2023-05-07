/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_static_function_usage.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:15:06 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/07 16:20:37 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
    Hypothesis:     Can I use the same name of the functions in different 
                    files, if the functions are static

    Result:         Yes, it is possible

    Tester:         cc -Wall -Wextra -Werror test_static_function_usage2.c test_static_function_usage.c && ./a.out && rm a.out
*/

static void ft_function(void)
{
    printf("function from main\n");
}

void    ft_port(void);

int main(void)
{
    ft_function();
    ft_port();
    return (0);
}