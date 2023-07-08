/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extend_wildcards.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 20:38:57 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/08 18:53:43 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_list.h"
#include "libft.h"
#include <dirent.h>
#include <readline/readline.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ft_error.h"

int ft_extend(t_list **head, t_list *token);
bool	ft_match_pattern(const char *str, const char *pattern);

int ft_extend_wildcard(t_list **head)
{
    t_list  *token;
    int     code;

    code = 0;
    token = *head;
    while (token)
    {
        if (token->type == 11 && ft_strchr((char *)token->content, '*'))
        {
            code = ft_extend(head, token);
            if (code != 0)
                return (code);
        }
        token = token->next;
    }
    token = *head;
    while (token)
    {
        
    }
    return (0);
}

int ft_extend(t_list **head, t_list *token)
{
    t_list  *new;
    t_list  *temp;
	DIR				*dir;
	struct dirent	*entry;

	(void)head;
	dir = opendir(".");
	if (dir == NULL)
		return (ft_perror("opendir"), 3);
    entry = readdir(dir);
	while (entry != NULL)
	{
		if (ft_match_pattern(entry->d_name, (char *)token->content))
		{
            new = ft_lstnew(ft_strdup(entry->d_name), 11);
            temp = token->next;
            token->next = new;
            new->prev = token;
            new->next = temp;
            if (temp)
                temp->prev = new;
		}
        entry = readdir(dir);
	}
    return (closedir(dir), 0);
}

bool	ft_match_pattern(const char *str, const char *pattern)
{
	while (*str && *pattern)
	{
		if (*pattern == '*')
		{
			pattern++;
			if (*pattern == '\0')
				return (true);
			while (*str)
			{
				if (ft_match_pattern(str, pattern))
					return (true);
				str++;
			}
			return (false);
		}
		else if (*pattern == *str || *pattern == '?')
		{
			pattern++;
			str++;
		}
		else
			return (false);
	}
	return (*str == '\0' && *pattern == '\0');
}
