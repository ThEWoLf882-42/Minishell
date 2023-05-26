/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 22:49:35 by agimi             #+#    #+#             */
/*   Updated: 2023/05/26 20:29:36 by agimi            ###   ########.fr       */
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

void	sig_handel(void)
{
	g_va.sa.sa_handler = &ha_sig;
	sigemptyset(&g_va.sa.sa_mask);
	g_va.sa.sa_flags = SA_RESTART;
	sigaction(SIGQUIT, &g_va.sa, NULL);
	sigaction(SIGINT, &g_va.sa, NULL);
}
