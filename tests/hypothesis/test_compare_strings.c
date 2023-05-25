/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_compare_strings.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:44:57 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/25 13:58:20 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

/*
    Hypothesis: Can I compare the string just with == operator?

    Result:     Yes, I can compare them. The pointers might be different, 
                but they point at one place, so they are equal
*/  

char *ft_function(char *s1, char *s2)
{
    (void)s2;
    return (s1);
}

int main(void)
{
    char    *str1;
    char    *str2;
    // char    *str3;

    str1 = ft_strdup("Akadil\n");
    str2 = ft_strdup("Kalimoldayev\n");

    str2 = ft_function(str1, str2);

    if (str1 == str2)
        printf("Same!\n");
    else
        printf("Not same!\n");
    return (0);
}