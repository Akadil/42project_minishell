/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_jm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:23:00 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/16 13:38:41 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/*
    Jean-Marc's test. Why statically declared char *, can't be updated?

    Result:     That's way of c language. (char *) is readonly, while char []
                is changeable 
*/

int main(void)
{
    char *s = "Akadil";

    printf("Before: %s\n", s);

    s[0] = 'q';
    printf("After: %s", s);
    return (0);
}