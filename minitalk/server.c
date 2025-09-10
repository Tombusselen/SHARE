/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbussele <tbussele@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:28:11 by tbussele          #+#    #+#             */
/*   Updated: 2025/08/28 11:59:43 by tbussele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	decrypt(int signal, siginfo_t *origin, void *context)
{
	static unsigned char	c;
	static int				bits;

	(void)context;
	if (signal == SIGUSR2)
		c = c << 1;
	else if (signal == SIGUSR1)
		c = c << 1 | 0b00000001;
	bits++;
	if (bits == 8)
	{
		write(1, &c, 1);
		c = 0;
		bits = 0;
	}
	usleep(100);
	kill(origin->si_pid, SIGUSR1);
}

int	main(void)
{
	int					pid;
	struct sigaction	action;

	action.sa_sigaction = decrypt;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO | SA_RESTART;
	pid = getpid();
	printf("PID du serveur: %d\n", pid);
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
