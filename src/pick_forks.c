/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelcarbonnel <raphaelcarbonnel@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:48:05 by raphaelcarb       #+#    #+#             */
/*   Updated: 2024/08/16 16:32:16 by raphaelcarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_pick_forks(t_philo *philo)
{
	t_setting	*set;
	int is_dead;

	is_dead = 0; 
	set = philo->set;
	if (!is_dead)
	{
		if (!pthread_mutex_lock(&philo->set->forks[philo->left]))
		{
			philo->left_hand = 1;
			ft_print(philo, "has taken a fork\n");
		}
		if (!pthread_mutex_lock(&philo->set->forks[philo->right])
			&& philo->left_hand)
		{
			philo->right_hand = 1;
			ft_print(philo, "has taken a fork\n");
		}
		pthread_mutex_lock(&set->check);
		if(set->die == 1)
			is_dead = 1;
		pthread_mutex_unlock(&set->check);
	}
}

void	ft_pick_fork(t_philo *philo)
{
	t_setting	*set;

	int is_dead;
	is_dead = 0;
	set = philo->set;
	if (!is_dead)
	{
		if (!pthread_mutex_lock(&philo->set->forks[philo->right]))
		{
			philo->right_hand = 1;
			ft_print(philo, "has taken a fork\n");
		}
		if (!pthread_mutex_lock(&philo->set->forks[philo->left])
			&& philo->right_hand)
		{
			philo->left_hand = 1;
			ft_print(philo, "has taken a fork\n");
		}
		pthread_mutex_lock(&set->check);
		if(set->die == 1)
			is_dead = 1;
		pthread_mutex_unlock(&set->check);
	}
}

void	pick_forks(t_philo *philo)
{
	if (philo->id % 2 != 0)
		ft_pick_forks(philo);
	else
		ft_pick_fork(philo);
}
