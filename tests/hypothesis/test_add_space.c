/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_add_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 00:29:28 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/11 00:33:51 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

void add_spaces(char* input) {
    const char* specials = "|&()<>";  // Special characters to add spaces around
    const char* doubles = "|<>";     // Special characters that can be doubled

    char* buffer = (char*) malloc(strlen(input) * 2 + 1);
    int j = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        if (strchr(specials, input[i]) != NULL) {
            if (i > 0 && strchr(doubles, input[i]) != NULL && input[i] == input[i-1]) {
                // Special character is doubled, add it without spaces
                buffer[j++] = input[i];
            } else if (input[i] == '&' && input[i+1] == '&') {
                // Special case: double &&, add it without spaces
                buffer[j++] = input[i];
                buffer[j++] = input[i+1];
                i++;  // skip the second &
            } else {
                // Special character is not doubled or is a single &, add spaces around it
                buffer[j++] = ' ';
                buffer[j++] = input[i];
                buffer[j++] = ' ';
            }
        } else {
            // Normal character, copy it to output buffer
            buffer[j++] = input[i];
        }
    }

    // Add null terminator to output buffer
    buffer[j] = '\0';

    // Copy output buffer back to input string
    strcpy(input, buffer);

    // Free output buffer
    free(buffer);
}

int main() {
    char *input;

    //  = "cat|grep 'hello' && echo 'world' >> output.txt"
    input = readline("Enter you string: ");
    printf("Original string: %s\n", input);
    add_spaces(input);
    printf("Modified string: %s\n", input);
    return 0;
}
