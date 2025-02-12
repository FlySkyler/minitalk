/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*x                                                    +:+ +:+
	+:+     */
/*   By: antbonin <antbonin@student.42.fr>i          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#t+
	+#+           */
/*   Created: 2025/02/12 16:33:28 by antbonin          #+#    #+#             */
/*   Updated: 2025/02/12 17:40:33 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _POSIX_C_SOURCE 200809L
#include "libft/ressource/libft.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

static int	g_running = 1; // Global flag to control program execution

void	cleanup(void)
{
	printf("\nCleaning up and exiting...\n");
	// Add any cleanup code here
}

void	signal_handler(int signum)
{
	if (signum == SIGINT || signum == SIGTERM)
	{
		g_running = 0; // Set flag to exit main loop
		cleanup();
		exit(0);
	}
	printf("Received signal %d\n", signum);
}

int	main(void)
{
	struct sigaction action;
	action.sa_handler = signal_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;

	sigaction(SIGINT, &action, NULL);
	sigaction(SIGTERM, &action, NULL);

	int i = 0;
	pid_t pid = getpid(); // Get current process ID
    
	while (g_running)
	{
		i++;
		ft_printf("%d", i);
		if (i == 13)
		{
			kill(pid, SIGINT); // Send SIGINT to our own process
			break;
		}
	}

	return (0);
}