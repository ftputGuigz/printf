/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stroutput_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <gpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 17:34:51 by gpetit            #+#    #+#             */
/*   Updated: 2020/12/28 11:18:42 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_nullstring(t_flags *flags)
{
	char	*tmp;

	if (flags->taillemax >= 0 && flags->taillemax < (int)ft_strlen("(null)"))
		tmp = ft_substr("(null)", 0, flags->taillemax);
	else
		tmp = ft_strdup("(null)");
	return (tmp);
}

char	*ft_stroutput2(char *tmp, t_flags *flags)
{
	int		i;
	int		max;
	char	*output;
	char	*spaces;

	i = 0;
	max = flags->taillemin - (int)ft_strlen(tmp);
	spaces = malloc(sizeof(char) * (max + 1));
	if (!spaces)
		return (NULL);
	spaces[max] = '\0';
	while (i < max)
		spaces[i++] = ' ';
	if (flags->tabulator)
		output = ft_strjoin(tmp, spaces);
	else
		output = ft_strjoin(spaces, tmp);
	free(spaces);
	return (output);
}

int	ft_stroutput(char *str, t_flags *flags)
{
	char	*tmp;
	char	*output;
	int		count;

	if (str == NULL)
		tmp = ft_nullstring(flags);
	else
	{
		if (flags->taillemax >= 0 && flags->taillemax < (int)ft_strlen(str))
			tmp = ft_substr(str, 0, flags->taillemax);
		else
			tmp = ft_strdup(str);
	}
	if (flags->taillemin > (int)ft_strlen(tmp))
		output = ft_stroutput2(tmp, flags);
	else
		output = ft_strdup(tmp);
	count = ft_putstr(output);
	free(tmp);
	free(output);
	return (count);
}
