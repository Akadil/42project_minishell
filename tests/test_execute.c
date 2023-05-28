#include "struct_data.h"
#include "struct_list.h"
#include <stdio.h>
#include "libft.h"
#include <readline/history.h>
#include <readline/readline.h>

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
    ft_lstadd_back(&env_var, ft_lstnew("d=-la ", 0));
    ft_lstadd_back(&env_var, ft_lstnew("e=main.c error.c", 0));

    str = readline("Entter: ");
    while (str)
    {
        params = ft_split(str, ' ');
        i = 0;
        while (params[i])
        {
            ft_lstadd_back(&node.cmds->params, ft_lstnew(params[i], 0));
            i++;
        }
        str = readline("Entter: ");
    }
    printf("%d", ft_execute(node.cmds, &env_var, &node));
    return (0);
}