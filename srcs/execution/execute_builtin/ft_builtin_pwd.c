/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_pwd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:07:59 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/26 13:14:28 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*
    ----------------- Description -------------------    
    Print the current directory

    Input:          ~
    Output:         Print


    ------------------ Test ----------------------
    Status:     Tested 

    Test file:  ./tester_akadil/test_buildin_pwd.c

    Results:    Good printing and valgrind free
*/
void    ft_buildin_pwd()
{
    char    *response;

    response = getcwd(NULL, 0);
    ft_printf("%s\n", response);
    free (response);
}