/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarreto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:50:14 by mbarreto          #+#    #+#             */
/*   Updated: 2021/11/24 18:50:17 by mbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t c, size_t n)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (void *)malloc(c * n);
	if (ptr == 0)
		return (0);
	while (i < c * n)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}
