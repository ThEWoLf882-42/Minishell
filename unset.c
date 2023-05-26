/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 22:37:18 by agimi             #+#    #+#             */
/*   Updated: 2023/05/26 15:43:41 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset_cmd(t_line *lm, int x)
{
	t_env	*env;
	t_env	*tenv;
	char	*s;

	if (open_file(g_va.sp, x))
		return ;
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
	close_fd();
}
