/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:31:51 by agimi             #+#    #+#             */
/*   Updated: 2023/05/26 15:44:14 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_cmd(int x)
{
	t_env	*env;

	if (open_file(g_va.sp, x))
		return ;
	env = g_va.env;
	while (env)
	{
		printf("%s\n", env->arg);
		env = env->nxt;
	}
	if (x)
		exit(0);
	close_fd();
}
