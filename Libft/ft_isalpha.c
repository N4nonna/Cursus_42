/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mescoda <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:11:41 by mescoda           #+#    #+#             */
/*   Updated: 2023/11/06 12:11:44 by mescoda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_isalpha (int c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/*void main (void)
{
    unsigned char c;

    c = 'a';
    ft_isalpha(c);
}*/