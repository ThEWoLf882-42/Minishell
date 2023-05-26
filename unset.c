/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 22:37:18 by agimi             #+#    #+#             */
/*   Updated: 2023/05/25 22:57:06 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset_cmd(t_line *lm, int x)
{
	t_env	*env;
	t_env	*tenv;
	char	*s;

	env = g_va.env;
	if (lm->nxt)
		s = lm->shx;
	while (env)
	{
		tenv = env;
		if (!ft_strncmp(s, env->arg, ft_strlen(s)))
		{
			tenv->nxt = env->nxt;
			free(env->arg);
			free(env);
		}
		env = tenv->nxt;
	}
	if (x)
		exit(0);
}
