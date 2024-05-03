/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: kgalstya <marvin@42.fr>                    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/05/03 19:27:45 by kgalstya          #+#    #+#             */
/*   Updated: 2024/05/03 19:27:45 by kgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "Printf/ft_printf.h"
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// server//

void	ft_signal_control(int x);
void	ft_bit(int x);

// client//

void	ft_send_signal(int pid, char *str);
int		ft_atoi(const char *nptr);

// bonus part//

void	ft_bit_bon(int x, siginfo_t *info, void *context);
void	ft_signal_control_bon(int x, siginfo_t *info, void *context);
void	messege_is_send(int y);
int		ft_atoi_bon(const char *nptr);
void	ft_send_signal_bon(int pid, char *str);

#endif
