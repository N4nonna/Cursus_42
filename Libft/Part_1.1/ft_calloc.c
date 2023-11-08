/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <escoda.manon@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:39:03 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/08 14:51:40 by mescoda          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <stdlib.h>
#include <stdio.h>

void    ft_bzero(void *s, size_t n)
{
    unsigned char *ptr;
    
    ptr = (unsigned char *)s;
    while (n-- > 0)
        *ptr++ = '\0';
    printf("my ft_bzero : %s\n", (unsigned char *)s);
}

void    *ft_calloc(size_t nmemb, size_t size)
{
    void    *ptr;

    if (nmemb == 0 || size == 0)
        nmemb = size = 1;
    ptr = malloc(nmemb * size);
    if (ptr)
        ft_bzero(ptr, (nmemb * size));
    return (ptr);
}

/*int main () {
   int i, n;
   int *a;

   printf("Number of elements to be entered:");
   scanf("%d",&n);

   a = (int*)ft_calloc(n, sizeof(int));
   printf("Enter %d numbers:\n",n);
   for( i=0 ; i < n ; i++ ) {
      scanf("%d",&a[i]);
   }

   printf("The numbers entered are: ");
   for( i=0 ; i < n ; i++ ) {
      printf("%d ",a[i]);
   }
   free( a );
   
   return(0);
}*/