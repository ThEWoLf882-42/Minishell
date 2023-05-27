/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:31:31 by agimi             #+#    #+#             */
/*   Updated: 2023/05/27 17:11:01 by zouaraqa         ###   ########.fr       */
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

// void	copy(char *new, int start, char *get)
// {
// 	copy_bef(new, start, lm->shx);
// 	copy_mid(new, start, found);
// 	copy_af(new, start + ft_strlen(found), start + ft_strlen(get) + 1, lm->shx);
// }
