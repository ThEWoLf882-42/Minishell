/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:24:34 by agimi             #+#    #+#             */
/*   Updated: 2023/05/28 16:59:50 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_cmd(int x)
{
	if (!x)
	{
		printf("exit\n");
		free_env(&g_va.env);
		//add free export
	}
	ft_free();
	exit(g_va.exit_s);
}
