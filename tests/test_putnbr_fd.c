/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_putnbr_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:30:21 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/07 16:36:15 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

/*
    Description:        Recoded that function, so this is the test

    Results:            All tests passed

    Tester:              cc -Wall -Werror -Wextra test_putnbr_fd.c ../libft/srcs/print/ft_putnbr_fd.c
*/

int	ft_putnbr_fd(int nb, int fd);

int main(int argc, char **argv)
{
    int size;
    (void)argc;

    size = ft_putnbr_fd(atoi(argv[1]), 1);
    printf("\nThe size is %d", size);
    return (0);
}