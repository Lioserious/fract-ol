/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lihrig <lihrig@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:15:45 by lihrig            #+#    #+#             */
/*   Updated: 2025/03/14 15:40:39 by lihrig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double ft_atof(const char *str)
{
	double result;
	double factor;
	int vrz;
	size_t i;
	
	i = 0;
	vrz = 1;
	
	if(str[i] == '-')
	{
		vrz = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while(str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10.0 + (str[i] - '0');
		i++;
	}
	if(str[i] == '.')
	{
		i++;
		factor = 0.1;
		
		while (str[i] >= 0 && str[i] <= 9)
		{
			result += (str[i] - '0') * factor;
			factor *= 0.1;
			i++;
		}
	}
	return (result * vrz);	
}
