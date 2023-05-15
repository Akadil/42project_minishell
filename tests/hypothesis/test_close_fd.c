/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_close_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 15:03:15 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/13 15:07:26 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

/*
    hypothesis:     Can I close the file descriptor 2 times?

    Result:         as much as I want
*/

int main(void)
{
    int fd;

    fd = open("Makefile", O_RDONLY);

    close (fd);
    printf ("Breakline\n");
    close (fd);

    return (0);
}