/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:25:26 by agimi             #+#    #+#             */
/*   Updated: 2023/05/20 20:15:44 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		add_history(line);
		fill_sp(line);
		fill_lin();
		while (g_va.sp)
		{
			printf("sp: %s\n", g_va.sp->pl);
			g_va.sp = g_va.sp->nxt;
		}
		
	}
}
