/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_race.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelcarbonnel <raphaelcarbonnel@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:34:41 by raphaelcarb       #+#    #+#             */
/*   Updated: 2024/08/13 17:01:33 by raphaelcarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_start(t_setting *set)
{
	int	i;

	i = 0;

	if(set->num_philo == 1)
		ft_for_one(set->philo);
	else
	{
		set->start_time = find_ms();
		while (i < set->num_philo)
		{
			set->philo[i].start_philo = find_ms();
			pthread_create(&set->p[i], NULL, ft_routine, &set->philo[i]);
			i++;
		}
		ft_check_die(set);
		i = 0;
		while (i < set->num_philo)
		{
			pthread_join(set->p[i], NULL);
			i++;
		}
	}
}
