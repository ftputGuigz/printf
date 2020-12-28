/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <gpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 14:56:46 by gpetit            #+#    #+#             */
/*   Updated: 2020/12/11 15:52:59 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int i;
	//char tab[] = "This is me";

	i = 0;
	ft_printf("Hello %n Reem !\n", &i);
	printf("I value is : %d\n", i);
	return (0);
}