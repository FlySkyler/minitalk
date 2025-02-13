/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 18:45:37 by antbonin          #+#    #+#             */
/*   Updated: 2025/02/13 18:48:04 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "../libft/ressource/libft.h"

void ft_test(char *str)
{
    while(*str)
    {
        ft_putchar_fd(*str, 1);
        str++;
    }
}