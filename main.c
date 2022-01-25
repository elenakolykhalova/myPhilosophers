#include "philo.h"

void	*pfilo_live(void *data)
{
	t_philo	*phil;

	phil = (t_philo *)data;
	if (phil->all->num_of_phs == 1)
		phil->time_eating = timer(phil->all->start);
	while (1)
	{
		take_forks(phil);
		eating(phil);
		sleeping_thinking(phil);
	}
	return (NULL);
}

void	start_threads(t_all *all, t_philo *ph)
{
	int	i;

	i = 0;
	while (i < all->num_of_phs)
	{
		if (i == 0)
			ph[i].left_fork = &all->forks[all->num_of_phs - 1];
		else
			ph[i].left_fork = &all->forks[i - 1];
		ph[i].rigth_fork = &all->forks[i];
		ph[i].num_eats = 0;
		ph[i].all = all;
		ph[i].id = i + 1;
		i++;
	}
	i = 0;
	gettimeofday(&all->start, NULL);
	while (i < all->num_of_phs)
	{
		pthread_create(&ph[i].thr, NULL, pfilo_live, &ph[i]);
		usleep(800);
		i++;
	}
}

int	finish_program(t_philo *ph)
{
	if (ph->all->fl_eats == 1)
		while (check_death(ph) == 0 && check_eats(ph) == 0)
			usleep(800);
	else
		while (check_death(ph) == 0)
			usleep(800);
	clear_mutex(ph);
	return (0);
}

int	main(int ac, char **argv)
{
	t_all	all;
	t_philo	*ph;

	ph = NULL;
	if (ac != 6 && ac != 5)
		return (error_print("ERROR number of arguments\n"));
	if (parsing(&all, argv) == -1)
		return (error_print("ERROR input data format\n"));
	ph = malloc(sizeof(t_philo) * all.num_of_phs);
	if (!ph)
		error_print("ERROR malloc\n");
	start_threads(&all, ph);
	finish_program(ph);
	return (0);
}
