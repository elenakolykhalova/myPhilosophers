#include "philo.h"

int	clear_mutex(t_philo *ph)
{
	int	i;

	i = 0;
	while (i < ph->all->num_of_phs)
	{
		if (pthread_mutex_unlock(&ph->all->forks[i]) != 0)
			return (error_print("ERROR mutex_unlock\n"));
		if (pthread_mutex_destroy(&ph->all->forks[i]) == EBUSY)
			return (error_print("ERROR mutex_destroy\n"));
		if (pthread_detach(ph[i].thr))
			return (error_print("ERROR pthread_detach\n"));
		i++;
	}
	usleep(800);
	if (pthread_mutex_unlock(&ph->all->output_mutex))
		return (error_print("ERROR mutex_unlock\n"));
	usleep(800);
	if (pthread_mutex_destroy(&ph->all->output_mutex) == EBUSY)
		return (error_print("ERROR mutex_destroy\n"));
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	error_print(char *str)
{
	write(2, str, ft_strlen(str));
	return (-1);
}
