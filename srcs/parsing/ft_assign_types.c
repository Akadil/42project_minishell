/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_types.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:28:25 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/17 13:35:52 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_list.h"
#include "libft.h"
#include "struct_data.h"

/*
    Go through each value and assign the values

    if I see <. then no matter what the next token is infile
*/
void    ft_assign_types(t_list *node)
{
    int is_filename;

    is_filename = 0;
    while (node)
    {
        if (is_filename == 1 && is_filename--)
            node->type = FILENAME;
        else if (!ft_strcmp(node->content, "|"))
            node->type = PIPE;
        else if(!ft_strcmp(node->content, "||"))
            node->type = OR;
        else if (!ft_strcmp(node->content, "&&"))
            node->type = AND;
        else if (!ft_strcmp(node->content, "("))
            node->type = LEFT_P;
        else if (!ft_strcmp(node->content, ")"))
            node->type = RIGHT_P;
        else if (!ft_strcmp(node->content, "<") && is_filename++ >= 0)
            node->type = REDIRECT_IN;
        else if (!ft_strcmp(node->content, "<<") && is_filename++ >= 0)
            node->type = HEREDOC;
        else if (!ft_strcmp(node->content, ">") && is_filename++ >= 0)
            node->type = REDIRECT_OUT;
        else if (!ft_strcmp(node->content, ">>") && is_filename++ >= 0)
            node->type = REDIRECT_OUT2;
        else 
            node->type = PARAMETER;
        node = node->next;
    }
}
