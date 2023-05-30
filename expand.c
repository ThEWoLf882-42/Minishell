/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 11:11:05 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/05/30 15:35:07 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*
get is the variable in env substr start + 1 to skip $ and len to 
substr is = end - (start + 1),EX: $USER&# len = 4  start + 1 = U, end = &
found is USER variable in env
start + ft_strlen(found) len in the new 
start + ft_strlen(get) + 1 len in the old shx
*/
char	*sp_dlr(char *get, int *bf, int *af)
{
	*bf = 0;
	*af = 0;
	if (!*get)
		return (ft_strdup("$"));
	if (get[0] == 31 && get[1] == '\0')
		return (ft_strdup("69"));
	if (get[0] == '?' && get[1] == '\0')
		return (ft_itoa(g_va.exit_s));
	return (NULL);
}

void	creat_expnod(t_line **newlm, char *found, int bf)
{
	char	**str;
	int		i;

	if (!found)
		return ;
	str = ft_split(found, ' ');
	i = -1;
	if (!bf)
	{
		i = 0;
		free(str[0]);
	}
	while (str[++i])
	{
		ft_backline(newlm, new_lin(str[i]));
		free(str[i]);
	}
	free(str);
}

// add tab maybe <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
char	*which_env(char *get, int *bf, int *af)
{
	t_env	*em;

	*bf = 0;
	*af = 0;
	em = g_va.env;
	if (!*get || (get[0] == 31 && get[1] == '\0')
		|| (get[0] == '?' && get[1] == '\0'))
		return (sp_dlr(get, bf, af));
	while (em)
	{
		if (!ft_strncmp(get, em->arg, ft_strlen(get)))
		{
			if (em->arg[ft_strlen(get) + 1] == ' ')
				*bf = 1;
			if (em->arg[ft_strlen(em->arg) - 1] == ' ')
				*af = 1;
			return (ft_strdup(&em->arg[ft_strlen(get) + 1]));
		}
		em = em->nxt;
	}
	return (NULL);
}

void	expand_that(t_exp_utl *exp, t_line *lm, int start, int end)
{
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
			ft_backline(&exp->newlm, new_lin(ft_substr(lm->shx, end + 1, \
				ft_strlen(lm->shx) - end)));
	}
	else
	{
		if (char_af(lm->shx, end))
			ft_lastline(exp->newlm)->shx = ft_strjoin2fr(\
				ft_lastline(exp->newlm)->shx, ft_substr(lm->shx, end + 1, \
				ft_strlen(lm->shx) - end));
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
		// break;
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
