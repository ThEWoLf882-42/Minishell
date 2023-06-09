/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:07:22 by zouaraqa          #+#    #+#             */
/*   Updated: 2023/06/09 15:21:27 by agimi            ###   ########.fr       */
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
