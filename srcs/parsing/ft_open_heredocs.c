/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_heredocs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 03:32:32 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/24 17:10:28 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_list.h"
#include "ft_error.h"
#include "libft.h"
#include <unistd.h>
#include <readline/readline.h>

int    ft_get_heredoc(char *delimiter);

int ft_open_heredocs(t_list *head)
{
    t_list  *token;
    void    *temp;
    int     *fd;

    token = head;
    while (token)
    {
        if (token->type == 8)
        {
            temp = token->content;
            fd = (int *)malloc(sizeof(int));
            if (!fd)
                return (-1);
            *fd = ft_get_heredoc((char *)temp);
            if (*fd == -1)
            {
                free (fd);
                return (-1);
            }
            token->content = fd;
            free (temp);
        }
        token = token->next;
    }
    return (0);
}

int    ft_get_heredoc(char *delimiter)
{
	char    *line;
    int		fd[2];

    if (pipe(fd) == -1)
    {
        ft_error();
        return (-1);
    }
	line = readline(">");
	while (line && ft_strcmp(line, delimiter) != 0)
	{
		ft_putstr_fd(line, fd[0]);
		free(line);
		line = readline(">");
	}
    free(line);
    close (fd[0]);
    return (fd[1]);
}
