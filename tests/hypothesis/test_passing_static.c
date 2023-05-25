/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_passing_static.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:49:15 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/25 15:56:09 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
    Hypothesis:     If I create an array in stack, how can I manipulate it?

    Results:        ft_function() doesn't work, second one is working
*/

int *ft_function(void)
{
    int arr[2];

    arr[0] = 0;
    arr[1] = 1;

    return (0);
    //return (arr);
}

void    ft_function2(int arr[2])
{
    arr[0] = 0;
    arr[1] = 1;
}

int main(void)
{
    int arr[2];

    ft_function2(arr);
    printf("%d and %d", arr[0], arr[1]);

    return (0);
}