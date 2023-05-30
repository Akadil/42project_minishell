/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_signal_basic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:13:53 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/30 14:42:04 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

pid_t child_pid = 0;  // Global variable to store child process ID

void handle_signal(int signum) {
    (void)signum;
    if (child_pid > 0) {
        kill(child_pid, SIGKILL);  // Terminate the child process
    }
}

int main() {
    // Set the signal handler in the parent process
    signal(SIGINT, handle_signal);

    // Fork a child process
    child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        return 1;
    } else if (child_pid == 0) {
        // Child process

        while (1) {
            // Child process logic here

            // Sleep or perform other operations
            usleep(100000); // Sleep for 100 milliseconds
        }

        // Child process cleanup code (optional)
        return 0;
    } else {
        // Parent process

        while (1) {
            // Parent process logic here

            // Sleep or perform other operations
            usleep(100000); // Sleep for 100 milliseconds
        }

        // Parent process cleanup code (optional)
        return 0;
    }
}
