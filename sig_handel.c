/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 22:49:35 by agimi             #+#    #+#             */
/*   Updated: 2023/05/26 16:33:35 by agimi            ###   ########.fr       */
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
		printf("\n");
		// rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

//ctrl-"\"
//ctrl-C
//ctrl-D ctrl-Z??
void	sig_handel(void)
{
	g_va.sa.sa_handler = &ha_sig;
	sigemptyset(&g_va.sa.sa_mask);
	g_va.sa.sa_flags = SA_RESTART;
	sigaction(SIGQUIT, &g_va.sa, NULL);
	sigaction(SIGINT, &g_va.sa, NULL);
}
