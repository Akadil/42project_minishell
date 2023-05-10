/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_struct_location_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akadilkalimoldayev <akadilkalimoldayev@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:43:38 by akadilkalim       #+#    #+#             */
/*   Updated: 2023/05/06 17:48:51 by akadilkalim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
    Hypothesis: Can I have several definition of the same struct throughout 
                different files

    Results     Yes
*/

typedef struct s_str
{
    int a;
}   t_str;

void    ft_function(t_str *str);

int main(void)
{
    t_str   str;

    str.a = 2;
    ft_function(&str);
    printf("%d\n", str.a);
    return (0);
}