/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_params_in_return.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 13:43:58 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/25 13:53:55 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
    Hypothesis:     I saw that sometimes people put functions inside of return 
                    statement. Explore this topic

	Result:			It is totally ok!
					1. No errors
					2. norminette is ok
					3. You can use any returner type function
*/

void	ft_free(void)
{
	printf("Hello World!\n");
}

int	ft_free2(void)
{
	printf("I am returning 2\n");
	return (2);
}

int	ft_function(char *str)
{
	return (free(str), ft_free(), ft_free(), ft_free(), ft_free2(), -21315);
}

int	main(void)
{
	char	*str;
	int		res;

	str = ft_strdup("Akadil");
	res = ft_function(str);
	printf("The result is %d\n", res);
	return (0);
}
