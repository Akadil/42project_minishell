/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_signals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:39:17 by akalimol          #+#    #+#             */
/*   Updated: 2023/05/01 16:06:01 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _XOPEN_SOURCE 700

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>



void handle_signal(int sig) {
    printf("Received signal %d\n", sig);
    exit(0);
}

int main() {
    struct sigaction sa;
    sa.sa_handler = &handle_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);

    // Loop indefinitely
    while(1) {
        printf("Waiting for signal...\n");
        sleep(1);
    }

    return 0;
}
