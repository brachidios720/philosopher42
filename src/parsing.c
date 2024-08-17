/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelcarbonnel <raphaelcarbonnel@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:05:57 by rcarbonn          #+#    #+#             */
/*   Updated: 2024/08/12 19:13:10 by raphaelcarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_isdigit_dif(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}

void	ft_pars_args(int ac, char **av, t_setting *set)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_isdigit_dif(av[i]) == 1)
			ft_exit(1);
		i++;
	}
	set->num_philo = ft_atoi_dif(av[1]);
	if (set->num_philo > 200)
		ft_exit(2);
	set->t_die = ft_atoi_dif(av[2]);
	set->t_eat = ft_atoi_dif(av[3]);
	set->t_sleep = ft_atoi_dif(av[4]);
	if (ac == 6)
		set->how_much = ft_atoi_dif(av[5]);
	else
		set->how_much = -1;
	if ((set->t_die < 60) || (set->t_eat < 60) || (set->t_sleep < 60))
		ft_exit(3);
	if ((set->t_die <= 0) || (set->t_eat <= 0) || (set->t_sleep <= 0)
		|| (set->num_philo <= 0) || (set->how_much == 0 || set->how_much < -1))
		ft_exit(3);
}
