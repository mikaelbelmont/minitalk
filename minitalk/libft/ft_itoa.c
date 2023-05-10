/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarreto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:51:27 by mbarreto          #+#    #+#             */
/*   Updated: 2021/11/24 18:51:30 by mbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	numlen(int n)
{
	int	l;

	l = 1;
	while (n > 9)
	{
		n = n / 10;
		l++;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		s;
	int		len;

	s = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = n * -1;
		s = 1;
	}
	len = numlen(n);
	str = (char *)malloc(sizeof(char ) * (len + s + 1));
	if (!str)
		return (NULL);
	str[len + s] = '\0';
	while (len-- > 0)
	{
		str[len + s] = 48 + n % 10;
		n = n / 10;
	}
	if (s == 1)
		str[len + s] = '-';
	return (str);
}
