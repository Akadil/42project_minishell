/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_array_as_param.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 17:06:21 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/17 17:09:05 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
    Can I statically created string to some other functions

    Result: Yes I can
*/

char *function(void)
{
    return ("Akadil");
}

void    function2(char *str)
{
    printf("%s\n", str);
}

int main(void)
{
    char *str;

    str = function();

    function2(str);
    return (0);
}