/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:15:30 by mescoda           #+#    #+#             */
/*   Updated: 2025/02/14 12:01:11 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
***	Thinking routine
	This function is the thinking routine of the philosopher.
***	@param philo -> Pointer to the philosopher structure.
*/
void	thinking(t_philo *philo)
{
	print_msg("is thinking, hmmmmmmmmmmm...", philo, philo->id);
}

/*
***	Sleeping routine
	This function is the sleeping routine of the philosopher.
***	@param philo -> Pointer to the philosopher structure.
*/
void	sleeping(t_philo *philo)
{
	print_msg("is sleeping, ronpich", philo, philo->id);
	// if (philo->time_to_die <= philo->time_to_sleep)
	// {
	// 	pthread_mutex_lock(philo->dead_lock);
	// 	*philo->is_dead = 1;
	// 	ft_usleep(philo->time_to_sleep);
	// 	pthread_mutex_unlock(philo->dead_lock);
	// }
	// else
	ft_usleep(philo->time_to_sleep);
}

// void	one_philo(t_philo *philo)
// {
// 	pthread_mutex_lock(philo->l_fork);
// 	print_msg("has taken left fork", philo, philo->id);
// 	ft_usleep(philo->time_to_die);
// 	pthread_mutex_unlock(philo->l_fork);
// 	return ;
// }

/*
***	Eating routine
	This function is the eating routine of the philosopher.
	Locks the right and left forks, then makes the philosopher eat.
***	@param philo -> Pointer to the philosopher structure.
*/
void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_msg("has taken left fork", philo, philo->id);
	if (philo->nb_philo == 1)
	{
		ft_usleep(philo->time_to_die);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	pthread_mutex_lock(philo->l_fork);
	print_msg("has taken right fork", philo, philo->id);
	philo->is_eating = 1;
	print_msg("is eating, nom nom nom", philo, philo->id);
	pthread_mutex_lock(philo->eat_lock);
	philo->last_meal = curr_time();
	philo->nb_meals++;
	// if (philo->time_to_die <= philo->time_to_eat)
	// {
	// 	pthread_mutex_lock(philo->dead_lock);
	// 	*philo->is_dead = 1;
	// 	ft_usleep(philo->time_to_eat);
	// 	pthread_mutex_unlock(philo->dead_lock);
	// }
	// else
	pthread_mutex_unlock(philo->eat_lock);
	ft_usleep(philo->time_to_eat);
	philo->is_eating = 0;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}
