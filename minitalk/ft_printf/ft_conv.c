/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarreto <mbarreto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:52:46 by mbarreto          #+#    #+#             */
/*   Updated: 2022/05/05 19:46:59 by mbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv_base(unsigned long long n, char *base, unsigned long long base_size)
{
	int	count;

	count = 0;
	if (n >= base_size)
		count = ft_conv_base(n / base_size, base, base_size);
	count += ft_putchar(base[n % base_size]);
	return (count);
}
