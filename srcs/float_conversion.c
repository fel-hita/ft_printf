/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebatchas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 12:05:39 by ebatchas          #+#    #+#             */
/*   Updated: 2019/03/13 21:53:16 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_double(int k, double n)
{
	t_double	d;

	d.d = n > 0.5 ? n + k : n;
	return (ft_pre_cal(&d));
}

static char	*ft_ldouble(int k, long double n)
{
	t_l_double	d;

	d.d = n > 0.5 ? n + k : n;
	return (ft_l_pre_cal(&d));
}

char		*ft_get_float_signed(t_conv *conv, va_list ap)
{
	int		k;

	k = conv->prec_set && !conv->precision;
	if (conv->type == 'f')
	{
		if (conv->modif == LF)
			return (ft_ldouble(k, va_arg(ap, long double)));
		else
			return (ft_double(k, va_arg(ap, double)));
	}
	else
	{
		if (conv->modif == LF)
			return (ft_ldouble(k, va_arg(ap, long double)));
		else
			return (ft_double(k, va_arg(ap, double)));
	}
}
