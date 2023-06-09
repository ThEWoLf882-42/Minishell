/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiguis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 15:43:36 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/06/09 15:15:23 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ambiguis(char *found)
{
	int	i;
	int	count;
	int	space;

	i = 0;
	count = 0;
	space = 0;
	if (!found)
		return (0);
	while (found[i])
	{
		if (found[i] == ' ' || found[i] == '\t')
				space++;
		else if (found[i])
			count++;
		i++;
	}
	if (count > 1 && space)
		return (1);
	return (0);
}
