/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:08:07 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/03/13 13:29:56 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static size_t	dapply_pro(int fd, const char *frg, size_t n, void	*content);

static size_t	find_end(const char *str, size_t i);

static int		dflag_p(void *ptr, int fd);

int	ft_dprintf(int fd, const char *str, ...)
{
	va_list				va;
	unsigned long long	val;
	size_t				i;
	size_t				end;
	size_t				ret;

	if (!str)
		return (0);
	va_start(va, str);
	val = va_arg(va, t_lluns);
	ret = 0;
	i = 0;
	while (str[i])
	{
		end = find_end(str, i);
		if (end == 0)
			return (0);
		ret += dapply_pro(fd, &str[i], end - i, &val);
		if (str[i] == '%' && str[end - 1] != '%')
			val = va_arg(va, t_lluns);
		i = end;
	}
	va_end(va);
	return (ret);
}

static size_t	dapply_pro(int fd, const char *frg, size_t n, void *val)
{
	if (frg[0] != '%')
		return (ft_putrsstrn_fd(frg, n, fd));
	if (frg[n - 1] == 's' && (*(char **)val) != NULL)
		return (ft_putrsstr_fd(*(char **)val, fd));
	if (frg[n - 1] == 's' && (*(char **)val) == NULL)
		return (ft_putrsstr_fd("(null)", fd));
	if (frg[n - 1] == 'c')
		return (ft_putrschar_fd(*((char *)(val)), fd));
	if (frg[n - 1] == '%')
		return (ft_putrschar_fd('%', fd));
	if (frg[n - 1] == 'u')
		return (ft_putrsuns_fd(*((t_uns *)(val)), fd));
	if (frg[n - 1] == 'p')
		return (dflag_p(val, fd));
	return (ftu_dprintf_proflagextra(frg, n, val, fd));
}

static size_t	find_end(const char *str, size_t i)
{
	size_t	end;

	end = i;
	if (str[end] != '%')
	{
		while (str[end] != '%' && str[end])
			end ++;
		return (end);
	}
	else
	{
		end++;
		while (!ft_cisinstr(str[end], "cspdiuxX%"))
		{
			if (!ft_cisinstr(str[end], "# +"))
				return (0);
			end++;
		}
	}
	return (end + 1);
}

static int	dflag_p(void *ptr, int fd)
{
	t_lluns	pos;

	pos = (t_lluns)(*((void **)ptr));
	if (pos == 0)
		return (ft_putstr_fd("(nil)", fd), 5);
	return (ft_putrsstr_fd("0x", fd)
		+ ft_putrsuns_base_fd((t_uns)pos, B_HEX_MAJ, fd));
}
