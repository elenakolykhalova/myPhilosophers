#include "philo.h"

void	take_forks(t_philo *phil)
{
	pthread_mutex_lock(phil->left_fork);
	if (phil->all->ff == 0)
		printf("%d %d has taken fork\n", \
		timer(phil->all->start), phil->id);
	pthread_mutex_lock(phil->rigth_fork);
	if (phil->all->ff == 0)
		printf("%d %d has taken fork\n", \
		timer(phil->all->start), phil->id);
}

void	eating(t_philo *phil)
{
	pthread_mutex_lock(&phil->all->output_mutex);
	if (phil->all->ff == 0)
		printf("%d %d is eating\n", \
		timer(phil->all->start), phil->id);
	pthread_mutex_unlock(&phil->all->output_mutex);
	if (phil->all->fl_eats == 1)
		phil->num_eats++;
	phil->time_eating = timer(phil->all->start);
	usleep(800 * phil->all->eat_time);
	pthread_mutex_unlock(phil->left_fork);
	pthread_mutex_unlock(phil->rigth_fork);
}

void	sleeping_thinking(t_philo *phil)
{
	pthread_mutex_lock(&phil->all->output_mutex);
	if (phil->all->ff == 0)
		printf("%d %d is sleeping\n", \
		timer(phil->all->start), phil->id);
	pthread_mutex_unlock(&phil->all->output_mutex);
	usleep(800 * phil->all->sleep_time);
	pthread_mutex_lock(&phil->all->output_mutex);
	if (phil->all->ff == 0)
		printf("%d %d is thinking\n", \
		timer(phil->all->start), phil->id);
	pthread_mutex_unlock(&phil->all->output_mutex);
}
