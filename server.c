/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bouh <mel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 21:02:43 by mel-bouh          #+#    #+#             */
/*   Updated: 2024/01/05 17:47:01 by mel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned char	bytetochar(char *base)
{
	unsigned char	c;
	int				i;

	c = 0;
	i = 0;
	while (i < BYTESIZE)
	{
		c = c * 2 + (base[i] - '0');
		i++;
	}
	return (c);
}

void	handlesig(int sig)
{
	unsigned char	c;
	static int		i;
	static char		base[9];

	if (base[0] == 0)
		setbase(base);
	if (sig == SIGUSR1)
		base[i] = '1';
	i++;
	if (i == 8)
	{
		c = bytetochar(base);
		write(1, &c, 1);
		setbase(base);
		i = 0;
	}
}

int	main(void)
{
	int		pid;
	t_sig	sa;

	pid = getpid();
	sa.sa_handler = handlesig;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	sigemptyset(&sa.sa_mask);
	ft_printf("%d\n", pid);
	while (1)
		usleep(50);
}
