/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_static_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:19:52 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/05 21:02:10 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
    Check how does unintialized static variables work

    Result:     int == 0, char == '\0' == 0

    To check:   cc -Wall -Werror -Wextra test_static_var.c && valgrind ./a.out && rm a.out
*/
int     ft_func(int mode);
int     ft_func2(int *num);
char    ft_func3();
char    ft_func4();

int main(void)
{
    printf("My num is %d\n", ft_func(1));
    printf("My char is %d\n", ft_func3());
    printf("My char ascii is %c\n", ft_func4());
    return (0);
}

char    ft_func4()
{
    static char c;

    if (c == '\0')
        return ('b');
    return ('a');
}

char    ft_func3()
{
    static char c;

    return (c);
}

int    ft_func(int mode)
{
    static int  a;
    
    if (mode == 1)
        return (ft_func2(&a));
    return (a);
}

int ft_func2(int *num)
{
    return (*num);
}