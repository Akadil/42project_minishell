/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expansion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 23:23:24 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/20 23:26:48 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* ft_expand(char* str) {
    char* expanded = malloc(strlen(str) + 1);
    char* token;
    char* variable;
    char* value;
    char* expanded_var;

    strcpy(expanded, str);  // Copy the input string to the expanded string

    // Find the first occurrence of '$'
    token = strchr(expanded, '$');

    while (token != NULL) {
        // Check if the variable is inside double quotes
        int is_double_quoted = 0;
        char* quote_before_token = token - 1;
        while (quote_before_token >= expanded && *quote_before_token != '$') {
            if (*quote_before_token == '\"') {
                is_double_quoted = !is_double_quoted;
            }
            quote_before_token--;
        }

        // If the variable is not inside single quotes or double quotes, expand it
        if (!is_double_quoted && (quote_before_token < expanded || *quote_before_token != '\'')) {
            // Find the end of the variable name
            variable = token + 1;
            while (*variable != '\0' && *variable != ' ' && *variable != '$') {
                variable++;
            }

            // Extract the variable name
            size_t var_len = variable - (token + 1);
            char* var = malloc(var_len + 1);
            strncpy(var, token + 1, var_len);
            var[var_len] = '\0';

            // Get the value of the environment variable
            value = getenv(var);

            // If the environment variable exists, expand it
            if (value != NULL) {
                // Calculate the expanded variable length
                size_t expanded_var_len = strlen(value) + strlen(expanded) - var_len + 1;

                // Create a new expanded variable string
                expanded_var = malloc(expanded_var_len);

                // Copy the part before the variable
                strncpy(expanded_var, expanded, token - expanded);

                // Copy the expanded value of the variable
                strcat(expanded_var, value);

                // Copy the rest of the original string
                strcat(expanded_var, variable);

                // Free the original expanded string and update it with the expanded variable
                free(expanded);
                expanded = expanded_var;
            }

            // Free the variable name
            free(var);
        }

        // Find the next occurrence of '$'
        token = strchr(token + 1, '$');
    }

    // Remove single quotes inside double quotes
    char* double_quotes = strchr(expanded, '\"');
    while (double_quotes != NULL) {
        char* next_double_quotes = strchr(double_quotes + 1, '\"');
        if (next_double_quotes != NULL) {
            char* single_quotes = strchr(double_quotes, '\'');
            while (single_quotes != NULL && single_quotes < next_double_quotes) {
                memmove(single_quotes, single_quotes + 1, strlen(single_quotes));
                single_quotes = strchr(single_quotes + 1, '\'');
            }
        }
        double_quotes = next_double_quotes;
    }

    // Remove double quotes inside single quotes
    char* single_quotes = strchr(expanded, '\'');
    while (single_quotes != NULL) {
        char* next_single_quotes = strchr(single_quotes + 1, '\'');
        if (next_single_quotes != NULL) {
            char* double_quotes = strchr(single_quotes, '\"');
            while (double_quotes != NULL && double_quotes < next_single_quotes) {
                memmove(double_quotes, double_quotes + 1, strlen(double_quotes));
                double_quotes = strchr(double_quotes + 1, '\"');
            }
        }
        single_quotes = next_single_quotes;
    }

    return expanded;
}

int main() {
    char *str = "Hello $USER! Today is '\"$DAY\"' and '\"$HOME\"'.";
    char* expanded = ft_expand(str);

    printf("Expanded: %s\n", expanded);

    free(expanded);

    return 0;
}
