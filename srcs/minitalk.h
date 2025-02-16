/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antbonin <antbonin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:33:48 by antbonin          #+#    #+#             */
/*   Updated: 2025/02/14 11:41:29 by antbonin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <sys/types.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <stdbool.h>
# include "../libft/ressource/libft.h"

/**********************************************/

void Signal(int, void *handler, bool use_restart);
void Kill(pid_t pid, int signum);

#endif