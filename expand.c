/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:11:05 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/06/11 10:04:43 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand_that(t_exp_utl *exp, t_line *lm, int start, int end)
{
	char	*lnew;
	size_t	s;

	s = ft_strlen(lm->shx) - end;
	if (exp->bf)
		check_bef(exp, lm, start);
	else
		join_bf(exp, lm->shx, exp->found, start);
	creat_expnod(exp, exp->found, exp->bf);
	if (exp->newlm)
		lnew = ft_lastline(exp->newlm)->shx;
	if (exp->af)
		check_af(exp, lm, s, end);
	else
	{
		if (char_af(lm->shx, end))
			lnew = ft_strjoin2fr(lnew, ft_substr(lm->shx, end, s));
		ft_lastline(exp->newlm)->shx = lnew;
	}
}

void	set_lm(t_line *lm, t_exp_utl *exp)
{
	if (lm->nxt && exp->newlm)
		ft_lastline(exp->newlm)->nxt = lm->nxt;
	if (!exp->newlm)
		exp->newlm = lm->nxt;
	free(lm->shx);
	lm->shx = NULL;
	if (exp->newlm)
	{
		lm->shx = exp->newlm->shx;
		lm->nxt = exp->newlm->nxt;
		free(exp->newlm);
	}
	free(exp->found);
}

void	exp_dlr(t_line *lm, int start, int end)
{
	t_exp_utl	exp;
	char		*get;

	exp.newlm = NULL;
	exp.typ = lm->typ;
	get = ft_substr(lm->shx, start + 1, end - (start + 1));
	exp.found = which_env(get, &exp.bf, &exp.af);
	free(get);
	if (!exp.found && (end - start == (int)ft_strlen(lm->shx)))
	{
		free(lm->shx);
		lm->shx = NULL;
		return ;
	}
	if (ambiguis(exp.found))
		lm->space = 1;
	if (between_dq(lm->shx, end))
		exp_no_split(lm, exp.found, start, end);
	else
	{
		expand_that(&exp, lm, start, end);
		set_lm(lm, &exp);
	}
}

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
		if (!ft_isalpha(lm->shx[end]) && lm->shx[end] != '_')
			exp_dlr(lm, start, end + 1);
		else
		{
			while (ft_isdigit(lm->shx[end]) || ft_isalpha(lm->shx[end])
				|| lm->shx[end] == '_')
				end++;
			exp_dlr(lm, start, end);
		}
	}
}

void	expand(void)
{
	t_pipe	*sm;
	t_line	*lm;
	int		d;

	sm = g_va.sp;
	while (sm)
	{
		lm = sm->lin;
		while (lm)
		{
			d = ft_strchr1(lm->shx, 31);
			if (ft_strchr(lm->shx, 31) && !ft_iss(lm->shx[d + 1]))
			{
				put_dlr_bex(lm);
				expand_it(lm);
			}
			else if (ft_strchr(lm->shx, 31) && ft_iss(lm->shx[d + 1]))
				lm->shx[d] = '$';
			lm = lm->nxt;
		}
		sm = sm->nxt;
	}
}
