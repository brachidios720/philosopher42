/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelcarbonnel <raphaelcarbonnel@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:26:06 by rcarbonn          #+#    #+#             */
/*   Updated: 2024/08/16 21:32:33 by raphaelcarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "../libft/libft.h"
# include <pthread.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct setting_s	t_setting;

typedef struct philo_s
{
	t_setting				*set;
	long long last_meal; // dernier repas
	int id;              // id du philo
	int left;            // gauche
	int right;           // droite
	int						left_hand;
	int						right_hand;
	int						hate;
	long long				start_philo;

}							t_philo;

typedef struct setting_s
{
	int num_philo; // nombre de philo
	int t_die;     // temps de mort
	int t_eat;     // temps de repas
	int t_sleep;   // temps de repos
	int how_much;  // combien de repas
	int						all_hate;
	int						die;
	long long start_time;   // lancement du programme
	pthread_mutex_t print;  // pour print
	pthread_mutex_t check;  // acces a la mort
	pthread_t *p;           // les threads
	pthread_mutex_t *forks; // fourchettes
	t_philo *philo;         // acces paramettre des philos
	pthread_mutex_t die_mutex;


}							t_setting;

// parsing
void						ft_pars_args(int ac, char **av, t_setting *set);
int							ft_atoi_dif(char *str);
int							ft_isdigit_dif(char *str);
long						find_ms(void);
int							ft_check_time(t_setting *set);
void 						ft_usleep(t_setting *set, long time_in_ms);

// initialisation

void						init_philo(t_setting *set);
int							init_settings(t_setting *set);
void						init_forks(t_setting *set);

// error

void						ft_exit(int i);
void						ft_clear(t_setting *set);
void						ft_error(int i, t_setting *set);
int							ft_is_dead(t_philo *philo);
void						*ft_check_die(void *p);

// routine

void						ft_eat(t_philo *philo);
void						*ft_routine(void *p);
void						ft_start(t_setting *set);
void						ft_print(t_philo *philo, char *s);
void						ft_finish_eating(t_philo *philo);
void						ft_pick_forks(t_philo *philo);
void						ft_pick_fork(t_philo *philo);
void						pick_forks(t_philo *philo);
int							ft_for_one(t_philo *philo);

#endif