/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:46:26 by agimi             #+#    #+#             */
/*   Updated: 2023/05/23 18:12:22 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	copy_it(t_line *lm)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (lm->shx[i])
	{
		if (lm->shx[i] == 30)
			i++;
		else
			lm->shx[++j] = lm->shx[i++];
	}
	lm->shx[++j] = '\0';
}

void	clean(void)
{
	t_pipe	*sm;
	t_line	*lm;

	sm = g_va.sp;
	while (sm)
	{
		lm = sm->lin;
		while (lm)
		{
			if (ft_strchr(lm->shx, 30))
				copy_it(lm);
			lm = lm->nxt;
		}
		sm = sm->nxt;
	}
}
