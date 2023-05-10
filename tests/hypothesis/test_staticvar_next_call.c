/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_staticvar_next_call.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akadilkalimoldayev <akadilkalimoldayev@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:28:18 by akadilkalim       #+#    #+#             */
/*   Updated: 2023/05/09 16:35:22 by akadilkalim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
    Hypothesis:     Damn shit. 

    Results:        static var doesn't work. I can't call it second time.
                    I have to refrresh the meaning each time
*/

int    ft_func(int num)
{
    static int  qwe;

    qwe = 0;
    if (num > 0)
    {
        qwe++;
        ft_func(num - 1);
    }
    return (qwe);
}

int main(void)
{
    printf("My num is %d\n", ft_func(3));

    printf("and next time is %d\n", ft_func(3));

    return(0);
}