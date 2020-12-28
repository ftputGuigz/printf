/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <gpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 09:59:33 by gpetit            #+#    #+#             */
/*   Updated: 2020/12/28 11:17:43 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_initstruct(t_flags *flags)
{
	flags->operator = 0;
	flags->tabulator = 0;
	flags->zero = 0;
	flags->taillemin = 0;
	flags->taillemax = -1;
}

void	ft_negativewidth(t_flags *flags)
{
	if (flags->taillemin < 0)
	{
		flags->taillemin = -flags->taillemin;
		flags->tabulator = 1;
		flags->zero = 0;
	}
}

void	ft_parse2(char *stock, int i, t_flags *flags, va_list args)
{
	if (stock[i] == '*' && stock[i])
	{
		flags->taillemin = va_arg(args, int);
		i++;
	}
	if (stock[i] == '.' && stock[i])
	{
		i++;
		flags->taillemax = ft_atoi(stock + i);
		while (stock[i] && (stock[i] >= '0' && stock[i] <= '9'))
			i++;
	}
	if (stock[i] == '*' && stock[i])
	{
		flags->taillemax = va_arg(args, int);
		i++;
	}
	if (stock[i] == 'c' || stock[i] == 's' || stock[i] == 'p'
		|| stock[i] == 'd' || stock[i] == 'i' || stock[i] == 'u'
		|| stock[i] == 'x' || stock[i] == 'X' || stock[i] == '%')
		flags->operator = stock[i];
	ft_negativewidth(flags);
}

static void	ft_spaces(char *stock, int *i, int *spaces)
{
	while (stock[*i] == ' ')
	{
		if (!(*spaces))
		{
			ft_putchar(' ');
			(*spaces)++;
		}
		(*i)++;
	}
}

int	ft_parse(char *stock, t_flags *flags, va_list args)
{
	int	i;
	int	spaces;

	i = 1;
	spaces = 0;
	ft_initstruct(flags);
	ft_spaces(stock, &i, &spaces);
	while ((stock[i] == '-' || stock[i] == '0') && stock[i])
	{
		if (stock[i] == '-')
			flags->tabulator = 1;
		if (stock[i] == '0')
			flags->zero = 1;
		i++;
	}
	if (stock[i] >= '1' && stock[i] <= '9' && stock[i])
	{
		flags->taillemin = ft_atoi(stock + i);
		while (stock[i] && (stock[i] >= '0' && stock[i] <= '9'))
			i++;
	}
	ft_parse2(stock, i, flags, args);
	return (spaces);
}
