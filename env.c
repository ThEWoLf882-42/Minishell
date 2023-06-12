/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:31:51 by agimi             #+#    #+#             */
/*   Updated: 2023/06/12 16:20:27 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_cmd(t_line *lm, int x)
{
	t_env	*env;

	if (!x)
	{
		open_here();
		if (open_file(g_va.sp, x))
			return ;
	}
	env = g_va.env;
	if (lm && lm->nxt && (!ft_strcmp(lm->nxt->typ, "arg")
			|| !ft_strcmp(lm->nxt->typ, "ex")))
	{
		print_error(lm->nxt->shx, 127, x);
		close_fd();
		return ;
	}
	while (env)
	{
		ft_putstr_fd(env->arg, 1);
		ft_putchar_fd('\n', 1);
		env = env->nxt;
	}
	if (x)
		exit(0);
	close_fd();
}
