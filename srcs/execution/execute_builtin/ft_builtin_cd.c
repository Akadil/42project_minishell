/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_cd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 15:07:09 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/31 17:51:54 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "libft.h"
#include "struct_list.h"

char	*ft_find_home(t_list *env);

/*
    Description:    cd command
    Test:           in progress 

    Input:  data - is data
            i_cmd - is cmd index
    output: void

    input cases:
        1. Doesn't consider bad inputs

    1. add env to paraleters
    2. 
*/
int	ft_execute_cd(t_list *params, t_list *env)
{
	int		count;
	char	*str;

	count = ft_lstsize(params);
	if (count == 0)
	{
		str = ft_find_home(env);
		if (!str)
			return (ft_merror("bash: cd: HOME not set\n", NULL), -1);
		if (chdir(str) == -1)
			return (ft_merror("bash: cd: HOME not set properly%s\n", str), -1);
	}
	else if (count > 1)
		return (ft_merror("bash: cd: Too many arguments\n", NULL), -1);
	else if (chdir((char *)params->content) == -1)
		return (ft_perror((char *)params->content), -1);
	return (0);
}

char	*ft_find_home(t_list *env)
{
	while (env)
	{
		if (ft_strncmp((char *)env->content, "HOME=", 5) == 0)
			return ((char *)env->content + 5);
		env = env->next;
	}
	return (NULL);
}
