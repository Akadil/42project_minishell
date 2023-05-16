/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_return.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:39:54 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/16 16:42:52 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
    If I declare the variable in the return statement, what will be returned?

    Result: The value that inside
*/

int ft_function(int b)
{
    int a;

    a = 2;
    return (a = a * b);
}

int main(void)
{
    printf("The number is %d", ft_function(7));
    return (0);
}