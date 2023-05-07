/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_static_var_in_recursion.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:22:06 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/07 16:29:05 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
    Hypothesis:     Does static variable works inside of the recursive function
                    and is it shares the common memory space?

    Result:         Yes, fucking working!

    Tester:         cc -Wall -Wextra -Werror test_static_var_in_recursion.c && ./a.out && rm a.out
*/

void    ft_recursion(int num)
{
    static int  a;

    a++;
    if (num > 0)
        ft_recursion(num - 1);
    else
        printf("The number is %d\n", a);
}

int main(void)
{
    ft_recursion(3);
    return (0);
}