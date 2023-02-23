/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghyle <donghyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 13:48:26 by donghyle          #+#    #+#             */
/*   Updated: 2023/01/22 16:41:47 by dahkang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	handle_sign(char **cursor, int *sign)
{
	if (**cursor == '-')
	{
		(*sign) = -1;
		(*cursor)++;
	}
	else if (**cursor == '+')
	{
		(*sign) = 1;
		(*cursor)++;
	}
	else
		(*sign) = 1;
}

static void	handle_digit(char c, double *val, int *incrementer)
{
	(*incrementer)++;
	(*val) = (*val) * 10.0f + (c - '0');
}

static int	handle_number(char *str, int *digits_after_decimal, double *val)
{
	int	decimal_found;
	int	digits_before_decimal;

	digits_before_decimal = 0;
	decimal_found = 0;
	while (*str != '\0')
	{
		if (ft_isdigit(*str))
		{
			if (decimal_found)
				handle_digit(*str, val, digits_after_decimal);
			else
				handle_digit(*str, val, &digits_before_decimal);
		}
		else if (*str == '.')
		{
			if (decimal_found)
				return (-1);
			decimal_found = 1;
		}
		else
			return (-1);
		str++;
	}
	return (0);
}

static void	handle_power(int digits_after_decimal, double *val)
{
	int	power;
	int	i;

	power = 1;
	i = 0;
	while (i < digits_after_decimal)
	{
		power *= 10;
		i++;
	}
	if (power > 1)
		(*val) /= power;
}

int	ft_atof_if_valid(char *str, double *ret)
{
	double	value;
	int		sign;
	int		digits_after_decimal;

	if (!str || ft_strlen(str) == 0)
		return (CODE_ERROR_DATA);
	value = 0.0;
	handle_sign(&str, &sign);
	digits_after_decimal = 0;
	value = 0.0;
	if (handle_number(str, &digits_after_decimal, &value))
		return (CODE_ERROR_DATA);
	handle_power(digits_after_decimal, &value);
	*ret = value * sign;
	return (CODE_OK);
}
