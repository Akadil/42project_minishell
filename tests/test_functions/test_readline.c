/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_readline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:21:16 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/01 15:46:38 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

/*
    In this file I am going to test:
        1. Readline                     [Link](https://man7.org/linux/man-pages/man3/readline.3.html)
            reads the input from the user
        2. add_history(char *line)      
            adds the "line" to the history, so that you can access them in the up arrow
        3. rl_clear_history
            clears the history
        
        4. rl_on_new_line
            stupid and unclear function
        5. rl_replace_line
            stupid and unclear function
        6. rl_redisplay
            stupid and unclear function
        
*/

int main(int argc, char **argv)
{
    char *line;

    (void) argc;
    (void) argv;

    line = readline("Prompt > ");
    while (line)
    {
        printf("%s\n", line);
        add_history(line);
        free (line);
        line = readline("Prompt > ");
    }
    clear_history();

    line = readline("Last one");
    return (0);
}