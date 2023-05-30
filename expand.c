/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:11:05 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/05/30 18:48:51 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand_that(t_exp_utl *exp, t_line *lm, int start, int end)
{
	char	*lnew;
	size_t	s;

	if (exp->newlm)
		lnew = ft_lastline(exp->newlm)->shx;
	s = ft_strlen(lm->shx) - end;
	if (exp->bf)
	{
		if (char_bf(start))
			ft_backline(&exp->newlm, new_lin(ft_substr(lm->shx, 0, start)));
	}
	else
		join_bf(&exp->newlm, lm->shx, exp->found, start);
	creat_expnod(&exp->newlm, exp->found, exp->bf);
	if (exp->af)
	{
		if (char_af(lm->shx, end))
			ft_backline(&exp->newlm, new_lin(ft_substr(lm->shx, end + 1, s)));
	}
	else
	{
		if (char_af(lm->shx, end))
			lnew = ft_strjoin2fr(lnew, ft_substr(lm->shx, end + 1, s));
	}
}

void	exp_dlr(t_line *lm, int start, int end)
{
	t_exp_utl	exp;
	char		*get;

	exp.newlm = NULL;
	get = ft_substr(lm->shx, start + 1, end - (start + 1));
	exp.found = which_env(get, &exp.bf, &exp.af);
	if (!exp.found && (end - start == (int)ft_strlen(lm->shx)))
	{
		free(lm->shx);
		lm->shx = NULL;
		return ;
	}
	expand_that(&exp, lm, start, end);
	if (lm->nxt)
		ft_lastline(exp.newlm)->nxt = lm->nxt;
	free(lm->shx);
	if (exp.af || exp.bf)
		lm->space = 1;
	if (exp.newlm)
	{
		lm->shx = exp.newlm->shx;
		lm->nxt = exp.newlm->nxt;
	}
	free(exp.found);
}
/*
locat the 31 and incrementend untill reaching non expandable char
*/

void	expand_it(t_line *lm)
{
	int		start;
	int		end;

	end = 0;
	while (1)
	{
		start = charloc(lm->shx, 31);
		if (start == -1 || !lm->shx[start])
			break ;
		end = start + 1;
		if ((lm->shx[start + 1] == 31 || lm->shx[start + 1] == '?'
				|| ft_isdigit(lm->shx[start + 1]) || lm->shx[start + 1] == '$'))
			end++;
		else
			while (ft_isdigit(lm->shx[end]) || ft_isalpha(lm->shx[end])
				|| lm->shx[end] == '_')
				end++;
		exp_dlr(lm, start, end);
	}
}

void	expand(void)
{
	t_pipe	*sm;
	t_line	*lm;

	sm = g_va.sp;
	while (sm)
	{
		lm = sm->lin;
		while (lm)
		{
			if (ft_strchr(lm->shx, 31))
			{
				put_dlr_bex(lm);
				expand_it(lm);
			}
			lm = lm->nxt;
		}
		sm = sm->nxt;
	}
}
