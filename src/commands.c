/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gariadno <gariadno@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 02:36:27 by gariadno          #+#    #+#             */
/*   Updated: 2021/03/18 02:32:11 by gariadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

int		ft_exit(t_shell *shell)
{
	ft_putendl_fd("exit", STDOUT_FILENO);
	free_shell(shell);
	exit(EXIT_SUCCESS);
}

char	*get_pwd(void)
{
	char	cwd[4096 + 1];
	char	*pwd;

	pwd = NULL;
	if (getcwd(cwd, 4096) == NULL)
		return (NULL);
	pwd = ft_strdup(cwd);
	return (pwd);
}

int		ft_pwd(char **argv, int fd)
{
	char	*pwd;

	(void)argv;
	pwd = get_pwd();
	if (pwd == NULL)
		return (1);
	ft_putendl_fd(pwd, fd);
	free(pwd);
	return (0);
}

int		ft_cd(char **argv, t_hashtable *env)
{
	char		*old_pwd;
	char		*new_pwd;
	t_variable	*old;
	t_variable	*new;

	old_pwd = get_pwd();
	if (old_pwd == NULL)
		return (1);
	if (chdir(argv[1]) != 0)
	{
		free(old_pwd);
		return (1);
	}
	new_pwd = get_pwd();
	if (new_pwd == NULL)
		return (1);
	old = ht_get(env, "OLDPWD");
	free(old->value);
	old->value = old_pwd;
	new = ht_get(env, "PWD");
	free(new->value);
	new->value = new_pwd;
	return (0);
}
