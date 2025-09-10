/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <tbussele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:24:44 by tbussele          #+#    #+#             */
/*   Updated: 2025/08/29 12:32:45 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_server_ready = 0;

void	signal_received(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	(void)info;
	g_server_ready = 1;
}

void	send_signal(int pid, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (j < 8)
		{
			if (((str[i] >> (7 - j)) & 1) == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			g_server_ready = 0;
			while (g_server_ready == 0)
				pause();
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	reaction;

	reaction.sa_sigaction = signal_received;
	sigemptyset(&reaction.sa_mask);
	reaction.sa_flags = SA_SIGINFO | SA_RESTART;
	if (argc != 3)
	{
		ft_printf("arguments error");
		exit (0);
	}
	sigaction(SIGUSR1, &reaction, NULL);
	send_signal(ft_atoi(argv[1]), argv[2]);
	return (0);
}
