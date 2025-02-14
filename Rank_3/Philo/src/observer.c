/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:18:35 by mescoda           #+#    #+#             */
/*   Updated: 2025/02/14 13:07:33 by mescoda          ###   ########.fr       */
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
static int	philo_dead(t_philo *philo, size_t time)
{
	// pthread_mutex_lock(philo->dead_lock);
	// if (*philo->is_dead == 1)
	// {
	// 	pthread_mutex_unlock(philo->dead_lock);
	// 	return (1);
	// }
	// pthread_mutex_unlock(philo->dead_lock);
	pthread_mutex_lock(philo->eat_lock);
	if ((curr_time() - philo->last_meal >= time) \
		&& philo->is_eating == 0)
	{
		pthread_mutex_unlock(philo->eat_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->eat_lock);
	return (0);
}

static void	print_death(char *str, int id, t_philo *philo)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = curr_time() - philo->start_time;
	printf(RED"%zums Philo %d %s\n"RESET, time, id, str);
	pthread_mutex_unlock(philo->write_lock);
}

/*
***	Checks if all philosophers have eaten.
	This function checks if all philosophers have eaten.
	If all philosophers have eaten, the function prints a message.
	And modify the is_dead variable to 1.
***	@param philo -> Pointer to the philosopher structure.
***	@return -> 1 if all philosophers have eaten, 0 otherwise.
*/
int	all_ate(t_philo *philo)
{
	int	i;
	int	meals;

	i = 0;
	meals = 0;
	if (philo[0].max_meals == -1)
		return (0);
	while (i < philo[0].nb_philo)
	{
		pthread_mutex_lock(philo[i].eat_lock);
		if (philo[i].nb_meals >= philo[i].max_meals)
			meals++;
		pthread_mutex_unlock(philo[i].eat_lock);
		i++;
	}
	if (meals == philo[0].nb_philo)
	{
		pthread_mutex_lock(philo[0].dead_lock);
		*philo->is_dead = 1;
		pthread_mutex_unlock(philo[0].dead_lock);
		print_death(BLUE"All philosophers ate to much. Burp !"RESET, 0, philo);
		return (1);
	}
	return (0);
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
	while (i < philo[0].nb_philo)
	{
		if (philo_dead(&philo[i], philo[i].time_to_die))
		{
			print_death(RED"has died. RIP."RESET, philo[i].id, philo);
			pthread_mutex_lock(philo[0].dead_lock);
			*philo->is_dead = 1;
			pthread_mutex_unlock(philo[0].dead_lock);
			return (1);
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
void	*obs_routine(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	while (1)
	{
		if (check_dead(philo) == 1 || all_ate(philo) == 1)
			break ;
		usleep(1000);
	}
	return (pointer);
}
