/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:09:46 by mescoda           #+#    #+#             */
/*   Updated: 2024/12/09 12:01:17 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(size_t temp)
{
	size_t	start;

	start = curr_time();
	while (curr_time() - start < temp)
		usleep(500);
	return (0);
}

void	destroy_all(char *str, t_program *program, \
	pthread_mutex_t *forks, int philo_nb, int err)
{
	int	i;

	i = 0;
	//printf("-----------------DESTROYING ALL-----------------\n");
	if (err == 1)
		printf(RED"Error: "RESET);
	if (*str)
		printf("%s\n", str);
	//printf("Begining to destroy all mutex.\n");
	pthread_mutex_destroy(&program->dead_lock);
	//printf(RED"Dead lock has been destroyed.\n"RESET);
	pthread_mutex_destroy(&program->eat_lock);
	//printf(RED"Eat lock has been destroyed.\n"RESET);
	pthread_mutex_destroy(&program->write_lock);
	//printf(RED"Write lock has been destroyed.\n"RESET);
	//printf(RED"All mutex has been destroyed.\n"RESET);
	//printf("nb philo = %d\n", philo_nb);
	while (i < philo_nb)
	{
		pthread_mutex_destroy(&forks[i]);
		//printf("Fork %d has been destroyed.\n", i);
		i++;
	}
	//printf("All mutex has been destroyed.\n");
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
		printf("Error: gettimeof day() doesn't work.\n");
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
