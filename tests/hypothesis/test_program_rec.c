/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_program_rec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 17:41:20 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/02 18:34:24 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"

/*
    Hypothesis:
                    can I call the my own program recursivelly
    
    Result:
                    No. Or at least I didn't tried properly
*/

int main(int argc, char **argv, char **env)
{

    (void) argv;

    if (argc != 3)
    {
        printf("The last one !");
        return (0);
    }
    
    char *path;

    path = getcwd(NULL, 0);
    path = ft_strjoin(path, argv[0]);

    char    **param;

    param = (char **)malloc(2);
    param[0] = argv[0];
    param[1] = NULL;


    int fd[2];

    pipe(fd);

    dup2(fd[1], STDOUT_FILENO);

    if (fork() == 0)
       execve(path, param, env);
    else
        close (fd[1]);
    
    close (fd[0]);

    char    *str;

    int a = open("outfile.txt", O_CREAT, O_WRONLY);

    dup2(a, STDOUT_FILENO);
    str = get_next_line(fd[0], 0);
    while (str)
    {
        printf("%s\n", str);
        str = get_next_line(fd[0], 0);
    }

    return (0);
}