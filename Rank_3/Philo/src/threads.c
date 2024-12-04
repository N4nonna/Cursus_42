/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:37:15 by mescoda           #+#    #+#             */
/*   Updated: 2024/12/03 13:36:29 by mescoda          ###   ########.fr       */
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
void	*philo_routine(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	if (philo->id % 2)
		usleep(1);
	while (dead_loop(philo) != 0)
	{
		thinking(philo);
		eating(philo);
		sleeping(philo);
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
void	create_threads(t_philo *philo, t_program *program)
{
	pthread_t	observer;
	int			i;

	i = 0;
	if (pthread_create(&observer, NULL, observer_routine, (void *)philo) != 0)
		destroy_all(philo, program, &observer);
	while (i < philo->nb_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, philo_routine, \
			(void *)&philo[i]) != 0)
			return (destroy_all(philo, program, &observer));
		i++;
	}
	i = 0;
	if (pthread_join(observer, NULL) != 0)
		return (destroy_all(philo, program, &observer));
	while (i < philo->nb_philo)
	{
		if (pthread_join(philo->thread, NULL) != 0)
			return (destroy_all(philo, program, &observer));
		i++;
	}
}
