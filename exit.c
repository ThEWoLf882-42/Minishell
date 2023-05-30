/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:24:34 by agimi             #+#    #+#             */
/*   Updated: 2023/05/30 18:42:03 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
//no argument <<<<<<<<<<<<<<<<<<<<<<<<<<<
void	exit_cmd(int x)
{
	if (!x)
	{
		printf("exit\n");
		free_env(&g_va.env);
		free_exp(&g_va.xport);
	}
	ft_free();
	exit(g_va.exit_s);
}
