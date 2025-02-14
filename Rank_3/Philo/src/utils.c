/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:09:46 by mescoda           #+#    #+#             */
/*   Updated: 2025/02/14 11:08:22 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(size_t temp)
{
	size_t	start;

	start = curr_time();
	while ((curr_time() - start) < temp)
		usleep(500);
	return (0);
}

void	destroy_all(char *str, t_program *program, \
	pthread_mutex_t *forks, int philo_nb)
{
	int	i;

	i = 0;
	if (*str)
		printf("%s\n", str);
	pthread_mutex_destroy(&program->dead_lock);
	pthread_mutex_destroy(&program->eat_lock);
	pthread_mutex_destroy(&program->write_lock);
	while (i < philo_nb)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

void	print_msg(char *str, t_philo *philo, int id)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = curr_time() - philo->start_time;
	if (!dead_loop(philo))
		printf("%zums Philo %d %s\n", time, id, str);
	pthread_mutex_unlock(philo->write_lock);
}

size_t	curr_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		print_msg(RED"ERROR: gettimeofday() doesn't work.\n"RESET, NULL, 0);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_atoi(const char *str)
{
	int	string;
	int	sign;

	string = 0;
	sign = 1;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		string = string * 10 + (*str - '0');
		str++;
	}
	return (string * sign);
}
