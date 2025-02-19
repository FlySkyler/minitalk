/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:55:37 by maximart          #+#    #+#             */
/*   Updated: 2025/02/19 16:32:21 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/ressource/libft.h"
# include <signal.h>

volatile sig_atomic_t	g_ack = 1;

typedef struct s_message
{
	t_list				*list;
	char				char_c;
	int					bit;
}						t_message;

#endif