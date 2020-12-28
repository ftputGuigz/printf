# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpetit <gpetit@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/04 14:56:56 by gpetit            #+#    #+#              #
#    Updated: 2020/12/28 11:56:53 by gpetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = clang

CFLAGS = -Wall -Werror -Wextra

SRCS = ft_printf.c basics.c basics2.c basics3.c hexaconvertor.c parsor.c charoutput.c stroutput.c memoutput.c numoutput.c

SRCSBONUS = ./bonus/ft_printf_bonus.c ./bonus/basics_bonus.c ./bonus/basics2_bonus.c \
			./bonus/basics3_bonus.c ./bonus/hexaconvertor_bonus.c ./bonus/parsor_bonus.c \
			./bonus/charoutput_bonus.c ./bonus/stroutput_bonus.c ./bonus/memoutput_bonus.c ./bonus/numoutput_bonus.c

OBJS = $(SRCS:.c=.o)

OBJSBONUS = $(SRCSBONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

bonus: $(OBJSBONUS)
	ar rc $(NAME) $(OBJSBONUS)

clean:
	rm -f $(OBJS) $(OBJSBONUS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY : all make re clean fclean bonus
