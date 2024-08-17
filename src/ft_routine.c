/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelcarbonnel <raphaelcarbonnel@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:10:24 by raphaelcarb       #+#    #+#             */
/*   Updated: 2024/08/16 21:54:30 by raphaelcarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_finish_eating(t_philo *philo)
{
	t_setting	*set;

	set = philo->set;
	ft_usleep(set, set->t_eat);
	pthread_mutex_unlock(&set->forks[philo->left]);
	pthread_mutex_unlock(&set->forks[philo->right]);
	philo->left_hand = 0;
	philo->right_hand = 0;
}

void	ft_eat(t_philo *philo)
{
	t_setting	*set;
	
	int is_dead = 0;
	set = philo->set;
	pick_forks(philo);
	pthread_mutex_lock(&set->check);
	philo->last_meal = find_ms();
	pthread_mutex_unlock(&set->check);
	if (!is_dead)
	{
		ft_print(philo, "\033[0;32mis eating\033[0m\n");
		pthread_mutex_lock(&set->check);
		if (set->how_much > 0)
		{
			philo->hate++;
			if (philo->hate == set->how_much)
				set->all_hate++;
		}
		pthread_mutex_unlock(&set->check);
		pthread_mutex_lock(&set->check);
		if(set->die == 1)
			is_dead = 1;
		pthread_mutex_unlock(&set->check);
	}
	ft_finish_eating(philo);
}

void	*ft_routine(void *p)
{
	t_philo	*philo;

	int is_dead =0;
	philo = (t_philo *)p;
	ft_print(philo, "is thinking\n");
	if (philo->id % 2 == 1)
		ft_usleep(philo->set, 60);
	while ((!is_dead))
	{
		ft_eat(philo);
		if (philo->hate == philo->set->how_much)
		{
			printf("ddd\n");
			return (0);
		}
		ft_print(philo, "is sleeping\n");
		ft_usleep(philo->set, philo->set->t_sleep);
		ft_print(philo, "is thinking\n");
		ft_usleep(philo->set, 5);
		pthread_mutex_lock(&philo->set->check);
		if(philo->set->die == 1)
		{
			is_dead = 1;
		}
		pthread_mutex_unlock(&philo->set->check);
	}
	return (0);
}

