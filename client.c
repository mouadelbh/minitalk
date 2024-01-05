/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-bouh <mel-bouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 21:57:31 by mel-bouh          #+#    #+#             */
/*   Updated: 2024/01/05 17:38:33 by mel-bouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	sendchar(int pid, char *base)
{
	int	i;

	i = 0;
	while (i < BYTESIZE)
	{
		if (base[i] == '1')
		{
			if (kill(pid, SIGUSR1) == -1)
				return (0);
		}
		else if (base[i] == '0')
		{
			if (kill(pid, SIGUSR2) == -1)
				return (0);
		}
		i++;
		usleep(50);
	}
	return (1);
}

int	chartobyte(int pid, char *str)
{
	int		tmp;
	char	base[9];
	int		i;
	int		j;

	i = 0;
	setbase(base);
	while (str[i])
	{
		check(str, &i);
		tmp = str[i];
		j = 7;
		while (tmp)
		{
			base[j--] = tmp % 2 + '0';
			tmp /= 2;
		}
		if (!sendchar(pid, base))
			return (0);
		usleep(50);
		setbase(base);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid <= 0)
			ft_printf("pid is not valid.\n");
		else if (kill(pid, 0) == -1)
			ft_printf("Process not found.\n");
		else if (!chartobyte(pid, av[2]))
			ft_printf("Failed to send signal.\n");
	}
	return (0);
}
