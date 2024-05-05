/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:18:33 by kgalstya          #+#    #+#             */
/*   Updated: 2024/05/04 20:20:27 by kgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_bit(int x, siginfo_t *info, void *context)
{
	static int	bit;
	static int	i;

	(void)info;
	(void)context;
	if (x == 1)
		i |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		if (i == 10)
			kill(info->si_pid, SIGUSR1);
		write(1, &i, 1);
		bit = 0;
		i = 0;
	}
}

void	ft_signal_control(int x, siginfo_t *info, void *context)
{
	if (x == SIGUSR1)
		ft_bit(1, info, context);
	else
		ft_bit(0, info, context);
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	action;

	(void)argv;
	if (argc != 1)
	{
		write(2, "ERROR\n", 1);
		return (0);
	}
	pid = getpid();
	ft_printf("Pid--> %u\n", pid);
	action.sa_sigaction = ft_signal_control;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	while (1)
	{
		sigaction(SIGUSR1, &action, NULL);
		sigaction(SIGUSR2, &action, NULL);
		pause();
	}
	return (0);
}
