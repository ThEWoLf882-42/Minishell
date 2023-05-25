/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:30:16 by agimi             #+#    #+#             */
/*   Updated: 2023/05/25 16:36:33 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	charloc(char *str, int n)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == n)
			return (i);
		i++;
	}
	return (ft_strlen(str));
}
