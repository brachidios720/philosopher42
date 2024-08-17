/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelcarbonnel <raphaelcarbonnel@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:46:28 by rcarbonn          #+#    #+#             */
/*   Updated: 2024/08/16 23:11:46 by raphaelcarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	ft_print(t_philo *philo, char *s)
{
	t_setting	*set;

	set = philo->set;
	pthread_mutex_lock(&philo->set->print);
	pthread_mutex_lock(&set->die_mutex);
	if (set->die != 1 && set->all_hate < set->num_philo)
	{
		printf("\033[38;5;214m%lld\033[0m %d %s", (find_ms()
				- philo->start_philo), philo->id + 1, s);
	}
	pthread_mutex_unlock(&set->die_mutex);
	pthread_mutex_unlock(&philo->set->print);
}

// void	*ft_check_die(void *p)
// {
// 	t_setting	*set;
// 	int			i;

// 	set = (t_setting *)p;
// 	if(set->die != 2)
// 	{
// 		while (set->die != 1)
// 		{
// 			i = 0;
// 			while (i < set->num_philo)
// 			{
// 				pthread_mutex_lock(&set->check);
// 				if ((find_ms() - set->philo[i].last_meal) >= set->t_die)
// 				{
// 					pthread_mutex_unlock(&set->check);
// 					ft_print(&set->philo[i], "\033[0;31mis dead\033[0m\n");
// 					set->die = 1;
// 					return (0);
// 				}
// 				pthread_mutex_unlock(&set->check);
// 				i++;
// 			}
// 			if (set->how_much != -1 && set->all_hate >= set->num_philo)
// 				return (0);
// 		}
// 	}
// 	return (0);
// }

void	*ft_check_die(void *p)
{
    t_setting	*set;
    int			i;
    set = (t_setting *)p;
    while (1)
    {
        i = 0;
        while (i < set->num_philo)
        {
            pthread_mutex_lock(&set->check);
            if ((find_ms() - set->philo[i].last_meal) >= set->t_die)
            {
                ft_print(&set->philo[i], "\033[0;31mis dead\033[0m\n");
                pthread_mutex_lock(&set->die_mutex);
                set->die = 1;
                pthread_mutex_unlock(&set->die_mutex);
                pthread_mutex_unlock(&set->check);
               	return (0);
            }
            pthread_mutex_unlock(&set->check);
            i++;
        }
        pthread_mutex_lock(&set->die_mutex);
        if (set->die == 1)
        {
            pthread_mutex_unlock(&set->die_mutex);
            return (0);
        }
        pthread_mutex_unlock(&set->die_mutex);
		pthread_mutex_lock(&set->check);
        if (set->how_much != -1 && set->all_hate >= set->num_philo)
		{
            return (0);
		}
		pthread_mutex_unlock(&set->check);
    }
    return (0);
}


int	ft_check_time(t_setting *set)
{
	int d;
	int e;
	int s;
	
	d = set->t_die;
	e = set->t_eat;
	s = set->t_sleep;

	if (e > (2147483647 / 4))
		return(0);
	if (e > (2147483647 - s))
		return(0);
	if(set->num_philo % 2 == 1)
	{
		if(d >= (e * 4) && d > (e + s))
			return(2);
	}
	if(set->num_philo % 2 == 0)
	{
		if(d >= (e * 2) && d > (e + s))
			return(2);
	}
	return(0);
}

int	ft_for_one(t_philo *philo)
{	
	philo->start_philo = find_ms();
	ft_print(philo, "is thinking\n");
	ft_print(philo, "has taken a forks\n");
	ft_usleep(philo->set, philo->set->t_die);
	ft_print(philo, "\033[0;31mis dead\033[0m\n"); 
	return(0);
}