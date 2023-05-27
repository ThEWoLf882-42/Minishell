/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:31:51 by agimi             #+#    #+#             */
/*   Updated: 2023/05/27 15:33:08 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_cmd(t_line *lm, int x)
{
	t_env	*env;

	if (open_file(g_va.sp, x))
		return ;
	env = g_va.env;
	if (lm && lm->nxt)
	{
		print_error(lm->nxt->shx, 127, x);
		close_fd();
		return ;
	}
	while (env)
	{
		printf("%s\n", env->arg);
		env = env->nxt;
	}
	if (x)
		exit(0);
	close_fd();
}
