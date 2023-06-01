/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 21:45:25 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/01 17:12:47 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "libft.h"
#include "struct_data.h"
#include "struct_list.h"
#include <stdlib.h>

void	ft_print_export_token(char *str)
{
	char	*equal_sign;
	char	*value;

	ft_printf("export ");
	equal_sign = ft_strchr(str, '=');
	if (equal_sign != NULL)
	{
		*equal_sign = '\0';
		value = equal_sign + 1;
		ft_printf("%s=\"%s\"\n", str, value);
		*equal_sign = '=';
	}
	else
		ft_printf("%s\n", str);
}

void	ft_swap(t_list *a, t_list *b)
{
    void *temp;
	
	temp = a->content;
    a->content = b->content;
    b->content = temp;
}

void	ft_bubble_sort_list(t_list *head)
{
    int swapped = 1;
    t_list	*ptr1;
    t_list	*ptr2;

	ptr2 = NULL;
	if (head == NULL)
        return;
    while (swapped)
	{
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != ptr2)
		{
            if (ft_strcmp(ptr1->content, ptr1->next->content) > 0)
			{
                ft_swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        ptr2 = ptr1;
    }
}

void	ft_print_export(t_list *env)
{
	ft_bubble_sort_list(env);
	while (env)
	{
		ft_print_export_token((char *)env->content);
		env = env->next;
	}
}

void	ft_remove_if_exist(t_list **env, char *new_value)
{
	t_list	*token;
	t_list	*temp;
	char	*str;
	int		i;

	token = *env;
	while (token)
	{
		i = 0;
		str = (char *)token->content;
		while (str[i] && new_value[i] && str[i] != '=')
			i++;
		temp = token->next;
		if (str[i] == '=' || str[i] == '\0')
			if (new_value[i] == '=' || new_value[i] == '\0')
				if (ft_strncmp(str, new_value, i) == 0)
					ft_lstremove(env, token, &free);
		token = temp;
	}
}

int	ft_execute_export(t_list *params, t_list **env)
{
	t_list	*token;
	char	*new_value;

	if (!params)
		return (ft_print_export(*env), 0);
	new_value = ft_strdup((char *)params->content);
	if (!new_value)
		return (-1);
	token = ft_lstnew(new_value, 1);
	if (!token)
		return (-1);
	ft_remove_if_exist(env, new_value);
	ft_lstadd_front(env, token);
	return (0);
}
