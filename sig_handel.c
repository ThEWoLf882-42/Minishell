/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 22:49:35 by agimi             #+#    #+#             */
/*   Updated: 2023/06/06 12:51:17 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ha_sig(int sig)
{
	if (sig == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
	if (sig == SIGINT)
	{
		rl_replace_line("", 0);
		printf("\n");
		rl_on_new_line();
		rl_redisplay();
	}
}

void	her_func(int sig)
{
	if (sig == SIGINT)
	{
		g_va.x = 1;
		printf("\n");
		rl_on_new_line();
		rl_redisplay();
	}
}

void	sig_handel(void)
{
	g_va.sa.sa_handler = &ha_sig;
	g_va.child_sa.sa_handler = &her_func;
	sigemptyset(&g_va.sa.sa_mask);
	g_va.sa.sa_flags = SA_RESTART;
	sigaction(SIGQUIT, &g_va.sa, NULL);
	sigaction(SIGINT, &g_va.sa, NULL);
}
