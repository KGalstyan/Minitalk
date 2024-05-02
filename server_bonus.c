/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:18:33 by kgalstya          #+#    #+#             */
/*   Updated: 2024/05/02 21:54:41 by kgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_bit(int x)
{
	static int	bit;
	static int	i;

	if (x == 1)
		i |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &i, 1);
		bit = 0;
		i = 0;
	}
}

void	ft_signal_control(int x)
{
	if (x == SIGUSR1)
		ft_bit(1);
	else
		ft_bit(0);
}

int	main(int argc, char **argv)
{
	int	pid;
    struct sigaction action;

	(void)argv;
	if (argc != 1)
	{
		printf("ERROR\n");
		return (0);
	}
	pid = getpid();
	printf("Pid--> %u\n", pid);
    action.sa_handler = ft_signal_control;
    sigemptyset(&action.sa_mask);
    action.sa_flags = SA_SIGINFO;
	while (1)
	{
		signal(SIGUSR1, ft_signal_control);
		signal(SIGUSR2, ft_signal_control);
		pause();
	}
	return (0);
}