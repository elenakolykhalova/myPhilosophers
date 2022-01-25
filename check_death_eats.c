#include "philo.h"

int	check_death(t_philo *ph)
{
	int	i;
	int	time;

	i = 0;
	pthread_mutex_lock(&ph->all->output_mutex);
	while (i < ph->all->num_of_phs)
	{
		time = timer(ph->all->start) - ph[i].time_eating;
		if (time >= ph->all->die_time)
		{
			ph->all->ff = 1;
			printf("%d %d died\n", timer(ph->all->start), ph[i].id);
			return (1);
		}
		i++;
	}
	pthread_mutex_unlock(&ph->all->output_mutex);
	return (0);
}

int	check_eats(t_philo *ph)
{
	int	i;

	i = -1;
	while (++i < ph->all->num_of_phs)
	{
		if (ph[i].num_eats >= ph->all->nums_of_eatings)
			continue ;
		return (0);
	}
	pthread_mutex_lock(&ph->all->output_mutex);
	return (1);
}
