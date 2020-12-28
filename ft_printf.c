/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <gpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 14:58:06 by gpetit            #+#    #+#             */
/*   Updated: 2020/12/24 13:20:20 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_isolator(const char *ptr)
{
	char	*str;
	int		i;

	i = 1;
	while (ptr[i] && !ft_strchrmodif("cspdiuxX%", ptr[i]))
		i++;
	str = ft_substr(ptr, 0, i + 1);
	return (str);
}

int	ft_check_conformity(char *str)
{
	int			i;
	static char	conform[] = "%-.*cspdiuxX0123456789";

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (!(ft_strchrmodif(conform, str[i])))
			return (-1);
		i++;
	}
	return (0);
}

int	ft_convert(char *stock, va_list args)
{
	int		count;
	t_flags	flags;

	count = ft_parse(stock, &flags, args);
	if (flags.operator == 'c')
		count = ft_charoutput((va_arg(args, int)), &flags);
	else if (flags.operator == '%')
		count = ft_percentoutput('%', &flags);
	else if (flags.operator == 's')
		count = ft_stroutput(va_arg(args, char*), &flags);
	else if (flags.operator == 'p')
		count = ft_memoutput(va_arg(args, void*), &flags);
	else if (flags.operator == 'd' || flags.operator == 'i')
		count = ft_numoutput((long)va_arg(args, int), &flags);
	else if (flags.operator == 'u' || flags.operator == 'x'
		|| flags.operator == 'X')
		count = ft_numoutput((long)va_arg(args, unsigned int), &flags);
	free(stock);
	return (count);
}

int	ft_printer(char c, int count)
{
	ft_putchar(c);
	count++;
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;
	char	*stock;

	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			stock = ft_isolator(&(str[i++]));
			count = ft_convert(stock, args) + count;
			while (str[i] && !ft_strchrmodif("cspdiuxX%", str[i]))
				i++;
			if (!str[i++])
				break ;
		}
		else
			count = ft_printer(str[i++], count);
	}
	va_end(args);
	return (count);
}
