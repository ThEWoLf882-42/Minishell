/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:31:31 by agimi             #+#    #+#             */
/*   Updated: 2023/05/23 15:42:00 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	copy_bef(char *new, int start, char *lin)
{
	int	i;

	i = -1;
	while (++i != start)
		new[i] = lin[i];
}

void	copy_mid(char *new, int start, char *found)
{
	int	i;
	int	j;

	j = 0;
	i = start;
	if (!found)
		return ;
	while (found[j])
		new[i++] = found[j++];
}

void	copy_af(char *new, int start, int nst, char *lin)
{
	int	i;
	int	j;

	j = nst;
	i = start;
	while (lin[j])
		new[i++] = lin[j++];
	new[i] = '\0';
}
