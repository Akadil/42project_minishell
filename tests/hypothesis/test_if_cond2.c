/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_if_cond2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 17:24:45 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/25 17:28:59 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
    Hypothesis:     If function returns some number, can I put "!"?

    Results:         With "!" condition, it will enter, only if 0 was returned 
*/

int ft_function(void)
{
    return (6);
}

int main(void)
{
    if (!ft_function())
        printf("I was here\n");
    else
        printf("I wasn't here\n");

    return (0);
}