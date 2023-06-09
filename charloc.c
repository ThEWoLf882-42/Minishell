/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:30:16 by agimi             #+#    #+#             */
/*   Updated: 2023/06/09 15:15:45 by agimi            ###   ########.fr       */
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
