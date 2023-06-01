/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_string_utils_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 12:28:52 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/01 17:25:11 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "struct_data.h"
#include <stdio.h>

int	ft_strlcat_alt(char *dst, const char *src, int dstsize);

int	ft_size_expanded(char *str, char *value, char *end)
{
	char	mode;
	int		size;
	int		i;

	size = 0;
	mode = '\0';
	i = 0;
	while (str)
	{
		if (mode == 0 && str[i] == '\'')
			mode = '\'';
		else if (mode == '\'' && str[i] == '\'')
			mode = '\0';
		else if (mode == 0 && str[i] == '\"')
			mode = '\"';
		else if (mode == '\"' && str[i] == '\"')
			mode = '\0';
		else if (str[i] == '$' && (mode == '\0' || mode == '\"'))
			break ;
		size++;
		i++;
	}
	size = size + ft_strlen(value) + ft_strlen(end);
	return (size);
}

char	*ft_strjoin_big(char *str, char *value, char *end)
{
	char	*returner;
	int		size;

	size = ft_size_expanded(str, value, end);
	returner = (char *)ft_calloc(sizeof(char), size + 1);
	if (!returner)
		return (NULL);
	if (str)
		ft_strlcat_alt(returner, str, size + 1);
	if (value)
		ft_strlcat(returner, value, size + 1);
	if (end)
		ft_strlcat(returner, end, size + 1);
	free(str);
	return (returner);
}

int	ft_find_key(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '?' && str[i + 1] == '\0')
		return (i + 1);
	while (str[i])
	{
		if (ft_isalnum(str[i]) != 1 && str[i] != '_')
			break ;
		i++;
	}
	return (i);
}

char	*ft_find_value(char *key, int i_pos, t_list *env, t_data *data)
{
	if ((*key) == '?')
	{
		return (ft_itoa(data->exit_code));
	}
	while (env)
	{
		if (ft_strncmp((char *)env->content, key, i_pos) == 0)
			if (((char *)env->content)[i_pos] == '=')
				return ((char *)env->content + i_pos + 1);
		env = env->next;
	}
	return (NULL);
}
