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
#include "unistd.h"

void	send_char(char c, pid_t pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if (c & (1 << bit))
		{
			if (kill(pid, SIGUSR1) < 0)
			{
				perror("Kill error");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) < 0)
			{
				perror("Kill error");
				exit(EXIT_FAILURE);
			}
		}
		usleep(400);
		bit++;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;
	char	*message;
	int		error;

	if (ac != 3)
	{
		ft_putendl_fd("Error", 2);
		return (EXIT_FAILURE);
	}
	error = 0;
	pid = ft_atoi(av[1], &error);
	if (error == -1)
	{
		ft_putendl_fd("Error", 2);
		return (EXIT_FAILURE);
	}
	message = av[2];
	while (*message)
		send_char(*message++, pid);
	send_char('\0', pid);
	return (EXIT_SUCCESS);
}
