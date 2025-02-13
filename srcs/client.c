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

#include "unistd.h"
#include "../libft/ressource/libft.h"
#include "minitalk.h"

int	main(int ac, char **av)
{
    if (ac == 3)
    {
        int error = 0;
        int i = ft_atoi(av[1], &error);
        ft_printf("%d\n", i);
        return (0);
    }
    return (1);
}
