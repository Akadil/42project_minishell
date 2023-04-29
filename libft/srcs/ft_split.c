/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:31:57 by akalimol          #+#    #+#             */
/*   Updated: 2022/12/11 17:56:56 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_n_word(char const *s, char c)
{
	int	i;
	int	n;
	int	checker;

	n = 0;
	i = 0;
	checker = 1;
	while (s[i])
	{
		if (s[i] != c && checker == 1)
		{
			checker = 0;
			n++;
		}
		else if (s[i] == c && checker == 0)
		{
			checker = 1;
		}
		i++;
	}
	return (n);
}

static char	*ft_add_word(char const *s, char c, int *pos)
{
	char	*word;
	int		word_len;
	int		i;

	word_len = 0;
	while (s[*pos] == c)
		*pos = *pos + 1;
	while (s[*pos + word_len] && s[*pos + word_len] != c)
		word_len++;
	word = (char *) malloc(sizeof(char) * (word_len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (s[*pos] && s[*pos] != c)
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

char	**ft_split(char const *s, char c)
{
	char	**returner;
	int		n_word;
	int		i;
	int		i_word;

	if (!s)
		return (NULL);
	n_word = ft_find_n_word(s, c);
	returner = (char **) malloc(sizeof(char *) * (n_word + 1));
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
