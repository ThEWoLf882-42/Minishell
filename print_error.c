/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zouaraqa <zouaraqa@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:07:22 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/06/05 14:43:03 by zouaraqa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_error(char *str, int exn, int x)
{
	write(2, "minishell-69: ", 14);
	perror(str);
	if (x)
		exit(exn);
	g_va.exit_s = exn;
}
