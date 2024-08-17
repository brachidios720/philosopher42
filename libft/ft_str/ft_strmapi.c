/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarbonn <rcarbonn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 19:34:38 by rcarbonn          #+#    #+#             */
/*   Updated: 2023/11/09 19:36:39 by rcarbonn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	strlen;
	unsigned int	i;
	char			*result;
	const char		*str;

	str = s;
	strlen = 0;
	while (str[strlen])
		strlen++;
	result = malloc(strlen + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (*str)
	{
		result[i] = f(i, *str);
		i++;
		str++;
	}
	result[strlen] = '\0';
	return (result);
}
