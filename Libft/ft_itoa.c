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

void    ft_reverse(char *str, int len)
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
}

char    *ft_itoa(int num, char *str, int base)
{
    int i;
    int isNegative;
    int ret;

    i = 0;
    isNegative = 0;
    ret = 0;
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return (str);
    }
    if (num < 0 && base == 10)
    {
        isNegative = 1;
        num = -num;
    }
    while (num != 0)
    {
        ret = num % base;
        if (ret > 9)
            str[i++] = (ret - 10) + 'a';
        else
            str[i++] = ret + '0';
        num = num / base;
    }
    if (isNegative)
        str[i++] = '-';
    str[i] = '\0';
    ft_reverse(str, i);
    return (str);
}

/*int main()
{
    int number = 1234;
    char string[20];

    ft_itoa(number, string, 10);

    printf("The number %d is represented as string: %s\n", number, string);

    return 0;
}*/