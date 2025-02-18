/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 17:12:01 by antbonin          #+#    #+#             */
/*   Updated: 2025/02/18 18:42:59 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/ressource/libft.h"
#include "minitalk.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(size);
	if (!new_ptr)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	if (ptr)
	{
		ft_memcpy(new_ptr, ptr, size);
		free(ptr);
	}
	return (new_ptr);
}

void	process_char(char c, char **str, size_t *len)
{
	char	*new_str;

	if (c == '\0')
	{
		if (*str)
		{
			printf("%s\n", *str);
			free(*str);
			*str = NULL;
			*len = 0;
		}
	}
	else
	{
		new_str = ft_realloc(*str, *len + 2);
		if (!new_str)
		{
			perror("ft_realloc");
			exit(EXIT_FAILURE);
		}
		*str = new_str;
		(*str)[*len] = c;
		(*str)[*len + 1] = '\0';
		(*len)++;
	}
}

void	signal_handler(int signum)
{
	static char		c = 0;
	static int		bit = 0;
	static char		*str = NULL;
	static size_t	len = 0;

	if (signum == SIGUSR1)
		c |= (1 << bit);
	else if (signum == SIGUSR2)
		c &= ~(1 << bit);
	bit++;
	if (bit == 8)
	{
		process_char(c, &str, &len);
		c = 0;
		bit = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = signal_handler;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) ==
		-1)
	{
		perror("sigaction");
		exit(EXIT_FAILURE);
	}
	printf("PID : %d\n", getpid());
	while (1)
	{
		pause();
	}
	return (EXIT_SUCCESS);
}
