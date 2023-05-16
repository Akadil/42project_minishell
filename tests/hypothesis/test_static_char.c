/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_static_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:34:51 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/16 13:42:59 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
    What is the nature of statically created str

    Result:     Normal. Ordinary
*/

int main(void)
{
    char *str = "Akadil";
    int     i;

    i = 0;
    while (str[i])
    {
        printf("%c ", str[i]);
        i++;
    }
    printf("\n\n");
    return (0);
}