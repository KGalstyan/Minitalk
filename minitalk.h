/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:33:09 by kgalstya          #+#    #+#             */
/*   Updated: 2024/04/22 16:33:23 by kgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
//# include "Printf/ft_printf.h"

// server//

void	ft_signal_control(int x);
void	ft_bit(int x);

// client//

void	ft_send_signa(int pid, char *str);
int		ft_atoi(const char *nptr);

#endif
