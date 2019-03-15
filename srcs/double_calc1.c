/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublecal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-hita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 17:23:24 by fel-hita          #+#    #+#             */
/*   Updated: 2019/03/13 21:57:29 by ebatchas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*ft_zeros(int len)
{
	char *new;

	new = (char*)malloc(len + 1);
	new = ft_memset(new, '0', len);
	new = ft_strjoin("0.", new);
	return (new);
}

static size_t	ft_is_end(char *str)
{
	while (*str)
	{
		if (*str != '0')
			return (0);
		str++;
	}
	return (1);
}

char			*ft_mvfrc(char *str, int frac_len)
{
	char	*new;
	int		str_len;
	int		i;

	i = -1;
	str_len = ft_strlen(str);
	if (str_len - frac_len == 0)
		new = ft_strjoin("0.", str);
	else if (str_len - frac_len < 0)
	{
		new = ft_strdup(str);
		new = ft_strjoin(ft_zeros(ABS((str_len - frac_len))), new);
	}
	else
	{
		new = ft_strjoin(".", str);
		while (++i < ABS((str_len - frac_len)))
		{
			new[i] = new[i + 1];
			new[i + 1] = '.';
		}
	}
	return (new);
}

char			*ft_rmz(char *str, short flag_frac)
{
	size_t	i;

	i = 0;
	if (flag_frac)
	{
		while (str[i] != '.')
			i++;
	}
	if (ft_is_end(str + i + 1))
	{
		str[i] = 0;
		return (str);
	}
	while (str[i])
	{
		if (ft_is_end(str + i))
			str[i] = 0;
		i++;
	}
	return (str);
}
