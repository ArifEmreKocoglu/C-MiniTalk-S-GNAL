/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocoglu <akocoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:51:16 by akocoglu          #+#    #+#             */
/*   Updated: 2022/04/05 15:20:54 by akocoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_to_server(int pid, char *str)
{
	size_t	size;

	size = 0;
	while (str[size] != '\0')
	{
		if (str[size] == '1')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		size++;
		usleep(80);
	}
}

char	*char_to_bit(char *str)
{
	char	*l;
	int		size;
	int		m;
	int		counter;

	counter = ft_strlen(str) - 1;
	size = (counter + 1) * 8 ;
	l = (char *)malloc((size * sizeof(char)));
	l[size--] = '\0';
	while (counter >= 0)
	{
		m = (int)str[counter];
		while (m != 0)
		{
			l[size--] = (m % 2) + '0';
			m = m / 2;
			if (m == 0)
			{
				l[size] = 0 + '0';
				size--;
			}
		}
		counter--;
	}
	return (l);
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc != 3)
	{
		write(1, "2 ARGÜMAN OLMALI", 17);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	str = char_to_bit(argv[2]);
	send_to_server(pid, str);
	send_to_server(pid, "00001010");
	return (0);
}
