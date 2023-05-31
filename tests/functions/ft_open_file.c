/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:08:56 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/31 18:09:07 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**



int	ft_open(t_list *token, int fd)
{
	int	return_fd;

	return_fd = fd;
	if (token->type == REDIRECT_IN)
	{
		if (fd != 0)
			close(fd);
		fd = open((char *)token->content, O_RDONLY);
	}
	else if (token->type == REDIRECT_OUT)
	{
		return_fd = open((char *)token->content, O_WRONLY | O_CREAT | O_TRUNC, 0666);
		if (isatty(return_fd) == 1)
			return (close(return_fd), fd);
		if (fd != 1)
			close(fd);
		fd = return_fd;
	}
	else if (token->type == REDIRECT_OUT2)
	{
		return_fd = open((char *)token->content, O_WRONLY | O_CREAT | O_APPEND, 0666);
		if (isatty(return_fd) == 1)
			return (close(return_fd), fd);
		if (fd != 1)
			close(fd);
		fd = return_fd;
	}
	else
	{
		if (fd != 0)
			close(fd);
		fd = *((int *)token->content);
	}
	return (fd);
}

 * 
 */