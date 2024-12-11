/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:18:35 by mescoda           #+#    #+#             */
/*   Updated: 2024/12/10 13:57:54 by mescoda          ###   ########.fr       */
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
static int	philo_dead(t_philo philo)
{
	pthread_mutex_lock(philo.eat_lock);
	if ((curr_time() - philo.last_meal >= philo.time_to_die) \
		&& philo.is_eating == 0)
		return (pthread_mutex_unlock(philo.eat_lock), 1);
	pthread_mutex_unlock(philo.eat_lock);
	return (0);
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
	if (philo->max_meals == -1)
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
		print_msg(BLUE"All philosophers ate to much. Burp !"RESET, philo, 0);
		pthread_mutex_lock(philo->dead_lock);
		*philo->is_dead = 1;
		pthread_mutex_unlock(philo->dead_lock);
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
		if (philo_dead(philo[i]) == 1)
		{
			print_msg(RED"has died. RIP."RESET, philo, philo[i].id);
			pthread_mutex_lock(philo->dead_lock);
			*philo->is_dead = 1;
			pthread_mutex_unlock(philo->dead_lock);
			return (1);
		}
		else if (*philo->is_dead == 1)
		{
			print_msg(RED"has died. RIP."RESET, philo, philo[i].id);
			pthread_mutex_lock(philo->dead_lock);
			pthread_mutex_unlock(philo->dead_lock);
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
	}
	return (pointer);
}
