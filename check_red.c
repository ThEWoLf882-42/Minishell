/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_red.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:48:10 by agimi             #+#    #+#             */
/*   Updated: 2023/06/09 15:17:03 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	red_condition(t_line *lm, int *i, int *r)
{
	if (lm->nxt)
	{
		if (ft_isred(lm->shx[*i]) && ft_isred(lm->nxt->shx[*i]))
			return (1);
	}
	else if (ft_isred(lm->shx[*i]) && !lm->nxt)
		return (1);
	if (ft_isred(lm->shx[0]))
	{
		while (lm->shx[++(*i)] && lm->shx[*i] == lm->shx[*i - 1])
			(*r)++;
		if (ft_isred(lm->shx[*i]) || *r > 2)
			return (1);
	}
	return (0);
}

int	check_red(void)
{
	t_pipe	*sm;
	t_line	*lm;
	int		i;
	int		r;

	sm = g_va.sp;
	while (sm)
	{
		lm = sm->lin;
		while (lm)
		{
			r = 1;
			i = 0;
			if (red_condition(lm, &i, &r))
			{
				g_va.exit_s = 2;
				ft_putstr_fd("minishell-69: syntax error\n", 2);
				return (1);
			}
			lm = lm->nxt;
		}
		sm = sm->nxt;
	}
	return (0);
}
