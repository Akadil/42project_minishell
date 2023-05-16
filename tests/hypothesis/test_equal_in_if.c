/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_equal_in_if.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:45:44 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/16 13:50:01 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
    Can I assign values inside of if condition

    Resuts:     I can assign. If the value is equal to zero of any type, then 
                it counted as a false
*/

char *ft_return(char *str)
{
    return (str);
}

int main(void)
{
    char *str;

    if (!(str = ft_return(NULL)))
        printf("I was here\n");
    return (0);
}