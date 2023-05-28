/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 15:30:27 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/28 18:47:35 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"
#include "ft_clean.h"

/**
 * @brief   shows an error message. Without any clarification
 * 
 * @param my_data   my_data
 */
void	ft_error_clean_exit(t_node *node, t_list *env, int exit_code)
{
	ft_error();
	ft_clean_tree(node);
	ft_clean_env(env);
	exit(exit_code);
}

/**
 * @brief   Clean the data and exit with 
 *              "str": error message
 *          format
 * 
 * Usually, used for filenames: filename: No such file or direcrory
 * 
 * @param my_data   my_data
 * @param str       some string before error message
 */
void	ft_perror_clean_exit(t_data *my_data, char *str)
{
	ft_perror(str);
	ft_clean_full(my_data);
	exit(-1);
}

/**
 * @brief Clean the data and exit with custom error message
 * 
 * @param my_data   My data
 * @param str       The same as printf parameters. str is "qwerty %s"
 * @param param     The same as printf. it is %s
 */
void	ft_merror_clean_exit(t_data *my_data, char *str, char *param)
{
	ft_merror(str, param);
	ft_clean_full(my_data);
	exit(-1);
}

void	ft_clean_exit(t_data *my_data)
{
	ft_clean_full(my_data);
	exit(-1);
}

void	ft_error_exit(int exit_code)
{
	ft_error();
	exit(exit_code);
}

void	ft_perror_exit(char *str, int exit_code)
{
	ft_perror(str);
	exit (exit_code);
}

void    ft_merror_exit(char *str, char *param, int exit_code)
{
	ft_merror(str, param);
	exit (exit_code);
}
