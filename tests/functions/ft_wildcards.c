/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wildcards.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 20:29:06 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/01 20:32:48 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <readline/readline.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool	ft_match_pattern(const char *str, const char *pattern)
{
	while (*str && *pattern)
	{
		if (*pattern == '*')
		{
			pattern++;
			if (*pattern == '\0')
				return (true);
			while (*str)
			{
				if (ft_match_pattern(str, pattern))
					return (true);
				str++;
			}
			return (false);
		}
		else if (*pattern == *str || *pattern == '?')
		{
			pattern++;
			str++;
		}
		else
			return (false);
	}
	return (*str == '\0' && *pattern == '\0');
}

void	listFilesWithWildcard(const char *pattern)
{
	DIR				*dir;
	struct dirent	*entry;

	dir = opendir(".");
	if (dir == NULL)
	{
		perror("opendir");
		return ;
	}
	while ((entry = readdir(dir)) != NULL)
	{
		if (ft_match_pattern(entry->d_name, pattern))
		{
			printf("%s\n", entry->d_name);
		}
	}
	closedir(dir);
}

int	main(void)
{
	const char	*pattern;

	pattern = readline("Enter the pattern: ");
	printf("Files with wildcard pattern '%s':\n", pattern);
	listFilesWithWildcard(pattern);
	return (0);
}
