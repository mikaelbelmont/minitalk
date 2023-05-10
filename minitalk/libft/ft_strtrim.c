/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarreto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:11:13 by mbarreto          #+#    #+#             */
/*   Updated: 2021/11/24 19:11:18 by mbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	n;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && ft_strchr(set, s1[i]) != 0)
		i++;
	n = ft_strlen(&s1[i]);
	if (n != 0)
		while (s1[i + n - 1] && ft_strchr(set, s1[i + n - 1]) != 0)
			n--;
	return (ft_substr(s1, i, n));
}
