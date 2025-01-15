/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <mescoda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:37:22 by mescoda           #+#    #+#             */
/*   Updated: 2024/10/25 15:14:20 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

// Initialize the data struct
// Need int	pid[2]; in the struct ?? : data->pid[0] = -1; data->pid[1] = -1;

void	init_data(t_data *data, int ac, char **av)
{
	(void)ac;
	(void)av;
	data->env = NULL;
	data->token = NULL;
	data->cmd = NULL;
	data->exit = 0;
}

/* 
	Create the environment variables
		If malloc fails, return NULL
		Loop through the environment variables
			Copy the environment variables to data->env
			If copy fails, return NULL
	Return 1 if the environment variables are created
*/

int	create_env(t_data *data, char **env)
{
	int		i;
	char	*tmp;

	i = 0;
	while (env[i])
		i++;
	data->env = (char **)malloc(sizeof(char *) * (i + 1));
	if (!data->env)
		return (NULL);
	data->env[i] = '\0';
	while (--i >= 0)
	{
		tmp = ft_strdup(env[i]);
		if (!tmp)
			return (NULL);
		data->env[i] = tmp;
	}
	return (1);
}
/* 
	Check if the line is empty
	Loop through the line
		If the character is a space, continue
		If the character is not a space, return 1
	Return 0 if the line is empty
*/

int	empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && is_space(line[i]))
		i++;
	if (i == ft_strlen(line))
	{
		free(line);
		return (0);
	}
	return (1);
}

int	parse_line(t_data *data, char *line)
{
	if (open_quote(data, line))
	{
		free(line);
		return (0);
	}
	return (1);
}

/* 
	Initialize data first so there is no garbage in the struct
	Then create the environment variables
	If the environment variables are not created, free all the data and exit
		Then read the input from the user
		If the input is empty nor parsed, continue
		If the input is not executed, free all the data and exit
		Free the tokens and commands
	If the input is executed, free all the data and exit 
*/

int	main(int ac, char **av, char **env)
{
	t_data	data;
	char	*line;

	init_data(&data, ac, av);
	if (!create_env(&data, env))
		free_all(&data, ERR_MALLOC, EXT_MALLOC);
	while (1)
	{
		line = read(1, "~ > ", 4);
		if (!line)
			free_all(&data, "Exit\n", &data.exit);
		if (!empty_line(line))
			continue ;
		if (!parse_line(&data, line))
			continue ;
		if (!exec(&data, line))
			free_all(&data, ERR_PIPE, EXT_PIPE);
		free_token(&data.token);
		free_cmd(&data.cmd);
	}
	free_all(&data, 0, -1);
	return (0);
}
