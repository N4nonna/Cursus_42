/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <escoda.manon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:51:52 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/10 13:13:47 by mescoda          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdlib.h>
#include <stdio.h>

void ft_striteri(char *s, void (*f)(unsigned int, char*))
{
    unsigned int i;
    
    i = 0;
    if (s || f)
    {
        while (*s)
            f(i++, s++);
    }
    printf("New string : %s\n", s);
}

/*void f(unsigned int i, char *s)
{
    *s = *s + i;
}

int main ()
{
    char *string = "Hello, World!";
    printf("Original string : %s\n", string);
    ft_striteri(string, *f);
    return 0;
}*/