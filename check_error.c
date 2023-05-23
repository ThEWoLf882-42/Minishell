/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 18:15:28 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/05/23 10:48:22 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_pipe(void)
{
	t_pipe	*mv;

	mv = g_va.sp;
	while (mv)
	{
		if (!mv->lin)
			return (write(2, "Error empty pipe line\n", 22), 1);
		mv = mv->nxt;
	}
	return (0);
}

static	void	qu_au(char c, int *sq, int *dq)
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

static	int	red_condition(t_line *lm, int *i, int *r)
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
				return (write(2, "Error wrong redirections\n", 25), 1);
			lm = lm->nxt;
		}
		sm = sm->nxt;
	}
	return (0);
}

int	check_error(void)
{
	if (check_pipe() || check_quote() || check_red())
		return (1);
	return (0);
}
