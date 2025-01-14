/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:18:11 by mescoda           #+#    #+#             */
/*   Updated: 2025/01/11 11:26:39 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>

//           ## DEFINES ##
# define PHILO_MAX	200
# define BLUE "\033[1;34m"
# define RED "\033[1;31m"
# define RESET "\033[0m"

//           ## STRUCTURES ##
typedef struct s_philo
{
	int				id;
	int				is_eating;
	int				nb_meals;
	int				nb_philo;
	int				max_meals;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_t		thread;
	int				*is_dead;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*eat_lock;
	pthread_mutex_t	*write_lock;
}				t_philo;

typedef struct s_program
{
	int				is_dead;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	eat_lock;
	pthread_mutex_t	write_lock;
	t_philo			*philo;
}				t_program;

//           ## MAIN.C ##
int		main(int ac, char **av);

//           ## INIT.C ##
void	init_prog(t_program *program);
void	init_forks(pthread_mutex_t *forks, int nb_philo);
void	init_philo(t_philo *philo, t_program *program, \
			pthread_mutex_t *forks, char **av);

//           ## THREADS.C ##
int		dead_loop(t_philo *philo);
void	*ph_routine(void *pointer);
int		create_threads(t_philo *philo, t_program *program, \
	pthread_mutex_t *forks);

//           ## ROUTINE.C ##
void	thinking(t_philo *philo);
void	sleeping(t_philo *philo);
void	one_philo(t_philo *philo);
void	eating(t_philo *philo);

//           ## OBSERVER.C ##
void	*obs_routine(void *pointer);
int		check_dead(t_philo *philo);
int		all_ate(t_philo *philo);

//           ## UTILS.C ##
int		ft_usleep(size_t temp);
void	destroy_all(char *str, t_program *program, \
	pthread_mutex_t *forks, int philo_nb);
void	print_msg(char *str, t_philo *philo, int id);
size_t	curr_time(void);
int		ft_atoi(const char *str);

#endif