#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <errno.h>

typedef struct s_all
{
	int				num_of_phs;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				nums_of_eatings;
	int				fl_eats;
	int				ff;
	pthread_mutex_t	output_mutex;
	pthread_mutex_t	*forks;
	struct timeval	start;
}			t_all;

typedef struct s_philo
{
	int				num_eats;
	int				time_eating;
	int				id;
	t_all			*all;
	pthread_t		thr;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*rigth_fork;
}			t_philo;

int		parsing(t_all *all, char **argv);
void	take_forks(t_philo *phil);
void	eating(t_philo *phil);
void	sleeping_thinking(t_philo *phil);
void	print_cur_time(struct timeval start);
int		timer(struct timeval start);
int		ft_atoi(const char *str);
int		check_death(t_philo *ph);
int		check_eats(t_philo *ph);
int		clear_mutex(t_philo *ph);
int		error_print(char *str);

#endif