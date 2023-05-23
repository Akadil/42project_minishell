/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 16:28:58 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/22 18:51:20 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_list.h"
#include "libft.h"

char    *ft_find_key(char *str, int i)
{
    char    *key_str;
    int     size;

    size = 0;
    while (str[i + size + 1])
    {
        if (ft_isalnum(str[i + size + 1]) != 1 && str[i + size + 1] != '_')
            break;
        size++;
    }
    key_str = (char *)malloc(sizeof(char) * (size + 1));
    if (!key_str)
        return (NULL);
    size = 0;
    size = 0;
    while (str[i + size + 1])
    {
        if (ft_isalnum(str[i + size + 1]) != 1 && str[i + size + 1] != '_')
            break;
        key_str[size] = str[i + size + 1];
        size++;
    }
    key_str[size] = '\0';
    return (key_str);
}

char    *ft_find_value(t_list *env, char *key)
{
    int key_len;

    key_len = ft_strlen(key);
    while (env)
    {
        if (ft_strncmp((char* )env->content, key, key_len) == 0)
            if (((char* )env->content)[key_len] == '=')
                return ((char* )env->content + key_len + 1);
        env = env->next;
    }
    return (NULL);
}

int ft_num_words(char *str)
{
    int count;
    int i;

    i = 0;
    count == 0;
    while (str[i])
    {
        if (str[i] == ' ')
            return (0);
    }
}

void    ft_parse_dollar(t_list *token, int *i, t_list *env)
{
    char    *str;
    char    *key_str;
    char    *value_str;
    char    **words;
    int     num_words;

    str = (char *)token->content;
    key_str = ft_find_key(str, *i);
    value_str = ft_get_value(key_str, env);
    
    num_words = ft_num_words(value_str);
    if (num_words > 1)
        words = ft_split(value_str, ' ');

    int j;
    t_list  *head;
    t_list  *temp;

    j = 0;
    head = NULL;
    temp = NULL;
    while (j < num_words)
    {
        temp = ft_lstnew(words[j], 0);

    }
    
}