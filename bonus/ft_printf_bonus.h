/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpetit <gpetit@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 10:53:51 by gpetit            #+#    #+#             */
/*   Updated: 2020/12/07 10:53:53 by gpetit           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_flags
{
	char		operator;
	int			tabulator;
	int			zero;
	int			taillemin;
	int			taillemax;
}				t_flags;

int				ft_printf(const char *s, ...);
int				ft_atoi(const char *str);
char			*ft_itoa(long n);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_strchrmodif(const char *s, int c);
void			ft_putchar(char c);
int				ft_putstr(char *s);
unsigned long	ft_strlen(char *s);
void			ft_hexaconvertor(char *stock, unsigned long nb, \
unsigned long i);
void			ft_hexamajconvertor(char *stock, unsigned long nb, \
unsigned long i);
char			*ft_print_memory(void *ptr);
char			*ft_print_hexa(unsigned long nb, char c);
int				ft_strcheckdouble(const char *s, int c);
int				ft_parse(char *stock, t_flags *flags, va_list args);
void			ft_initstruct(t_flags *flags);
int				ft_charoutput(char c, t_flags *flags);
int				ft_percentoutput(char c, t_flags *flags);
int				ft_stroutput(char *str, t_flags *flags);
int				ft_memoutput(void *ptr, t_flags *flags);
int				ft_numoutput(long nb, t_flags *flags);
char			*ft_strdup(char *s1);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_nullstring(t_flags *flags);

#endif
