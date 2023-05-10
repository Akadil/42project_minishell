/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_envvar_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:58:32 by akalimol          #+#    #+#             */
/*   Updated: 2023/04/11 21:04:31 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_envvar_info.h"

void    ft_envvar_info(t_envvar *data, char *line)
{
    int i;
    int j;

    data->size = ft_envvar_count(line);
    data->item = (t_item *)malloc(sizeof(t_item) * data->size);			// Consider num == 0 case
    if (!data->item)
        exit(-1);															// Extend
    ft_init_envvar(data);
    j = 0;
    i = 0;
    while (i < data->size)
    {
        while (line[j] != '$' || (line[j] == '$' && !ft_isalnum_alt2(line[j + 1])))
            j++;
        data->item[i].key = ft_add_word(line, j);
		data->item[i].value = getenv(data->item[i].key);
        data->item[i].key_size = ft_strlen(data->item[i].key);
        if (data->item[i].value)
    		data->item[i].value_size = ft_strlen(data->item[i].value);
        data->key_size += data->item[i].key_size;
        data->value_size += data->item[i].value_size;
        i++;
        j++;
    }
}

char    *ft_add_word(char *line, int pos)
{
    char    *word;
    int size;
    int i;

    pos++;
    size = ft_word_size(line, pos);
    word = (char *)malloc(sizeof(char) * (size + 1));
	if (!word)
		return (NULL);												 // Consider this case
    i = 0;
    while (i < size)
    {
        word[i] = line[pos + i];
        i++;
    }
    return (word);
}