/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_spacing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 10:01:57 by ebatchas          #+#    #+#             */
/*   Updated: 2019/03/13 18:40:59 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_print_left(t_conv *conv, char *str)
{
	ft_tally_str(str);
	ft_print_spacing(ft_strlen(str), conv->min_width, ' ');
}

void			ft_print_num_spaced(t_conv *conv, char *str)
{
	if (conv->flag->minus)
		return (ft_print_left(conv, str));
	if (conv->flag->zero)
		ft_print_spacing(ft_strlen(str), conv->min_width, '0');
	else
		ft_print_spacing(ft_strlen(str), conv->min_width, ' ');
	ft_tally_str(str);
}

void			ft_print_spacing(int len, int min, char c)
{
	while (min-- > len)
		ft_tally_print(&c, 1);
}
