/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_string_utils_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:28:52 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/23 12:47:11 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int     ft_strlcat_alt(char *dst, const char *src, int dstsize);

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

char    *ft_strjoin_big(char *str, char *value, char *end)
{
    char    *returner;
    int size;

    size = ft_size_expanded(str, value, end);
    returner = (char *)ft_calloc(sizeof(char), size + 1);
    if (!returner)
        return (NULL);
    ft_strlcat_alt(returner, str, size + 1);
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

