/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_init_envvar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akadilkalimoldayev <akadilkalimoldayev@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:22:49 by akadilkalim       #+#    #+#             */
/*   Updated: 2023/05/09 18:45:55 by akadilkalim      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
    Test the rightness of the ft_init_envvar function
    
    Location:   srcs/init/ft_init_envvar.c

    To check:   cc -I ../includes -Wall -Werror -Wextra test_init_envvar.c ../srcs/init/ft_init_envvar.c -L../libft -lft && ./a.out  && rm a.out

    Result:
*/

void    ft_init_env(t_list **data, char **env);
void    ft_error(t_list  **data);

int main(int argc, char **argv, char **env)
{
    t_list  *beg;

    (void)argc;
    (void)argv;

    beg = NULL;

    ft_init_env(&beg, env);
    
    while (beg)
    {
        printf("%s -> %d\n", (char *)beg->content, beg->type);
        beg = beg->next;
    }
    ft_error(&beg);
    return (0);
}