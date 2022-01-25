#include "philo.h"

int	mutex_init(t_all *all)
{
	int	i;

	i = 0;
	while (i < all->num_of_phs)
	{
		if (pthread_mutex_init(&all->forks[i], NULL))
			return (error_print("Mutex init error"));
		i++;
	}
	if (pthread_mutex_init(&all->output_mutex, NULL))
		return (error_print("Mutex init error"));
	return (0);
}

int	parsing(t_all *all, char **argv)
{
	all->num_of_phs = ft_atoi(argv[1]);
	all->die_time = ft_atoi(argv[2]);
	all->eat_time = ft_atoi(argv[3]);
	all->sleep_time = ft_atoi(argv[4]);
	if (all->num_of_phs < 1 || all->num_of_phs > 200 || \
		all->die_time < 60 || all->eat_time < 60 || \
		all->sleep_time < 60)
		return (-1);
	if (argv[5])
	{
		all->nums_of_eatings = ft_atoi(argv[5]);
		if (all->nums_of_eatings <= 0)
			return (-1);
		all->fl_eats = 1;
	}
	else
		all->fl_eats = 0;
	all->ff = 0;
	all->forks = malloc(sizeof(pthread_mutex_t) * all->num_of_phs);
	if (!all->forks || mutex_init(all) == -1)
		return (-1);
	return (0);
}
