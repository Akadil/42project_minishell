/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:30:59 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/17 13:35:10 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_data.h"
#include <stdio.h>

/*
		Close all file descriptors if open
*/
void	ft_clean_fds(t_data *my_data)
{
	(void)my_data;
	printf("ft_clean_fds() is on construction :( \n");
}

/*
		Free my data
*/
void	ft_clean_data(t_data *my_data)
{
	(void)my_data;
    printf("ft_clean_data() is on construction :( \n");
}

/*
		Delete temporary created file for here_doc
*/
void	ft_clean_heredoc(t_data *my_data)
{
	(void)my_data;
	printf("ft_clean_heredoc() is on construction :( \n");
}

void	ft_clean_full(t_data *my_data)
{
	(void)my_data;
	printf("ft_clean_full() is on construction :( \n");
}