/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarreto <mbarreto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:51:57 by mbarreto          #+#    #+#             */
/*   Updated: 2022/07/28 18:19:53 by mbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_isnull(int pid, char c)
{
	int	shift;

	shift = 8;
	while (--shift >= 0)
	{
		if ((c >> shift & 1) == 0)
		{
			kill(pid, SIGUSR1);
			usleep(80);
		}
		else if ((c >> shift & 1) == 1)
		{
			kill(pid, SIGUSR2);
			usleep(80);
		}
	}
}

static void	ft_sendmnsg(int pid, char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		ft_isnull(pid, str[i]);
	ft_isnull(pid, 0);
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		ft_printf("Number of arguments needs to be 2!\n");
		return (0);
	}
	pid = ft_atoi(av[1]);
	ft_sendmnsg(pid, av[2]);
}
