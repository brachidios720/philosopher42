/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:32:59 by rcarbonn          #+#    #+#             */
/*   Updated: 2023/11/10 22:54:47 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	result;
	char	*ret;

	result = count * size;
	ret = malloc(result);
	if (!ret)
		return (NULL);
	ft_bzero(ret, result);
	return (ret);
}
