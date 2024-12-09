/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:37:15 by mescoda           #+#    #+#             */
/*   Updated: 2024/12/09 11:21:22 by mescoda          ###   ########.fr       */
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
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!dead_loop(philo))
	{
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
void	create_threads(t_philo *philo, t_program *program, \
	pthread_mutex_t *forks)
{
	pthread_t	observer;
	int			i;

	i = 0;
	//printf("--------------ENTERING THREADS----------------\n");
	if (pthread_create(&observer, NULL, observer_routine, (void *)philo) != 0)
		destroy_all("pthread_create cannot be done", program, forks, philo[0].nb_philo, 1);
	//printf("Observer created\n");
	while (i < philo[0].nb_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, philo_routine, \
			&philo[i]) != 0)
			return (destroy_all("pthread_create cannot be done", \
				program, forks, philo[0].nb_philo, 1));
		//printf("Philosopher %d created\n", philo[i].id);
		i++;
	}
	//printf("All Philosophers created\n");
	i = 0;
	if (pthread_join(observer, NULL) != 0)
		return (destroy_all("pthread_join cannot be done", program, forks, philo[0].nb_philo, 1));
	//printf("Observer joined\n");
	while (i < philo[0].nb_philo)
	{
		if (pthread_join(philo[i].thread, NULL) != 0)
			return (destroy_all("pthread_join cannot be done", \
				program, forks, philo[0].nb_philo, 1));
		//printf("Philosopher %d joined\n", i + 1);
		i++;
	}
	//printf("All Philosophers joined\n");
}
