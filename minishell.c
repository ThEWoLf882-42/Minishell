/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:25:26 by agimi             #+#    #+#             */
/*   Updated: 2023/05/21 11:13:12 by zouaraqa         ###   ########.fr       */
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
		trim_space(line);
		fill_sp(line);
		fill_lin();
		// delete_space();
		while (g_va.sp)
		{
			printf("sp: [%s]\n", g_va.sp->pl);
			while (g_va.sp->lin)
			{
				printf("	lin: (%s)\n", g_va.sp->lin->shx);
				g_va.sp->lin = g_va.sp->lin->nxt;
			}
			g_va.sp = g_va.sp->nxt;
		}
	}
}
