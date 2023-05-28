/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:04:16 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/28 19:04:17 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_data.h"
#include "struct_list.h"
#include <stdio.h>
#include "libft.h"
#include <readline/history.h>
#include <readline/readline.h>

/*
    To test:        make test_execute
*/

int ft_execute(t_cmd *cmd, t_list **env, t_node *node);

int main(void)
{
    t_node  node;
    t_list  *env_var;
    char    *str;
    char    **params;
    int     i;
    
    node.cmds = (t_cmd *)ft_calloc(sizeof(t_cmd), 1);
    node.cmds->redir = NULL;
    node.cmds->in_fd = 0;
    node.cmds->out_fd = 1;
    env_var = ft_lstnew("HOME=/my_home", 0);
    ft_lstadd_back(&env_var, ft_lstnew("USER=akalimol", 0));
    ft_lstadd_back(&env_var, ft_lstnew("a=z", 0));
    ft_lstadd_back(&env_var, ft_lstnew("b= ", 0));
    ft_lstadd_back(&env_var, ft_lstnew("c= -la", 0));
    ft_lstadd_back(&env_var, ft_lstnew("PATH=/mnt/nfs/homes/akalimol/sgoinfre/miniconda3/bin:/mnt/nfs/homes/akalimol/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin", 0));
    ft_lstadd_back(&env_var, ft_lstnew("e=main.c error.c", 0));
    
    str = readline("Enter: ");
    params = ft_split(str, ' ');
    i = 0;
    while (params[i])
    {
        ft_lstadd_back(&node.cmds->params, ft_lstnew(params[i], 0));
        i++;
    }
    ft_execute(node.cmds, &env_var, &node);
    return (0);
}