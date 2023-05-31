/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:30:15 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/31 19:22:53 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "libft.h"
#include <stdlib.h>

void	ft_error(void)
{
	char	*join;

	join = ft_strjoin(strerror(errno), "\n");
	ft_printf2("%s", join);
	free(join);
}

void	ft_perror(char *str)
{
	char	*join;

	join = ft_strjoin("bash: ", str);
	perror(join);
	free(join);
}

void	ft_merror(char *str, char *param)
{
	ft_printf2(str, param);
}
