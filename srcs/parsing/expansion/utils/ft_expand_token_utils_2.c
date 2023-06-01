/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_token_utils_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:02:11 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/01 17:25:44 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_skip(char const *str, int i, char c);

int	ft_find_n_word(char const *s, char c)
{
	int	i;
	int	n;

	n = 0;
	i = ft_skip(s, 0, ' ');
	if (s[i] != '\0')
		n++;
	while (s[i])
	{
		if (s[i] == '\'' && i++ >= 0)
			i = ft_skip(s, i, '\'');
		else if (s[i] == '\"' && i++ >= 0)
			i = ft_skip(s, i, '\"');
		else if (s[i] == c)
		{
			i = ft_skip(s, i, ' ');
			if (s[i] != c)
				n++;
		}
		else
			i++;
	}
	return (n);
}

static int	ft_strlen_alt(const char *str, int i_pos)
{
	char	mode;
	int		size;
	int		i;

	size = 0;
	mode = '\0';
	i = i_pos;
	while (str[i])
	{
		if (mode == 0 && str[i] == '\'')
			mode = '\'';
		else if (mode == 0 && str[i] == '\"')
			mode = '\"';
		else if (mode == '\'' && str[i] == '\'')
			mode = '\0';
		else if (mode == '\"' && str[i] == '\"')
			mode = '\0';
		else if (str[i] == ' ' && mode == '\0')
			break ;
		size++;
		i++;
	}
	return (size);
}

static char	*ft_add_word(char const *s, char c, int *pos)
{
	char	*word;
	int		word_len;
	int		i;

	while (s[*pos] == c)
		*pos = *pos + 1;
	word_len = ft_strlen_alt(s, *pos);
	word = (char *)malloc(sizeof(char) * (word_len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (s[*pos] && i < word_len)
	{
		word[i] = s[*pos];
		*pos = *pos + 1;
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	*ft_free(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
	return (NULL);
}

char	**ft_split_alt(char const *s, char c)
{
	char	**returner;
	int		n_word;
	int		i;
	int		i_word;

	if (!s)
		return (NULL);
	n_word = ft_find_n_word(s, c);
	returner = (char **)malloc(sizeof(char *) * (n_word + 1));
	if (!returner)
		return (NULL);
	i = 0;
	i_word = 0;
	while (i_word < n_word)
	{
		returner[i_word] = ft_add_word(s, c, &i);
		if (!returner[i_word])
			return (ft_free(returner));
		i_word++;
	}
	returner[i_word] = 0;
	return (returner);
}
