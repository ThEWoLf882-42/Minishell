/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 22:37:18 by agimi             #+#    #+#             */
/*   Updated: 2023/06/10 16:50:47 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset_env(t_env *env, char *s)
{
	t_env	*tenv;

	tenv = NULL;
	while (env)
	{
		if (!ft_strncmp(s, env->arg, ft_strlen(s)))
		{
			if (env->arg[ft_strlen(s)] == '=')
			{	
				if (tenv)
					tenv->nxt = env->nxt;
				else
					g_va.env = g_va.env->nxt;
				free(env->arg);
				env->arg = NULL;
				free(env);
				env = NULL;
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
			if (texp)
				texp->nxt = exp->nxt;
			else
				g_va.xport = g_va.xport->nxt;
			free(exp->xarg);
			free(exp);
			break ;
		}
		texp = exp;
		exp = exp->nxt;
	}
}

void	if_valid(t_line *lm)
{
	if (!valid_exp(lm->shx))
	{
		ft_putstr_fd("minishell-69: ", 2);
		ft_putstr_fd(lm->shx, 2);
		ft_putstr_fd(": not a valid identifier\n", 2);
		g_va.exit_s = 1;
	}
}

void	unset_cmd(t_line *lm, int x)
{
	t_env	*env;
	t_exp	*exp;

	if (!x)
	{
		open_here();
		if (open_file(g_va.sp, x))
			return ;
	}
	while (lm)
	{
		exp = g_va.xport;
		env = g_va.env;
		if_valid(lm);
		if (!ft_strcmp(lm->typ, "arg"))
		{
			unset_env(env, lm->shx);
			unset_xport(exp, lm->shx);
		}
		lm = lm->nxt;
	}
	if (x)
		exit(0);
	close_fd();
}
