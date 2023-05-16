/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_if_cond.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:22:37 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/16 13:36:10 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
    To see how does if (c++) works

    Result:
        I have to specify some 100% condition, like a = 0; if (a++ > -2147483648)
*/

int main(void)
{
    int a;

    a = 0;
    if (a++ > -1)
        printf("I was here");
    else
        printf("I wasn't here");
    return (0);
}