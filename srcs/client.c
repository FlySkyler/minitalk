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

#include "../libft/ressource/libft.h"
#include "minitalk.h"

void	handle_ack(int signal)
{
	(void)signal;
	g_ack = 0;
}

void	send_char(pid_t pid, unsigned char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 1 << i)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_ack)
			pause();
		g_ack = 1;
		i++;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	act;
	int					i;

	i = 0;
	act.sa_handler = handle_ack;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &act, NULL);
	if (argc != 3 || ft_atoi(argv[1]) <= 0)
	{
		ft_printf("Error");
		return (1);
	}
	while (argv[2][i])
		send_char(ft_atoi(argv[1]), argv[2][i++]);
	send_char(ft_atoi(argv[1]), '\0');
	return (0);
}
