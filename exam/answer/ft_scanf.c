#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

/*
** 공통 패턴 (이것만 기억하면 됨):
**   c = fgetc(f) 로 한 글자씩 꺼내 보고
**   "내 것이 아닌" 글자를 만나면 ungetc(c, f) 로 되돌려 놓는다.
**   (단, EOF는 되돌리지 않는다)
*/

/* ============================================================
** match_space
** [추가] 공백을 전부 먹고, 공백이 아닌 첫 글자는 되돌려 놓음
**        에러(ferror)면 -1, 아니면 1
** ============================================================ */
int	match_space(FILE *f)
{
	int	c = fgetc(f);	// [추가]

	while (c != EOF && isspace(c))	// [추가] 공백이면 계속 먹기
		c = fgetc(f);	// [추가]
	if (c != EOF)	// [추가] 공백 아닌 글자는
		ungetc(c, f);	// [추가] 다시 넣어두기
	if (ferror(f))	// [추가]
		return (-1);	// [추가]
	return (1);	// [수정] 원본: return (0);
}

/* ============================================================
** match_char
** [추가] 형식 문자열의 일반 글자(예: ',')가 입력과 같은지 확인
**        같으면 1, 다르면 되돌려 놓고 -1
** ============================================================ */
int	match_char(FILE *f, char c)
{
	int	in = fgetc(f);	// [추가]

	if (in == c)	// [추가] 일치 -> 소비하고 성공
		return (1);	// [추가]
	if (in != EOF)	// [추가] 불일치 -> 되돌려 놓기
		ungetc(in, f);	// [추가]
	return (-1);	// [수정] 원본: return (0);
}

/* ============================================================
** scan_char  (%c)
** [추가] 공백도 건너뛰지 않고 딱 한 글자 저장
** ============================================================ */
int	scan_char(FILE *f, va_list ap)
{
	int		c = fgetc(f);	// [추가]
	char	*p = va_arg(ap, char *);	// [추가] 다음 인자(char *) 꺼내기

	if (c == EOF)	// [추가]
		return (-1);	// [추가]
	*p = (char)c;	// [추가]
	return (1);	// [수정] 원본: return (0);
}

/* ============================================================
** scan_int  (%d)
** [추가] 부호(+/-) 1개 -> 숫자가 하나도 없으면 실패
**        -> 숫자 끝까지 누적 -> 숫자 아닌 글자는 되돌려 놓기
** (앞 공백은 match_conv가 match_space로 이미 먹어줌)
** ============================================================ */
int	scan_int(FILE *f, va_list ap)
{
	int	*p = va_arg(ap, int *);	// [추가]
	int	sign = 1;	// [추가]
	int	res = 0;	// [추가]
	int	c = fgetc(f);	// [추가]

	if (c == '-' || c == '+')	// [추가] 부호 처리
	{
		if (c == '-')	// [추가]
			sign = -1;	// [추가]
		c = fgetc(f);	// [추가]
	}
	if (!isdigit(c))	// [추가] 숫자가 없다 = 변환 실패
	{
		if (c != EOF)	// [추가]
			ungetc(c, f);	// [추가]
		return (-1);	// [추가]
	}
	while (isdigit(c))	// [추가] 123 = ((1*10)+2)*10+3
	{
		res = res * 10 + (c - '0');	// [추가]
		c = fgetc(f);	// [추가]
	}
	if (c != EOF)	// [추가] 숫자 뒤 글자는 내 것이 아님
		ungetc(c, f);	// [추가]
	*p = res * sign;	// [추가]
	return (1);	// [수정] 원본: return (0);
}

/* ============================================================
** scan_string  (%s)
** [추가] 공백 전까지 복사 -> 끝에 '\0' -> 공백은 되돌려 놓기
** (앞 공백은 match_conv가 이미 먹어줌)
** ============================================================ */
int	scan_string(FILE *f, va_list ap)
{
	char	*s = va_arg(ap, char *);	// [추가]
	int		i = 0;	// [추가]
	int		c = fgetc(f);	// [추가]

	while (c != EOF && !isspace(c))	// [추가] 공백/EOF 전까지
	{
		s[i++] = c;	// [추가]
		c = fgetc(f);	// [추가]
	}
	if (c != EOF)	// [추가] 공백은 다음을 위해 되돌려 놓기
		ungetc(c, f);	// [추가]
	if (i == 0)	// [추가] 한 글자도 못 읽음 = 실패
		return (-1);	// [추가]
	s[i] = '\0';	// [추가]
	return (1);	// [수정] 원본: return (0);
}

/* ============================================================
** match_conv / ft_vfscanf
** [변경 없음] 주어진 그대로
** ============================================================ */
int	match_conv(FILE *f, const char **format, va_list ap)
{
	switch (**format)
	{
		case 'c':
			return scan_char(f, ap);
		case 'd':
			match_space(f);
			return scan_int(f, ap);
		case 's':
			match_space(f);
			return scan_string(f, ap);
		case EOF:
			return -1;
		default:
			return -1;
	}
}

int	ft_vfscanf(FILE *f, const char *format, va_list ap)
{
	int	nconv = 0;

	int c = fgetc(f);
	if (c == EOF)
		return EOF;
	ungetc(c, f);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (match_conv(f, &format, ap) != 1)
				break;
			else
				nconv++;
		}
		else if (isspace(*format))
		{
			if (match_space(f) == -1)
				break;
		}
		else if (match_char(f, *format) != 1)
			break;
		format++;
	}

	if (ferror(f))
		return EOF;
	return nconv;
}

/* ============================================================
** ft_scanf
** [추가] "// ..." 두 자리 = 가변인자 열기/닫기
**        va_list 선언 -> va_start(ap, 마지막 고정인자) -> ... -> va_end
** ============================================================ */
int	ft_scanf(const char *format, ...)
{
	va_list	ap;	// [추가] 원본: // ...

	va_start(ap, format);	// [추가] 원본: // ...
	int ret = ft_vfscanf(stdin, format, ap);
	va_end(ap);	// [추가] 원본: // ...
	return ret;
}
