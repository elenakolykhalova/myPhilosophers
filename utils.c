#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (c);
	else
		return (0);
}

static int	utils(int res, int sign, int k)
{
	if (k >= 19)
	{
		if (sign == -1)
			res = 0;
		else
			res = -1;
	}
	return (res);
}

int	ft_atoi(const char *str)
{
	int			rez;
	int			sign;
	int			k;
	size_t		i;

	i = 0;
	sign = 1;
	rez = 0;
	k = 1;
	while ((*(str + i) == '\t' || *(str + i) == '\n' || *(str + i) == '\v'\
			|| *(str + i) == '\f' || *(str + i) == '\r' || *(str + i) == ' '))
		i++;
	if ((*(str + i) == '-' || *(str + i) == '+') && ft_isdigit(*(str + i + 1)))
	{
		if (*(str + i) == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(*(str + i)))
	{
		rez = rez * 10 + (*(str + i++) - '0');
		k++;
	}
	return (sign * utils(rez, sign, k));
}

int	timer(struct timeval start)
{
	struct timeval	end;

	gettimeofday(&end, NULL);
	return (((end.tv_sec * 1000000 + end.tv_usec) - \
	(start.tv_sec * 1000000 + start.tv_usec)) / 1000);
}
