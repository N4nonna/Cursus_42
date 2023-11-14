/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <escoda.manon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 21:15:13 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/09 21:15:15 by mescoda          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

/*void    ft_reverse(char *str, int len)
{
    int start;
    int end;
    char    temp;

    start = 0;
    end = len - 1;
    while (start < end)
    {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}*/

int ft_len_itoa(int n)
{
    size_t i;

    i = 0;
    if (n < 0)
        i++;
    if (!n)
        return (i + 1);
    while (n)
    {
        i++;
        n = n / 10;
    }
    return (i);
}

static char *ft_intTochar(int n)
{
    size_t i;
    char    *str;

    str = malloc(sizeof(char *) * ft_len_itoa(n) + 1);
    if (!str)
        return(NULL);
    i = ft_len_itoa(n) - 1;
    str[ft_len_itoa(n)] = '\0';
    if (n < 0)
    {
        str[0] = '-';
        n = -n;
    }
    if (!n) {
        str[i] = '0';
        return(str);
    }
    while (n != 0)
    {
        str[i--] = n % 10 + '0';
        n = n / 10;
    }
    /*if (i == 0)
        str[i++] = '0';*/
    
    // ft_reverse(str, i);
    return (str);
}

char *ft_itoa(int n)
{
    char    *s;
    // size_t  len;
    // size_t  i;

    s = ft_intTochar(n);
    // if (!str)
        // return (0);
    // len = ft_strlen((const char *)str);
    // s = malloc(sizeof(char) * (len + 1));
    // if (!s)
        // return (NULL);
    // i = 0;
    // while (i < len)
    // {
        // s[i] = str[i];
        // i++;
    // }
    // s[i] = '\0';
    return (s);
}

// int main(int ac, char **av) {
//     printf("itoa = %s\n", ft_itoa(atoi(av[1])));
//     return(0);
// }

/*int main()
{
    int number = 1234;
    char string[20];

    ft_itoa(number, string, 10);

    printf("The number %d is represented as string: %s\n", number, string);

    return 0;
}*/