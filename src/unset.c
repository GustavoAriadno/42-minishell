/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroque <aroque@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 22:01:22 by aroque            #+#    #+#             */
/*   Updated: 2021/03/16 20:45:38 by aroque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"
#include "minishell.h"

int		ft_unset(char **argv, t_hashtable *env)
{
	argv++;
	while (*argv)
		ht_remove(env, *argv++, free_variable);
	return (0);
}