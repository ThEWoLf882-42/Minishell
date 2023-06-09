/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 22:37:18 by agimi             #+#    #+#             */
/*   Updated: 2023/06/09 15:22:15 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset_env(t_env *env, char *s)
{
	t_env	*tenv;

	while (env)
	{
		if (!ft_strncmp(s, env->arg, ft_strlen(s)))
		{
			if (env->arg[ft_strlen(s)] == '=')
			{	
				if (tenv)
					tenv->nxt = env->nxt;
				else
					g_va.env = env->nxt;
				free(env->arg);
				free(env);
				break ;
			}
		}
		tenv = env;
		env = env->nxt;
	}
}

void	unset_xport(t_exp *exp, char *s)
{
	t_exp	*texp;

	while (exp)
	{
		if (!ft_strncmp(s, exp->xarg, ft_strlen(s)))
		{
			if (exp->xarg[ft_strlen(s)] == '=')
			{
				if (texp)
					texp->nxt = exp->nxt;
				else
					g_va.xport = exp->nxt;
				free(exp->xarg);
				free(exp);
				break ;
			}
		}
		texp = exp;
		exp = exp->nxt;
	}
}

void	unset_cmd(t_line *lm, int x)
{
	t_env	*env;
	t_exp	*exp;
	char	*s;

	if (!x)
	{
		open_here();
		if (open_file(g_va.sp, x))
			return ;
	}
	env = g_va.env;
	exp = g_va.xport;
	while (lm)
	{
		if (!ft_strcmp(lm->typ, "arg"))
		{
			s = lm->shx;
			unset_env(env, s);
			unset_xport(exp, s);
		}
		lm = lm->nxt;
	}
	if (x)
		exit(0);
	close_fd();
}
