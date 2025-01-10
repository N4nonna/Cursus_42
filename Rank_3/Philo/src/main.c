/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:17:32 by mescoda           #+#    #+#             */
/*   Updated: 2025/01/10 11:51:37 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
***	Checks if the input is a number.
	This function checks if the input is a number.
***	@param av -> The input string to be checked.
***	@return -> 0 if the input is a number, 1 otherwise.
*/
static int	is_num(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!(av[i] >= '0' && av[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

/*
***	Checks the input arguments.
	This function checks the input arguments.
	checks if the number of philosophers is between 2 and 200.
	checks if input are numbers and if they are greater than 0.
***	@param ac -> The number of arguments.
***	@param av -> The array of strings containing the arguments.
***	@return -> 0 if the arguments are correct, 1 otherwise.
*/
static int	check_args(int ac, char **av)
{
	int	i;

	i = 0;
	while (i < ac - 1)
	{
		if (ft_atoi(av[1]) > PHILO_MAX || is_num(av[1]) == 1)
			return (printf(RED"ERROR: Wrong number of philosopher !"RESET), 1);
		if (ft_atoi(av[2]) <= 0 && is_num(av[2]) == 1)
			return (printf(RED"ERROR: Wrong time to die !"RESET), 1);
		if (ft_atoi(av[3]) <= 0 && is_num(av[3]) == 1)
			return (printf(RED"ERROR: Wrong time to sleep !"RESET), 1);
		if (ft_atoi(av[4]) <= 0 && is_num(av[4]) == 1)
			return (printf(RED"ERROR: Wrong time to eat !"RESET), 1);
		if (av[5])
		{
			if (ft_atoi(av[5]) <= 0 && is_num(av[5]) == 1)
				return (printf(RED"ERROR: Wrong max number of meal !"RESET), 1);
		}
		i++;
	}
	return (0);
}

/*
***	Main function.
	This function is the main function of the program.
	It initializes the program structure, the forks and the philosophers.
	It then creates the threads and waits for them to finish.
	Then destoying them.
***	@param ac -> The number of arguments.
***	@param av -> The array of strings containing the arguments.
***	@return -> 0 if the program runs correctly, 1 otherwise.
*/
int	main(int ac, char **av)
{
	t_program		program;
	t_philo			philo[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];

	if (ac < 5 || ac > 6)
		return (printf(RED"ERROR: Wrong number of arguments\n"RESET), 1);
	if (check_args(ac, av) == 1)
		return (1);
	init_prog(&program);
	init_forks(forks, ft_atoi(av[1]));
	init_philo(philo, &program, forks, av);
	create_threads(philo, &program, forks);
	printf(BLUE"DESTROY ?\n"RESET);
	destroy_all(BLUE"END OF PROGRAM"RESET, &program, forks, ft_atoi(av[1]));
	return (0);
}

/*
	TODO: 
		- check why sometimes the program wont end when a philosopher is dead
			(time to destroy all forks ??)
		- check at what range it's ok if a philo die (in ms) 
			and/or if it's due to my computer
*/