/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhennequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:41:24 by bhennequ          #+#    #+#             */
/*   Updated: 2023/02/16 16:08:08 by bhennequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hexal(long long unsigned n, int fd, int len)
{
	char	*base;

	base = "0123456789abcdef";
	if (n <= 15)
	{	
		ft_putchar_fd(base[n], fd);
		len++;
	}
	if (n > 15)
	{
		len += ft_putnbr_hexal(n / 16, fd, 0);
		len += ft_putnbr_hexal(n % 16, fd, 0);
	}
	return (len);
}

int	ft_unsigned_putnbr(unsigned int n, int fd, int len)
{
	if (n <= 9)
	{	
		ft_putchar_fd(n + '0', fd);
		len++;
	}
	if (n > 9)
	{
		len += ft_unsigned_putnbr(n / 10, fd, 0);
		len += ft_unsigned_putnbr(n % 10, fd, 0);
	}
	return (len);
}

int	ft_putnbr_hexa(unsigned int n, int fd, char cap, int len)
{
	char	*base;

	base = "0123456789abcdef";
	if (n > 15)
	{
		len += ft_putnbr_hexa(n / 16, fd, cap, 0);
		len += ft_putnbr_hexa(n % 16, fd, cap, 0);
	}
	if (n <= 15)
	{
		if (n > 9 && cap == 'X')
			ft_putchar_fd(base[n] - 32, fd);
		else
			ft_putchar_fd(base[n], fd);
		len++;
	}
	return (len);
}

int	ft_putnbr_printf(int n, int fd, int len)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
		len++;
	}
	if (n <= 9 && n >= 0)
	{	
		ft_putchar_fd(n + '0', fd);
		len++;
	}
	if (n > 9)
	{
		len += ft_putnbr_printf(n / 10, fd, 0);
		len += ft_putnbr_printf(n % 10, fd, 0);
	}
	return (len);
}
