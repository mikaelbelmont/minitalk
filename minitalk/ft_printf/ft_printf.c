/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarreto <mbarreto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:52:39 by mbarreto          #+#    #+#             */
/*   Updated: 2022/05/06 14:19:38 by mbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_found_format(const char *format, int i, va_list *args)
{
	if (format[i] == 'c')
		return (ft_putchar(va_arg(*args, int)));
	else if (format[i] == 's')
		return (ft_putstr(va_arg(*args, char *)));
	else if (format[i] == 'p')
		return (write(1, "0x", 2) + ft_putul(va_arg(*args, unsigned long int)));
	else if (format[i] == 'd')
		return (ft_putnumber(va_arg(*args, int)));
	else if (format[i] == 'i')
		return (ft_putnumber(va_arg(*args, int)));
	else if (format[i] == 'u')
		return (ft_putui(va_arg(*args, unsigned int), "0123456789", 10));
	else if (format[i] == 'x')
		return (ft_putui(va_arg(*args, unsigned int),
				"0123456789abcdef", 16));
	else if (format[i] == 'X')
		return (ft_putui(va_arg(*args, unsigned int),
				"0123456789ABCDEF", 16));
	else if (format[i] == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			ret += ft_found_format(format, ++i, &args);
		else
			ret += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (ret);
}
