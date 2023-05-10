/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_struct_location_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akadilkalimoldayev <akadilkalimoldayev@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 17:45:14 by akadilkalim       #+#    #+#             */
/*   Updated: 2023/05/06 17:48:57 by akadilkalim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_str
{
    int a;
    int b;
}   t_str;

void    ft_function(t_str *str)
{
    str->a = 5;
}