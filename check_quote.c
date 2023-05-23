/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:49:08 by agimi             #+#    #+#             */
/*   Updated: 2023/05/23 15:49:54 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	qu_au(char c, int *sq, int *dq)
{
	if (c == '\'')
		(*sq)++;
	else if (c == '"')
		(*dq)++;
}

int	check_quote(void)
{
	t_pipe	*sm;
	t_line	*lm;
	int		dq;
	int		sq;
	int		i;

	sm = g_va.sp;
	while (sm)
	{
		sq = 0;
		dq = 0;
		lm = sm->lin;
		while (lm)
		{
			i = -1;
			while (lm->shx[++i])
				qu_au(lm->shx[i], &sq, &dq);
			lm = lm->nxt;
		}
		if (sq % 2 != 0 || dq % 2 != 0)
			return (write(2, "Syntax Error quote\n", 19), 1);
		sm = sm->nxt;
	}
	return (0);
}
