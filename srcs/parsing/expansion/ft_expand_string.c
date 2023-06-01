/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:24:59 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/01 17:23:52 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_expand_string.h"
#include "struct_data.h"

char	*ft_expand_string(char *str, t_list *env, t_data *data)
{
	char	*temp;
	char	*value;
	int		pos_key;
	int		status;

	temp = ft_strchr_alt(str, '$');
	status = 0;
	if (!temp)
		return (str);
	while (temp)
	{
		pos_key = ft_find_key(temp + 1);
		value = ft_find_value(temp + 1, pos_key, env, data);
		if (temp[1] == '?' && (temp[2] == ' ' || temp[2] == '\0'))
			status = 1;
		str = ft_strjoin_big(str, value, temp + pos_key + 1);
		if (status == 1)
			free(value);
		if (!str)
			return (NULL);
		temp = ft_strchr_alt(str, '$');
	}
	return (str);
}
