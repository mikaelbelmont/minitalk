/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarreto <mbarreto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:51:59 by mbarreto          #+#    #+#             */
/*   Updated: 2022/07/28 18:23:25 by mbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_writemnsg(int signal)
{
	static int	binary[] = {128, 64, 32, 16, 8, 4, 2, 1};
	static int	i = 0;
	static char	c = 0;

	if (signal == SIGUSR1)
		i++;
	if (signal == SIGUSR2)
		c += binary[i++];
	if (i >= 8)
	{
		if (c != 0)
			write(1, &c, 1);
		else
			write(1, "\n", 1);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_printf("PID: %u\n", getpid());
	signal(SIGUSR1, ft_writemnsg);
	signal(SIGUSR2, ft_writemnsg);
	while (1)
		pause();
	return (0);
}
