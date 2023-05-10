/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarreto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:10:45 by mbarreto          #+#    #+#             */
/*   Updated: 2021/11/24 19:10:47 by mbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = ft_strlen(str);
	while (i > 0)
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i--;
	}
	if (str[i] == (char)c)
		return ((char *)str + i);
	return (NULL);
}
