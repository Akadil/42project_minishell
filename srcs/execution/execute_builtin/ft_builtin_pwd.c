/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_pwd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:07:59 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/31 17:59:49 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
void	ft_execute_pwd(void)
{
	char	*response;

	response = getcwd(NULL, 0);
	ft_printf("%s\n", response);
	free(response);
}
