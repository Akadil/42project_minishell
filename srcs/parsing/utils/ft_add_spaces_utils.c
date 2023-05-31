/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_spaces_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:42:57 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/31 21:33:54 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "libft.h"

void	ft_put(char *string, int *j, int *i, char *meta)
{
	int	size;

	size = 0;
	string[*j] = ' ';
	*j = *j + 1;
	while (meta && meta[size])
	{
		string[*j] = meta[size];
		*j = *j + 1;
		size++;
	}
	string[*j] = ' ';
	*j = *j + 1;
	if (size == 2)
		*i = *i + 1;
}

size_t	ft_strlcpy_alt(char *restrict dst, const char *restrict src,
		size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	i = 0;
	src_len = ft_strlen(src);
	while (i + 1 < dstsize && i < src_len)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize != 0)
	{
		while (i < dstsize)
		{
			dst[i] = '\0';
			i++;
		}
	}
	return (src_len);
}

void	*ft_memset2(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		((unsigned char *)b)[i++] = c;
	return (b);
}

void	ft_remove_extra_spaces(char *str, int size)
{
	int	i;
	int	j;
	int	len;

	len = ft_strlen(str);
	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	ft_strlcpy_alt(str, &str[i], len + 1);
	i = len - 1;
	while (i >= 0 && str[i] == ' ')
	{
		str[i] = '\0';
		i--;
	}
	i = 0;
	j = 0;
	while (i < len)
	{
		if (!(str[i] == ' ' && str[i + 1] == ' '))
			str[j++] = str[i];
		i++;
	}
	str[j] = '\0';
	ft_memset2(str + j, '\0', size - j);
}
