/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:41:27 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/22 16:24:32 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_list.h"
#include "libft.h"
#include <stdio.h>

t_list	*ft_parse_double(t_list *token, int *i, char *env)
{
	char	*str;
	int		i_beg;

	str = (char *)token->content;
	i_beg = *i;
	(*i)++;
	while (str[*i] != '\"')
		(*i)++;
	
}

void	ft_parse_dollar(t_list *token, int *i_p, t_list *env)
{
	char	*str;
	int	i;

	i = *i_p + 1;
	str = (char *)token->content;
	while (str[i])
	{
		if (ft_isalnum(str[i]) != 1 && str[i] != '_')
			break;
		i++;
	}
	char	*word;

	word = ft_find_word(i, *i_p, str, env);
	int	count_words;

	count_words = ft_count_words(word);
	char **words;

	
}

void	ft_parse_word(t_list *token, int *i_p)
{
	char	*str;
	int		i;

	i = i_p;
	str = (char *)token->content;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"' || str[i] == '$')
			break;
		i++;
	}
	*i_p = i;
}

t_list	*ft_expand(t_list *token, t_list *env, char mode)
{
    char    *str;
    t_list  *new;
	int     i;
	
    str = (char *)token->content;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			ft_parse_double(str, &i, env);        // This one works with dollars
		else if (str[i] == '\'')
			ft_parse_single(str, &i, env);        // This one just removes the quotes
		else if (str[i] == '$')
			ft_parse_dollar(str, &i, env);        // 
		else
			ft_parse_word(str, &i);
        if (!new)
        {
            // Error
        }
		// i++ shouldn't be here
	}
}