/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:12:01 by antbonin          #+#    #+#             */
/*   Updated: 2025/02/19 16:33:40 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/ressource/libft.h"
#include "minitalk.h"
#include <stdlib.h>

void	add_message(t_message *message, char c)
{
	char	*str;

	str = malloc(2);
	if (!str)
		return ;
	str[0] = c;
	str[1] = '\0';
	ft_lstadd_back(&message->list, ft_lstnew(str));
}

void	clear_and_print_message(t_message *message)
{
	t_list	*current;

	current = message->list;
	while (current)
	{
		ft_printf("%s", (char *)current->content);
		current = current->next;
	}
	ft_printf("\n");
	ft_lstclear(&message->list, free);
	message->list = NULL;
}

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static t_message	message = {NULL, 0, 0};

	(void)context;
	if (signal == SIGUSR1)
		message.char_c |= (0x01 << message.bit);
	message.bit++;
	if (message.bit == 8)
	{
		if (message.char_c == '\0')
			clear_and_print_message(&message);
		else
			add_message(&message, message.char_c);
		message.char_c = 0;
		message.bit = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction	act;
	pid_t				pid;

	(void)argv;
	act.sa_sigaction = handle_signal;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	if (argc != 1)
	{
		ft_printf("Error");
		return (1);
	}
	pid = getpid();
	ft_printf("PID : %d\n", pid);
	while (1)
		pause();
	return (0);
}
