#include "minitalk.h"

void	ft_writemnsg(int signal)
{
	static int c = 0;

	if (signal == SIGUSR1)
		c++;
	else if (signal == SIGUSR2)
	{
		write(1, &c, 1);
		c = 0;
	}
}

int main()
{
	ft_printf("PID: %u\n", getpid()); 
	signal(SIGUSR1, ft_writemnsg);
	signal(SIGUSR2, ft_writemnsg);
	while (1)
		pause();
	return (0);
}