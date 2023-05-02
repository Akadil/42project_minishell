/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:18:09 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/02 14:06:36 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/*
    Hypothesis: 
                Can I make a chain list with different structures?

    Result: 
                Yes, I can!

    Tester:
                cc -Wall -Wextra -Werror test_structs.c && ./a.out && rm a.out 
*/

typedef struct s_s1
{
    char    *name;
    void    *next;

}   t_s1;

typedef struct s_s2
{
    int     a;
    void    *next;

}   t_s2;

int main(int argc, char **argv)
{

    (void)argc;
    (void)argv;
    
    t_s1    *s1;
    t_s2    *s2;
    t_s1    *s11;

    s1 = (t_s1 *)malloc(sizeof(t_s1));
    s2 = (t_s2 *)malloc(sizeof(t_s2));
    s11 = (t_s1 *)malloc(sizeof(t_s1));

    s1->name = "Akaidl";
    s1->next = s2;

    s2->a = 2;
    s2->next = s11;

    s11->name = "Kalimoldayev!";
    s11->next = NULL;

    printf("My surname is %s", ((t_s1 *)((t_s2 *)s1->next)->next)->name);

    return (0);
}


