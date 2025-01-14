/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:37:15 by mescoda           #+#    #+#             */
/*   Updated: 2025/01/11 14:06:06 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
***	Checks if the philosopher is dead.
	This function checks if the philosopher is dead.
***	@param philo -> Pointer to the philosopher structure to be checked.
***	@return -> 1 if the philosopher is dead, 0 otherwise.
*/
int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->is_dead == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	else
		return (pthread_mutex_unlock(philo->dead_lock), 0);
}

/*
***	Philosopher routine.
	This function is the routine of the philosopher.
	Check first if the philosopher is an odd number.
	Check if the philosopher is dead, then makes him think, eat and sleep.
***	@param pointer -> Pointer to the philosopher structure.
*/
void	*ph_routine(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	if (philo->nb_philo == 1)
	{
		one_philo(philo);
		return (pointer);
	}
	while (!dead_loop(philo))
	{
		// pthread_mutex_lock(philo->dead_lock);
		// if (*philo->is_dead == 1)
		// {
		// 	pthread_mutex_unlock(philo->dead_lock);
		// 	return (NULL);
		// }
		// pthread_mutex_unlock(philo->dead_lock);
		eating(philo);
		sleeping(philo);
		thinking(philo);
	}
	return (pointer);
}

/*
***	Create and join threads.
	This function creates and joins the threads.
	Initialized the observer thread and the philosopher threads.
	If an error occurs, the function destroys all the resources.
***	@param philo -> Pointer to the philosopher structure.
***	@param program -> Pointer to the program structure.
*/
int	create_threads(t_philo *philo, t_program *program, \
	pthread_mutex_t *forks)
{
	pthread_t	observer;
	int			i;

	i = 0;
	printf(BLUE"entering create_threads\n"RESET);
	if (pthread_create(&observer, NULL, obs_routine, (void *)philo) != 0)
		return (destroy_all(RED"ERROR : Can't create observer thread."RESET, \
			program, forks, philo[0].nb_philo), 1);
	printf(BLUE"create observer done\n"RESET);
	while (i < philo[0].nb_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, ph_routine, \
			(void *)&philo[i]) != 0)
			return (destroy_all(RED"ERROR: Can't create philo thread."RESET, \
				program, forks, philo[0].nb_philo), 1);
		i++;
	}
	printf(BLUE"create philo done\n"RESET);
	i = 0;
	printf(BLUE"joining threads\n"RESET);
	if (pthread_join(observer, NULL) != 0)
		return (destroy_all(RED"ERROR: Can't join observer thread."RESET, \
			program, forks, philo[0].nb_philo), 1);
	printf(BLUE"join observer done\n"RESET);
	while (i < philo[0].nb_philo)
	{
		printf(BLUE"joining philo %d\n"RESET, i + 1);
		if (pthread_join(philo[i].thread, NULL) != 0)
		{
			printf (RED"111111111111111111111111"RESET);
			destroy_all(RED"ERROR: Can't join philo thread."RESET, \
				program, forks, philo[0].nb_philo);
			return (1);
		}
		printf(BLUE"join philo %d done\n"RESET, i + 1);
		i++;
	}
	printf(BLUE"join philo done\n"RESET);
	return (0);
}
