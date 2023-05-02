/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_structs2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 13:38:31 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/02 14:05:10 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/*
    Hypothesis:
                Can I make a double chain list with different strctures?

    Result:
                Fucking possible !!!

    Tester:
                cc -Wall -Wextra -Werror test_structs2.c && ./a.out && rm a.out
*/

typedef struct s_s1
{
    char    *name;
    void    **next;

}   t_s1;

typedef struct s_s2
{
    int     age;
    void    *next;

}   t_s2;

int main(void)
{
    t_s1    *s1;
    t_s2    *s2;
    t_s1    *s11;

    s1 = (t_s1 *)malloc(sizeof(t_s1));
    s2 = (t_s2 *)malloc(sizeof(t_s2));
    s11 = (t_s1 *)malloc(sizeof(t_s1));


    s2->age = 23;
    s11->name = "Akadil";

    s1->next = (void **)malloc(sizeof(void *) * 2);

    s1->next[0] = s2;
    s1->next[1] = s11;

    printf("My name is %s, I am %d years old\n", ((t_s1 *)s1->next[1])->name, ((t_s2 *)s1->next[0])->age);

    return (0);
}