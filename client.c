/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgalstya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:18:37 by kgalstya          #+#    #+#             */
/*   Updated: 2024/05/04 19:56:12 by kgalstya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *nptr)
{
	int	num;
	int	sign;
	int	n;

	n = 0;
	sign = 1;
	num = 0;
	while ((nptr[n] >= 9 && nptr[n] <= 13) || nptr[n] == ' ')
		n++;
	if (nptr[n] == '-' || nptr[n] == '+')
	{
		if (nptr[n] == '-')
		{
			sign *= -1;
		}
		n++;
	}
	while (nptr[n] >= '0' && nptr[n] <= '9')
	{
		num = num * 10 + (nptr[n] - '0');
		n++;
	}
	return (num * sign);
}

void	ft_send_signal(int pid, char *str)
{
	int	bit;
	int	i;

	i = 0;
	while (str[i])
	{
		bit = 0;
		while (bit < 8)
		{
			if (str[i] & (1 << bit))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(75);
			bit++;
		}
		signal(SIGUSR1, messege_is_send);
		i++;
	}
}

void	messege_is_send(int y)
{
	if (y == SIGUSR1)
		write(1, "SENT\n", 5);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		write(2, "Error: wrong number of arguments\n", 33);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	ft_send_signal(pid, argv[2]);
	ft_send_signal(pid, "\n");
	return (0);
}
