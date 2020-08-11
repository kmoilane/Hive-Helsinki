#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdint.h>
# include <float.h>

# define L				1
# define LL				2
# define BIGL			3
# define H				4
# define HH				5
# define Z				6

# define CONVERS		"cspdiouxXf%"
# define LENGTH			"hlLz"
# define FLAGS			"#0-+ .*0123456789hlLz"
# define ALL			"#0-+ .*0123456789hlLzcspdiouxXf%"

typedef	struct			s_struct
{
	char				*format;

	int					printedn;

	int					pos;
	int					len;
	int					minus; // -
	int					plus; // +
	int					space; // ' '
	int					zero; // 0
	int					hash; // #
	int					sign;
	int					nb;

	int					width; // 0 - 9
	int					precisiontf; // .
	int					precision; // .#
	int					length; // LL HH H L
	
	int					conv1;
	int					conv2;
	int					conv3;
	int					x;
}						t_struct;


int						formatparse(const char *format, t_struct *s, va_list ap, int pos);
int						parsel(t_struct *s, int pos, const char *format, va_list ap);
int						formatparse(const char *format, t_struct *s, va_list ap, int pos);
int						ft_printf(const char *format, ...);

char					*pre_converter(char *str, t_struct *s, char c, int status);
char					*left_convert(char *str, size_t nb, t_struct *s, char c);
char					*right_convert(char *str, size_t nb, t_struct *s, char c);
char					*leftalign(t_struct *s, char *str);
char					*rightalign(t_struct *s, char *str);
char					*swap1(char *joint, char c, int i, int state);
char					*swap2(char *joint, char c, int i, int state);
char					*check_hex_len(unsigned long n, t_struct *s, va_list ap);
char					*check_float_len(long double n, t_struct *s, va_list ap);

void					intistruct(t_struct *s);
void					typedetect(t_struct *s, char c, va_list ap);
void					flags(const char *format, t_struct *s);
void					width(const char *format, t_struct *s, va_list ap);
void					precision(const char *format, t_struct *s, va_list ap);
void					length(const char *format, t_struct *s);
void					modifiers(const char *format, t_struct *s, va_list ap);
void					dealint(t_struct *s, va_list ap);
void					dealperc(t_struct *s);
void					dealchar(t_struct *s, va_list ap);
void					dealstring(t_struct *s, va_list ap);
void					dealpointer(t_struct *s, va_list ap);
void					dealoctal(t_struct *s, va_list ap);
void					dealudi(t_struct *s, va_list ap);
void					dealhex(t_struct *s, va_list ap);
void					dealfloat(t_struct *s, va_list ap);

#endif
