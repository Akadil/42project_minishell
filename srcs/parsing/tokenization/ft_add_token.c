/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:48:41 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/17 13:36:06 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "struct_list.h"
#include "libft.h"
#include "ft_error.h"

int     ft_add_token(t_list **head, char *str, int i_beg, int i_end)
{
    char    *new_str;
    t_list  *node;
    int     i;

    if (i_beg == i_end)
        i_end++;
    new_str = (char *)malloc(sizeof(char) * (i_end - i_beg + 1));
    if (!new_str)
        return (0);
    i = 0;
    while (i < i_end - i_beg)
    {
        new_str[i] = str[i + i_beg];
        i++;
    }
    new_str[i] = '\0';
    node = ft_lstnew(new_str, 0);
    if (!node)
    {
        free (new_str);
        return (0);
    }
    ft_lstadd_back(head, node);
    return (1);
}