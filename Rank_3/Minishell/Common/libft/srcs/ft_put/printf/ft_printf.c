/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabonny- <mabonny-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:08:07 by mbonny-e          #+#    #+#             */
/*   Updated: 2024/03/13 13:30:38 by mabonny-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static size_t	apply_pro(const char *frg, size_t n, void	*content);

static size_t	find_end(const char *str, size_t i);

static int		flag_p(void *ptr);

int	ft_printf(const char *str, ...)
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
		ret += apply_pro(&str[i], end - i, &val);
		if (str[i] == '%' && str[end - 1] != '%')
			val = va_arg(va, t_lluns);
		i = end;
	}
	va_end(va);
	return (ret);
}

static size_t	apply_pro(const char *frg, size_t n, void *val)
{
	if (frg[0] != '%')
		return (ft_putrsstrn(frg, n));
	if (frg[n - 1] == 's' && (*(char **)val) != NULL)
		return (ft_putrsstr(*(char **)val));
	if (frg[n - 1] == 's' && (*(char **)val) == NULL)
		return (ft_putrsstr("(null)"));
	if (frg[n - 1] == 'c')
		return (ft_putrschar(*((char *)(val))));
	if (frg[n - 1] == '%')
		return (ft_putrschar('%'));
	if (frg[n - 1] == 'u')
		return (ft_putrsuns(*((t_uns *)(val))));
	if (frg[n - 1] == 'p')
		return (flag_p(val));
	return (ftu_printf_proflagextra(frg, n, val));
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

static int	flag_p(void *ptr)
{
	t_lluns	pos;

	pos = (t_lluns)(*((void **)ptr));
	if (pos == 0)
		return (ft_putstr("(nil)"), 5);
	return (ft_putrsstr("0x") + ft_putrsuns_base((t_uns)pos, B_HEX_MAJ));
}
