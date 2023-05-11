/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_types.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:28:25 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/11 16:08:12 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"
#include "libft.h"

#define PIPE 1
#define OR 2
#define AND 3

#define LEFT_P 4
#define RIGHT_P 5

#define REDIRECT_IN 6
#define REDIRECT_OUT 7
#define HEREDOC 8
#define REDIRECT_OUT2 9

#define FILENAME 10
#define PARAMETER 11

/*
    Go through each value and assign the values
*/
void    ft_assign_types(t_list *node)
{
    int is_filename;

    is_filename = 0;
    while (node)
    {
        if (is_filename == 1 && is_filename--)
            node->type = FILENAME;
        if (ft_strcmp(node->content, "|"))
            node->type = PIPE;
        else if(ft_strcmp(node->content, "||"))
            node->type = OR;
        else if (ft_strcmp(node->content, "&&"))
            node->type = AND;
        else if (ft_strcmp(node->content, "("))
            node->type = LEFT_P;
        else if (ft_strcmp(node->content, ")"))
            node->type = RIGHT_P;
        else if (ft_strcmp(node->content, "<") && is_filename++)
            node->type = REDIRECT_IN;
        else if (ft_strcmp(node->content, "<<") && is_filename++)
            node->type = HEREDOC;
        else if (ft_strcmp(node->content, ">") && is_filename++)
            node->type = REDIRECT_OUT;
        else if (ft_strcmp(node->content, ">>") && is_filename++)
            node->type = REDIRECT_OUT2;
        else 
            node->type = PARAMETER;
        node = node->next;
    }
}
