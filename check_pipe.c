/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:50:08 by agimi             #+#    #+#             */
/*   Updated: 2023/06/07 19:05:50 by agimi            ###   ########.fr       */
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
					"syntax error near unexpected token `|'\n", 39), 1);
		mv = mv->nxt;
	}
	return (0);
}
