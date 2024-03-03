/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftome-ve <ftome-ve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 20:04:58 by ftome-ve          #+#    #+#             */
/*   Updated: 2024/02/29 15:21:55 by ftome-ve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	converse_neg(long n, unsigned int base, char specifier)
{
	int		count;
	long	num;

	count = 0;
	num = n;
	if (num < 0)
	{
		count = count + write (1, "-", 1);
		num = -num;
	}
	count = count + print_digit(num, base, specifier);
	return (count);
}

int	print_str(char *s)
{
	int	count;

	count = 0;
	if (s == NULL)
	{
		print_str("(null)");
		return (6);
	}
	while (*s)
	{
		count = count + write (1, s++, 1);
	}
	return (count);
}

int	print_digit(unsigned long n, unsigned int base, char specifier)
{
	int		count;
	char	*basics;
	char	digit;

	count = 0;
	basics = "0123456789abcdef";
	if (specifier == 'X')
		basics = "0123456789ABCDEF";
	if (n >= base)
		count = count + print_digit(n / base, base, specifier);
	digit = basics[n % base];
	count = count + write (1, &digit, 1);
	return (count);
}

int	print_format(char specifier, va_list ap)
{
	int		count;
	char	charac;

	count = 0;
	if (specifier == 'c')
	{
		charac = (va_arg(ap, int));
		count = count + write (1, &charac, 1);
	}
	else if (specifier == 's' )
		count = count + print_str(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count = count + converse_neg(va_arg(ap, int), 10, specifier);
	else if (specifier == 'x' || specifier == 'X')
		count = count + print_digit(va_arg(ap, unsigned int), 16, specifier);
	else if (specifier == 'u')
		count = count + print_digit(va_arg(ap, unsigned int), 10, specifier);
	else if (specifier == 'p')
	{
		count = count + print_str("0x");
		count = count + print_digit(va_arg(ap, unsigned long), 16, specifier);
	}
	else
		count = count + write (1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			count = count + print_format(*(++format), ap);
		else
			count = count + write (1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}
/*
int	main()
{
	int	count;

	count = ft_printf("Hello %s\n", Fran);
	//ft_printf("hay %d caracteres \n", count);
	//return (0);
}*/