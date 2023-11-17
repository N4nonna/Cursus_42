/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:25:34 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/17 15:25:36 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = ft_strlen(src);
	dest = malloc(sizeof(char) * (i + 1));
	if (dest == NULL)
		return (0);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/*int	main(int ac, char **av)
{
	(void) ac;
	char	*str = ft_strdup(av[1]);
    char    *str2 = strdup(av[1]);
	printf("My strdup --> %s : %s\n", av[1], str);
    printf("Real stdup --> %s : %s\n", av[1], str2);
	free(str);
	return (0);
}*/
