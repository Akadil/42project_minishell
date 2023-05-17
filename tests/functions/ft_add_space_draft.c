// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ft_add_spaces.c                                    :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/05/11 00:12:17 by akalimol          #+#    #+#             */
// /*   Updated: 2023/05/16 13:57:49 by akalimol         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include <stdlib.h>
// #include <stdio.h>

// char    *ft_is_metacharacter(char c1, char c2)
// {
//     if (c1 == '|' && c2 == '|')
//         return ("||");
//     if (c1 == '|')
//         return ("|"); 
//     if (c1 == '&' && c2 == '&')
//         return ("&&"); 
//     if (c1 == '(')
//         return ("("); 
//     if (c1 == ')')
//         return (")"); 
//     if (c1 == '<' && c2 == '<')
//         return ("<<");
//     if (c1 == '<')
//         return ("<"); 
//     if (c1 == '>' && c2 == '>')
//         return (">>");
//     if (c1 == '>')
//         return (">");
//     return (NULL);
// }

// int ft_isspace(char c)
// {
//     if (c == ' ' || c == '\f' || c == '\n')
//         return (1);
//     if (c == '\r' || c == '\t' || c == '\v')
//         return (1);
//     return (0);
// }

// void    ft_cat(char *string, int *j, int *i, char *meta)
// {
//     int size;

//     size = 0;
//     string[*j] = ' ';
//     *j == *j + 1;
//     while (meta && meta[size])
//     {
//         string[*j] = meta[size];
//         *j == *j + 1;
//         size++;
//     }
//     string[*j] = ' ';
//     *j == *j + 1;
//     if (size == 2)
//         *i = *i + 1;
// }


// char    *ft_add_spaces(char *str)
// {
//     char    *string;
//     char    *meta;
//     int     i;
//     int     size;
//     int     j;

//     // This fragment can be removed as a ft_find_num_meta() -> int
//     i = 0;
//     size = 0;
//     while (str[i])
//     {
//         if (ft_is_metacharacter(str[i], str[i + 1]) != 0)
//             size++;
//         i++;
//     }
//     // --------------------- The end ------------------------------

//     string = (char *)malloc(sizeof(char) * (i + size * 2 + 1));
//     i = 0;
//     j = 0;
//     while (str[i])
//     {
//         if (ft_isspace(str[i]) == 1)
//             string[j++] = ' ';

//         if ((meta = ft_is_metacharacter(str[i], str[i + 1])))
//             ft_cat(string, &j, &i, meta);

//         else if (str[i] == '|' && str[i + 1] == '|')
//         {
//             string[j++] = ' ';
//             string[j++] = '|';
//             string[j++] = '|';
//             string[j++] = ' ';
//             i++;
//         }
//         else if (str[i] == '|' && str[i + 1] != '|')
//         {
//             string[j++] = ' ';
//             string[j++] = '|';
//             string[j++] = ' ';
//         }
//         else if (str[i] == '<' && str[i + 1] == '<')
//         {
//             string[j++] = ' ';
//             string[j++] = '<';
//             string[j++] = '<';
//             string[j++] = ' ';
//             i++;
//         }
//         else if (str[i] == '<')
//         {
//             string[j++] = ' ';
//             string[j++] = '<';
//             string[j++] = ' ';
//         }
//         else if (str[i] == '>' && str[i + 1] == '>')
//         {
//             string[j++] = ' ';
//             string[j++] = '>';
//             string[j++] = '>';
//             string[j++] = ' ';
//             i++;
//         }
//         else if (str[i] == '>')
//         {
//             string[j++] = ' ';
//             string[j++] = '>';
//             string[j++] = ' ';
//         }
//         else if (str[i] == '&' && str[i + 1] == '&')
//         {
//             string[j++] = ' ';
//             string[j++] = '&';
//             string[j++] = '&';
//             string[j++] = ' ';
//             i++;
//         }
//         else if (str[i] == '(')
//         {
//             string[j++] = ' ';
//             string[j++] = '(';
//             string[j++] = ' ';
//         }
//         else if (str[i] == ')')
//         {
//             string[j++] = ' ';
//             string[j++] = ')';
//             string[j++] = ' ';
//         }
//         else
//             string[j++] = str[i];
//         i++;
//     }
//     string[j] = '\0';
//     i = 0;
//     j = 0;
//     while (string[i])
//     {
//         if (string[i] != ' ' || (i != 0 && string[j - 1] != ' '))
//             string[j++] = string[i];
//         i++;
//     }
//     string[j] = '\0';
//     free(str);
//     return (string);
// }

// void    ft_remove_extra_spaces(char *str)
// {
//     int i;
//     int j;

//     i = 0;
//     while (str[i])
//     {

//     }


//     j = 0;
//     while (str[i])
//     {
//         if (str[i] != ' ' || (i != 0 && str[j - 1] != ' '))
//             str[j++] = str[i];
//         i++;
//     }
//     str[j] = '\0';
// }