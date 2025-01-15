/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftu_printf_processflagextra.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:54:16 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/04/16 18:38:46 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	flag_id_sp(void *val, char c);

static int	dflag_id_sp(void *val, char c, int fd);

size_t	ftu_printf_proflagextra(const char *frg, size_t n, void *val)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((ft_cisinstr(frg[n - 1], "di")) && ft_cisinstr(frg[i], "+ "))
			return (flag_id_sp(val, frg[i]));
		if ((ft_cisinstr(frg[n - 1], "xX")) \
			&& (frg[i] == '#') && !*(t_uns *)(val))
			return (ft_putrschar('0'));
		if ((frg[n - 1] == 'x') && (frg[i] == '#'))
			return (ft_putrsstr("0x") + \
			ft_putrsuns_base(*(t_uns *)(val), B_HEX_MIN));
		if ((frg[n - 1] == 'X') && (frg[i] == '#'))
			return (ft_putrsstr("0X")
				+ ft_putrsuns_base(*(t_uns *)(val), B_HEX_MAJ));
		i++;
	}
	if (frg[n - 1] == 'i' || frg[n - 1] == 'd')
		return (ft_putrsnbr(*((int *)(val))));
	if (frg[n - 1] == 'x')
		return (ft_putrsuns_base(*((t_uns *)(val)), "0123456789abcdef"));
	if (frg[n - 1] == 'X')
		return (ft_putrsuns_base(*((t_uns *)(val)), "0123456789ABCDEF"));
	return (0);
}

size_t	ftu_dprintf_proflagextra(const char *frg, size_t n, void *val, int fd)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((ft_cisinstr(frg[n - 1], "di")) && ft_cisinstr(frg[i], "+ "))
			return (dflag_id_sp(val, frg[i], fd));
		if ((ft_cisinstr(frg[n - 1], "xX")) \
			&& (frg[i] == '#') && !*(t_uns *)(val))
			return (ft_putrschar_fd('0', fd));
		if ((frg[n - 1] == 'x') && (frg[i] == '#'))
			return (ft_putrsstr_fd("0x", fd) + \
			ft_putrsuns_base_fd(*(t_uns *)(val), B_HEX_MIN, fd));
		if ((frg[n - 1] == 'X') && (frg[i] == '#'))
			return (ft_putrsstr_fd("0X", fd)
				+ ft_putrsuns_base_fd(*(t_uns *)(val), B_HEX_MAJ, fd));
		i++;
	}
	if (frg[n - 1] == 'i' || frg[n - 1] == 'd')
		return (ft_putrsnbr_fd(*((int *)(val)), fd));
	if (frg[n - 1] == 'x')
		return (ft_putrsuns_base_fd(*((t_uns *)(val)), B_HEX_MIN, fd));
	if (frg[n - 1] == 'X')
		return (ft_putrsuns_base_fd(*((t_uns *)(val)), B_HEX_MAJ, fd));
	return (0);
}

static int	flag_id_sp(void *val, char c)
{
	if (*((int *)(val)) >= 0)
		return (ft_putrschar(c), ft_putrsnbr(*((int *)(val))));
	return (ft_putrsnbr(*((int *)(val))));
}

static int	dflag_id_sp(void *val, char c, int fd)
{
	if (*((int *)(val)) >= 0)
		return (ft_putrschar_fd(c, fd), ft_putrsnbr_fd(*((int *)(val)), fd));
	return (ft_putrsnbr_fd(*((int *)(val)), fd));
}
