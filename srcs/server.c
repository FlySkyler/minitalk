/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:12:01 by antbonin          #+#    #+#             */
/*   Updated: 2025/02/13 18:49:29 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "sys/types.h"
#include "stdio.h"
#include "stdlib.h"
#include "../libft/ressource/libft.h"
#include "minitalk.h"
#include <signal.h>

void signal_callback_handler(int signum)
{
   printf("Caught signal %d\n",signum); 
}

int main()
{
    pid_t pid = getpid();
   signal(SIGUSR1, signal_callback_handler);
   signal(SIGUSR2, signal_callback_handler);
   if (pid)
   ft_test("abcdef");
   ft_printf("\npid : %u\n", pid);
   while(1)
   {
      ft_printf("\n");
      sleep(10);
   }
   return EXIT_SUCCESS;
}