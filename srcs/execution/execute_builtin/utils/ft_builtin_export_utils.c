/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin_export_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:01:50 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/01 18:04:03 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "struct_list.h"
#include "libft.h"

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
	void	*temp;

	temp = a->content;
	a->content = b->content;
	b->content = temp;
}

void	ft_bubble_sort_list(t_list *head)
{
	int		swapped;
	t_list	*ptr1;
	t_list	*ptr2;

	swapped = 1;
	ptr2 = NULL;
	if (head == NULL)
		return ;
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
