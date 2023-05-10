/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akadilkalimoldayev <akadilkalimoldayev@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:55:59 by akadilkalim       #+#    #+#             */
/*   Updated: 2023/05/06 15:01:43 by akadilkalim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
    Hypothesis:     Can I send uninitialized structure to function

    Result:         Yes
*/

typedef struct s_data
{
    int a;
    int b;
}       t_data;

void    ft_function(t_data *data);

int main(void)
{
    t_data  data;

    ft_function(&data);
    return (0);
}

void    ft_function(t_data *data)
{
    printf("%d\n", data->a);
}