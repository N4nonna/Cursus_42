/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <escoda.manon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:54:12 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/08 15:01:22 by mescoda          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *string)
{
	int	i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen(dest);
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int	tab_len(int size, char **tab, char *sep)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < size)
	{
		len = len + ft_strlen(tab[i]);
		i++;
	}
	len = len + (size - 1) * ft_strlen(sep) + 1;
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*dest;

	if (size == 0)
	{
		dest = malloc(sizeof(char));
		*dest = 0;
		return (dest);
	}
	dest = (char *) malloc(sizeof(char) * tab_len(size, strs, sep));
	if (!dest)
		return (NULL);
	*dest = 0;
	i = 0;
	while (i < size)
	{
		ft_strcat(dest, strs[i]);
		if (i <size - 1)
			ft_strcat(dest, sep);
		i++;
	}
	return (dest);
}

/*int	main(int ac, char **av)
{
	printf("%s\n", ft_strjoin(ac - 2, av + 1, av[ac - 1]));
	return (0);
}*/