/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akocoglu <akocoglu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:48:12 by akocoglu          #+#    #+#             */
/*   Updated: 2022/04/05 15:20:57 by akocoglu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_pow(int power)
{
	int	base;

	base = 1;
	while (power > 0)
	{
		base = base * 2;
		power --;
	}
	return (base);
}

void	binary_to_char(char *str)
{
	int		i;
	int		str_size;
	int		sum;
	char	l;

	sum = 0;
	i = 0;
	str_size = ft_strlen(str) - 1;
	while (i <= str_size)
	{
		if (str[i] == '1')
			sum = sum + ft_pow(str_size - i);
		i++;
	}
	l = sum;
	write(1, &l, 1);
}

char	*add(char *l, char a)
{
	char	*str;
	size_t	size;
	size_t	i;

	size = ft_strlen(str);
	str = (char *) malloc (size + 2);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (l[i] != '\0')
	{
		str[i] = l[i];
		i++;
	}
	str[i] = a;
	str[i + 1] = '\0';
	free(l);
	return (str);
}

void	sig_control(int sig)
{
	static char	*l;
	static int	i;

	i++;
	if (l == NULL)
	{
		l = ft_strdup("");
		i = 1;
	}
	if (sig == SIGUSR2)
	{
		l = add(l, '0');
	}
	else
	{
		l = add(l, '1');
	}
	if (i == 8)
	{
		binary_to_char(l);
		free(l);
		l = NULL;
	}
}

int	main(void)
{
	ft_printf("Server PID: %u\n", getpid());
	signal(SIGUSR1, sig_control);
	signal(SIGUSR2, sig_control);
	while (1)
	{
		pause();
	}
	return (0);
}
