/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:46:26 by agimi             #+#    #+#             */
/*   Updated: 2023/05/23 17:32:18 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clean(void)
{
	t_pipe	*sm;
	t_line	*lm;
	int		i;
	int		j;

	sm = g_va.sp;
	while (sm)
	{
		lm = sm->lin;
		while (lm)
		{
			if (ft_strchr(lm->shx, '#'))
			{
				i = 0;
				j = -1;
				while (lm->shx[i])
				{
					if (lm->shx[i] == '#')
						i++;
					else
						lm->shx[++j] = lm->shx[i++];
				}
				lm->shx[++j] = '\0';
			}
			lm = lm->nxt;
		}
		sm = sm->nxt;
	}
}
