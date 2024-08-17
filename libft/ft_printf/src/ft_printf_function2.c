/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_function2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raphaelcarbonnel <raphaelcarbonnel@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 06:28:33 by mpoussie          #+#    #+#             */
/*   Updated: 2024/06/19 00:36:29 by raphaelcarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_print_hex(unsigned int nbr, const char format)
{
	if (nbr == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(nbr, format);
	return (ft_printf_len(nbr));
}

int	ft_print_unsigned(unsigned int nbr)
{
	int		print_len;
	char	*num;

	print_len = 0;
	if (nbr == 0)
		print_len += write(1, "0", 1);
	else
	{
		num = ft_unsigned_itoa(nbr);
		print_len += ft_print_str(num);
		free(num);
	}
	return (print_len);
}
