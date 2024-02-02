/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhennequ <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 23:48:03 by bhennequ          #+#    #+#             */
/*   Updated: 2023/02/16 15:56:21 by bhennequ         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <stddef.h>

int	ft_putnbr_printf(int n, int fd, int len);
int	ft_putnbr_hexal(long long unsigned n, int fd, int len);
int	ft_unsigned_putnbr(unsigned int n, int fd, int len);
int	ft_putnbr_hexa(unsigned int n, int fd, char cap, int len);
int	test_arg(char *str, va_list arg);
int	arg_test(char *str, va_list arg);
int	test_arg_test(char *str, va_list arg);
int	read_str(char *str, va_list arg);
int	ft_printf(const char *format, ...);

#endif
