/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 22:37:18 by agimi             #+#    #+#             */
/*   Updated: 2023/05/26 21:34:33 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset_loop(t_env *env, t_env *tenv, char *s)
{
	while (env)
	{
		if (!ft_strncmp(s, env->arg, ft_strlen(s)))
		{
			if (tenv)
				tenv->nxt = env->nxt;
			else
				g_va.env = env->nxt;
			free(env->arg);
			free(env);
			break ;
		}
		tenv = env;
		env = env->nxt;
	}
}

void	unset_cmd(t_line *lm, int x)
{
	t_env	*env;
	t_env	*tenv;
	char	*s;

	if (open_file(g_va.sp, x))
		return ;
	env = g_va.env;
	if (lm && lm->nxt)
		s = lm->nxt->shx;
	unset_loop(env, tenv, s);
	if (x)
		exit(0);
	close_fd();
}
