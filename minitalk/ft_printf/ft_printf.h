/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarreto <mbarreto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:52:35 by mbarreto          #+#    #+#             */
/*   Updated: 2022/05/05 17:52:56 by mbarreto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef unsigned long long int		t_ulli;
int			ft_printf(const char *type, ...);
int			ft_found_format(const char *format, int i, va_list *args);
int			ft_putchar(char c);
int			ft_putstr(char *str);
int			ft_conv_base(t_ulli n, char *base, t_ulli base_size);
int			ft_putnumber(int n);
int			ft_putui(unsigned int n, char *base, int base_size);
int			ft_putul(unsigned long n);

#endif