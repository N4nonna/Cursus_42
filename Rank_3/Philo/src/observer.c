/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:18:35 by mescoda           #+#    #+#             */
/*   Updated: 2024/12/03 13:28:19 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
***	Checks if all philosophers have eaten.
	This function checks if all philosophers have eaten or if they take to
	muche time between each meal.
***	@param philo -> Pointer to one philosopher structure. (philo[i])
***	@return -> 1 if all philosophers have eaten or strave, 0 otherwise.
*/
static int	philo_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->eat_lock);
	if (philo->max_meals != -1 && philo->nb_meals >= philo->max_meals)
		return (1);
	if (curr_time() - philo->last_meal > philo->time_to_die)
	{
		if (philo->is_eating == 1)
			return (pthread_mutex_unlock(philo->eat_lock), 1);
	}
	return (pthread_mutex_unlock(philo->eat_lock), 0);
}

/*
***	Checks if all philosophers are alive.
	This function checks if all philosophers are alive.
	If a philosopher is dead, the function prints a message.
	And modify the is_dead variable to 1.
***	@param philo -> Pointer to the philosopher structure.
***	@return -> 1 if a philosopher is dead, 0 otherwise.
*/
int	check_dead(t_philo	*philo)
{
	int	i;

	i = 0;
	while (i < philo->nb_philo)
	{
		if (philo_dead(philo) == 1)
		{
			printf("%ld %d has died.", curr_time() - philo->start_time, philo->id);
			pthread_mutex_lock(philo->dead_lock);
			philo->is_dead = 1;
			return (pthread_mutex_unlock(philo->dead_lock), 1);
		}
		i++;
	}
	return (0);
}

/*
***	Observer routine.
	This function is the routine of the observer.
	Create and initialize the philo variable.
	Check if a philosopher is dead, or if they all ate.
***	@param pointer -> Pointer to the philosopher structure.
***	@return philo -> Pointer to the dead philosopher
*/
void	*observer_routine(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	while (1)
	{
		if (check_dead(philo) == 1)
			break ;
	}
	return (pointer);
}
