#include "minitalk.h"

static void ft_sendmnsg(int pid, char *str)
{
	int i;
	int diff;

	i = 0;
	while (str[i])
	{
		diff = str[i];
		while (diff)
		{
			kill(pid, SIGUSR1);
			diff--;
			usleep(80);
		}
		kill(pid, SIGUSR2);
		i++;
	}
}

int main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
	{
		ft_printf("Number of arguments needs to be 2!\n");
	}
	pid = ft_atoi(av[1]);
	ft_sendmnsg(pid, av[2]);
}



	//usleep em miliseg pois nao ha buffer e se for muito rapido alguns
	//sinais podem ser ignorados
	
	//sleep é em segundo e um segundo pra 100 char é muito tempo