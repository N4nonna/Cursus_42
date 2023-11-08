/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <escoda.manon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:42:17 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/08 14:04:19 by mescoda          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdio.h>

int ft_strcmp (char s1, int c)
{
    if (s1 != c)
        return (s1 - c);
    return (s1 - c);
}

int ft_strlen(const char *s)
{
    int i;

    i = 0;
    while(s[i])
        i++;
    return(i - 1);
}

/*char    ft_print(char *s, int i)
{
    int j = 0;
    int slen = ft_strlen(s) - i;
    char ret[slen];
    printf("..ret : %s --> .s : %s --> .i : %d\n", ret, s, i);
    while (s[i] != '\0')
        ret[j++] = s[i++];
    ret[j] = '\0';
    printf("...ret : %s --> .s : %s --> .i : %d\n", ret, s, i);
    return (ret);
}*/

char	*ft_strcpy(char *dest, char *src, int i)
{
	char	*ptr;

	*ptr = *dest;
    printf(".0.ret : %s --> .0.s : %s --> .0.i : %d\n", dest, src, i);
	while (src[i] != '\0')
	{
		*dest = src[i];
		dest++;
		i++;
	}
	*dest = '\0';
	return (ptr);
}

char    *ft_strrchr(const char *str, int c)
{
    char    *temp;
    char    *ret;
    int i;
    int slen;
    char    *cpy;

    temp = (char *)str;
    slen = ft_strlen(temp) - i;
    i = ft_strlen(str);
    cpy = "";
    printf("temp : %s --> i : %d\n", temp, i);
    while (i > 0)
    {
        printf("-temp : %s --> -i : %d\n", temp, i);
        if (ft_strcmp(temp[i], c) == 0)
        {
            int j = 0;
            ret[slen];
            printf(".ret : %s --> .s : %s --> .i : %d\n", ret, temp, i);
            cpy = ft_strcpy(ret, temp, i);
            printf("..ret : %s --> ..s : %s --> ..i : %d\n", ret, temp, i);
            return (cpy);
            printf("...ret : %s --> ...s : %s --> ...i : %d\n", ret, temp, i);
        }
        else if (ft_strcmp(temp[i], c) != 0)
            i--;
    }
    return (0);
}

int main (void)
{
    const char *str = "Il fait beau aujourd'hui !";
    int c = 'a';
    printf ("le reponse est : %s", ft_strrchr(str, c));
}