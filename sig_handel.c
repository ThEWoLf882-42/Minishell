/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 22:49:35 by agimi             #+#    #+#             */
/*   Updated: 2023/05/25 13:21:58 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ha_sig(int sig)
{
	// if (sig == SIGQUIT)
	// 	;
	if (sig == SIGTSTP)
	{
		ft_free();
		free_env(&g_va.env);
		exit(0);
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
	// sigaddset(&g_va.sa.sa_mask, SIGQUIT);
	// sigaddset(&g_va.sa.sa_mask, SIGINT);
	sigaction(SIGQUIT, &g_va.sa, NULL);
	sigaction(SIGINT, &g_va.sa, NULL);
}
