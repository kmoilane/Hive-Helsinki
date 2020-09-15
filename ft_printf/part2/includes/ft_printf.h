#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <float.h>

# define ALL		"cspdiouxXfhlL%#0-+.* 0123456789"
# define CONVERS	"cspdiouxXf%"
# define LENGTH		"hlL"
# define FLAGS		"hlL#0-+ .*0123456789"

# define H			1
# define HH			2
# define LL			3
# define L			4
# define CAPL		5

typedef	struct		s_printf
{
	char			*format;
	int				total_printed;
	int				pos;
	int				length;
	int				minus;
	int				plus;
	int				space;
	int				hash;
	int				zero;
	int				width;
	int				precision;
	char			conv_c;
}					t_printf;

int					ft_printf(const char *format, ...);
int					detect_modifiers(t_printf *data_t, const char *format,
					va_list ap, int pos);
int					parse_format(t_printf *data_t, const char *format,
					va_list ap, int	pos);

void				init_struct(t_printf *data_t);
void				get_flags(t_printf *data_t, const char *format);
void				get_width(t_printf *data_t, const char *format, va_list ap);
void				get_precision(t_printf *data_t, const char *format, va_list ap);
void				get_length(t_printf *data_t, const char *format);
void				convert_char(t_printf *data_t, va_list ap);
void				convert_string(t_printf *data_t, va_list ap);
void				convert_pointer(t_printf *data_t, va_list ap);

#endif
