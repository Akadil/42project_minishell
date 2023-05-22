/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:24:59 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/22 20:06:36 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_expand_token.h"

int     ft_size_expanded(char *str, char *value, char *end)
{
    int size;
    int i;

    size = 0;
    i = 0;
    while (str && str[i] != '$')
    {
        size++;
        i++;
    }
    i = 0;
    while (value && value[i])
    {
        size++;
        i++;
    }
    i = 0;
    while (end && end[i])
    {
        size++;
        i++;
    }
    return (size);
}

char    *ft_cat_everything(char *str, char *value, char *end)
{
    // I have previous word, the value, and after work
    char    *returner;
    int size;

    size = ft_size_expanded(str, value, end);
    returner = (char *)ft_calloc(sizeof(char), size + 1);
    if (!returner)
        return (NULL);
    ft_strlcat_alt(returner, str, size + 1);        // Have to stop on $
    ft_strlcat(returner, value, size + 1);
    ft_strlcat(returner, end, size + 1);
    free(str);
    return (returner);
}

int ft_find_key(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (ft_isalnum(str[i]) != 1 && str[i] != '_')
            break;
        i++;
    }
    return (i);
}

char    *ft_find_value(char *key, int i_pos, t_list *env)
{
    while (env)
    {
        if (ft_strncmp((char* )env->content, key, i_pos) == 0)
            if (((char* )env->content)[i_pos] == '=')
                return ((char* )env->content + i_pos + 1);
        env = env->next;
    }
    return (NULL);
}

/*
    Inputs:     1. char *str
*/
t_list  *ft_expand_token(char *str, t_list *env)
{
    t_list  *node;
    char    *temp;
    char    *value;
    int     i_pos;

    node = NULL;
    temp = ft_strchr_alt(str, '$');     // Alternative because $ in quotes doesn't count
    if (temp == NULL)
        return (ft_lstnew(str, 0));
    while (temp)
    {
        // My goal is to create the maximum string without any expansions
        i_pos = ft_find_key(temp + 1);
        value = ft_find_value(temp + 1, i_pos, env);
        str = ft_cat_everything(str, value, temp + i_pos + 1);
        if (!str)
            return (NULL);                          // Protect it 
        temp = ft_strchr_alt(str, '$');
    }
    return (ft_lstnew(str, 0));
}