/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhennequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:48:52 by bhennequ          #+#    #+#             */
/*   Updated: 2023/02/16 16:04:15 by bhennequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	test_arg(char *str, va_list arg)
{
	int					j;
	long long unsigned	k;

	j = 0;
	if (*str == 'd' || *str == 'i')
		j = ft_putnbr_printf(va_arg(arg, int), 1, 0);
	else if (*str == 'p')
	{
		k = va_arg(arg, long long unsigned);
		if (k == 0)
		{	
			ft_putstr_fd("(nil)", 1);
			return (5);
		}
		else
		{
			ft_putstr_fd("0x", 1);
			j = ft_putnbr_hexal(k, 1, 0) + 2;
		}
	}
	else
		j = arg_test(str, arg);
	return (j);
}

int	arg_test(char *str, va_list arg)
{
	int	j;

	j = 0;
	if (*str == 'u')
		j = ft_unsigned_putnbr(va_arg(arg, int), 1, 0);
	else if (*str == 'x')
		j = ft_putnbr_hexa(va_arg(arg, unsigned int), 1, 'x', 0);
	else if (*str == 'X')
		j = ft_putnbr_hexa(va_arg(arg, unsigned int), 1, 'X', 0);
	else if (*str == '%')
	{	
		ft_putchar_fd('%', 1);
		j = 1;
	}
	else if (*str == 'c')
	{
		ft_putchar_fd(va_arg(arg, int), 1);
		j = 1;
	}
	else
		j = test_arg_test(str, arg);
	return (j);
}

int	test_arg_test(char *str, va_list arg)
{
	int		j;
	char	*k;

	j = 0;
	if (*str == 's')
	{
		k = va_arg(arg, char *);
		if (!k)
		{
			ft_putstr_fd("(null)", 1);
			return (6);
		}
		else
			j = ft_strlen(k);
		ft_putstr_fd(k, 1);
	}
	return (j);
}

int	read_str(char *str, va_list arg)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{	
			j = j + test_arg(&str[++i], arg);
		}
		else
		{	
			ft_putchar_fd(str[i], 1);
			j++;
		}
		i++;
	}
	return (j);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		j;

	if (!format || *format == '\0')
		return (0);
	va_start(arg, format);
	j = read_str((char *)format, arg);
	va_end(arg);
	return (j);
}
