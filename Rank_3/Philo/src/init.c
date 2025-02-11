/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:58:14 by mescoda           #+#    #+#             */
/*   Updated: 2025/02/11 11:10:39 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
***	Initializes the input values.
	This function sets up the input values for the philosopher structure.
	It ensures that the philosopher has the correct values for the simulation.
***	@param philo -> Pointer to the philosopher structure to be initialized.
***	@param av -> Array of strings containing the input arguments.
*/
static void	init_input(t_philo *philo, char **av)
{
	philo->nb_philo = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		philo->max_meals = ft_atoi(av[5]);
	else
		philo->max_meals = -1;
}

/*
***	Initializes the philosopher structure.
	This function sets up the philosopher structure by allocating necessary
	resources and initializing its state. It ensures that the philosopher is
	ready to be used in the dining philosophers problem.
***	@param philo -> Pointer to the philosopher structure to be initialized.
***	@param program -> Pointer to the program structure to be initialized.
***	@param forks -> Pointer to the forks structure to be initialized.
***	@param av -> Array of strings containing the input arguments.
*/
void	init_philo(t_philo *philo, t_program *program, \
			pthread_mutex_t *forks, char **av)
{
	int	i;

	i = -1;
	while (++i < ft_atoi(av[1]))
	{
		philo[i].id = i + 1;
		philo[i].is_eating = 0;
		philo[i].nb_meals = 0;
		philo[i].last_meal = curr_time();
		philo[i].start_time = curr_time();
		philo[i].is_dead = &program->is_dead;
		philo[i].dead_lock = &program->dead_lock;
		philo[i].eat_lock = &program->eat_lock;
		philo[i].write_lock = &program->write_lock;
		init_input(&philo[i], av);
		philo[i].r_fork = &forks[i];
		if (i == 0)
			philo[i].l_fork = &forks[philo[i].nb_philo - 1];
		else
			philo[i].l_fork = &forks[i - 1];
	}
}

/*
***	Initializes the fork structure.
	This function sets up the fork structure by allocating necessary resources
	and initializing its state. It ensures that the fork is ready to be used
	by the philosophers in the dining philosophers problem.
***	@param fork -> Pointer to the fork structure to be initialized.
***	@param nb_philo -> Total numbers of forks to initialized.
*/
void	init_forks(pthread_mutex_t *forks, int nb_philo)
{
	int	i;

	i = -1;
	while (++i < nb_philo)
		pthread_mutex_init(&forks[i], NULL);
}

/*
**	Initializes the program structure by creating mutex threads for the locks
**	@param program -> Pointer to the program structure to be initialized.
*/
void	init_prog(t_program *program)
{
	program->is_dead = 0;
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->eat_lock, NULL);
	pthread_mutex_init(&program->write_lock, NULL);
}
