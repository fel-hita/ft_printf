# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/15 17:36:55 by ebatchas          #+#    #+#              #
#    Updated: 2019/03/14 11:28:44 by ebatchas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc

SRCDIR=srcs
HEADDIR=includes
LIBDIR=libs
BINDIR=.

CFLAGS=-Wall -Wextra -Werror

NAME = libftprintf.a

SRC=$(SRCDIR)/ft_printf.c\
	$(SRCDIR)/conversion.c\
	$(SRCDIR)/newconversion.c\
	$(SRCDIR)/parseconversion.c\
	$(SRCDIR)/printconversion.c\
	$(SRCDIR)/float_conversion.c\
	$(SRCDIR)/print_spacing.c\
	$(SRCDIR)/print_numbers.c\
	$(SRCDIR)/print_strings.c\
	$(SRCDIR)/print_float.c\
	$(SRCDIR)/print_wint.c\
	$(SRCDIR)/print_wstr.c\
	$(SRCDIR)/print_error.c\
	$(SRCDIR)/precision.c\
	$(SRCDIR)/width.c\
	$(SRCDIR)/tally_print.c\
	$(SRCDIR)/double_tools.c\
	$(SRCDIR)/double_calc1.c\
	$(SRCDIR)/double_calc2.c\
	$(SRCDIR)/double_utils.c\
	$(SRCDIR)/double_ops.c\
	$(SRCDIR)/color.c


OBJ=$(LIBDIR)/ft_printf.o\
	$(LIBDIR)/conversion.o\
	$(LIBDIR)/newconversion.o\
	$(LIBDIR)/parseconversion.o\
	$(LIBDIR)/printconversion.o\
	$(LIBDIR)/float_conversion.o\
	$(LIBDIR)/print_spacing.o\
	$(LIBDIR)/print_numbers.o\
	$(LIBDIR)/print_float.o\
	$(LIBDIR)/print_strings.o\
	$(LIBDIR)/print_wint.o\
	$(LIBDIR)/print_wstr.o\
	$(LIBDIR)/print_error.o\
	$(LIBDIR)/precision.o\
	$(LIBDIR)/width.o\
	$(LIBDIR)/tally_print.o\
	$(LIBDIR)/double_tools.o\
	$(LIBDIR)/double_calc1.o\
	$(LIBDIR)/double_calc2.o\
	$(LIBDIR)/double_utils.o\
	$(LIBDIR)/double_ops.o\
	$(LIBDIR)/color.o\
	$(LIBDIR)/libft/*.o

$(LIBDIR)/%.o:$(HEADDIR)/%.h
$(LIBDIR)/%.o:$(SRCDIR)/%.c

all : $(NAME)
$(NAME) :
	make re -C $(LIBDIR)/libft
	$(CC) $(CFLAGS) $(SRC) -c
	mv *.o $(LIBDIR)/
	ar rc $@ $(OBJ)
	ranlib $@


.PHONY: clean fclean

clean:
	make clean -C $(LIBDIR)/libft
	rm -rf $(LIBDIR)/*.o
	rm -rf *.o

fclean: clean
	make fclean -C $(LIBDIR)/libft
	rm -rf $(LIBDIR)/libft.a
	rm -rf $(BINDIR)/$(NAME)

re: fclean all
