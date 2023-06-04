/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:50:08 by agimi             #+#    #+#             */
/*   Updated: 2023/06/04 16:21:55 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_pipe(void)
{
	t_pipe	*mv;

	mv = g_va.sp;
	while (mv)
	{
		if (!mv->lin)
			return (write(2,
					"syntax error near unexpected token `|'\n", 40), 1);
		mv = mv->nxt;
	}
	return (0);
}
