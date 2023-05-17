/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_types.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:28:25 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/17 12:26:26 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"
#include "libft.h"
#include "data.h"

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
        else if (ft_is_special_character(node->content))
            node->type = ft_check_special_character(node->content);
        else if (ft_is_redirection(node->content) && is_filename++ >= 0)
            node->type = ft_check_redirection(node->content);
        else 
            node->type = PARAMETER;
        node = node->next;
    }
}
/*
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
*/

int ft_check_special_character(char *str)
{
    int type;

    type = 0;
    if (!ft_strcmp(str, "|"))
        type = PIPE;
    else if(!ft_strcmp(str, "||"))
        type = OR;
    else if (!ft_strcmp(str, "&&"))
        type = AND;
    else if (!ft_strcmp(str, "("))
        type = LEFT_P;
    else if (!ft_strcmp(str, ")"))
        type = RIGHT_P;
    return (type);
}

int ft_check_redirection(char *str)
{
    int type;

    type = 0;
    if (!ft_strcmp(str, "<"))
        type = REDIRECT_IN;
    else if (!ft_strcmp(str, "<<"))
        type = HEREDOC;
    else if (!ft_strcmp(str, ">"))
        type = REDIRECT_OUT;
    else if (!ft_strcmp(str, ">>"))
        type = REDIRECT_OUT2;
    return (type);
}
