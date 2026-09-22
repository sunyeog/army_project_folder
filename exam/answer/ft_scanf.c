/*
 * ft_scanf — 정답본
 *
 * 뼈대는 한 글자도 지우지 않았다.
 *   - 다섯 함수: 비어 있던 "// You may insert code here" 자리에만 코드 추가
 *                (맨 끝 return (0); 은 뼈대 그대로 두고, 실패 경로로 그대로 사용)
 *   - ft_scanf : "// ..." 두 자리를 채움 (필수)
 *   - ft_vfscanf: 두 줄 추가 (선택, 아래 설명)
 *
 * 외우기: 다섯 함수 전부 같은 모양
 *     c = fgetc(f);                  ← 한 글자 꺼내기
 *     while (조건에 맞는 동안) 처리하고 c = fgetc(f);
 *     if (c != EOF) ungetc(c, f);    ← 안 맞은 마지막 글자 돌려놓기
 *     성공이면 return (1);           ← 실패면 그대로 흘러내려 뼈대의 return (0)
 *
 * 주의: va_list를 값으로 넘기는 뼈대 구조라 x86_64(시험장)에선 정상,
 *       Apple Silicon 맥에서는 이상하게 동작할 수 있음.
 */

#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

int match_space(FILE *f)
{
	int c = fgetc(f);                          // [추가] 한 글자 꺼내기

	while (c != EOF && isspace(c))             // [추가] 공백인 동안
		c = fgetc(f);                          // [추가]   계속 꺼내서 버리기
	if (c != EOF)                              // [추가] 공백 아닌 글자는 다음 변환의 몫
		ungetc(c, f);                          // [추가]   돌려놓기
	return (0);                                // 뼈대 그대로 (공백 0개여도 성공)
}

int match_char(FILE *f, char c)
{
	int got = fgetc(f);                        // [추가] 입력 한 글자 꺼내기

	if (got == c)                              // [추가] format 글자와 같으면
		return (1);                            // [추가]   먹고 성공
	if (got != EOF)                            // [추가] 다르면 (EOF는 글자가 아니므로 제외)
		ungetc(got, f);                        // [추가]   돌려놓기
	return (0);                                // 뼈대 그대로 (매칭 실패 → vfscanf가 멈춤)
}

int scan_char(FILE *f, va_list ap)
{
	int c = fgetc(f);                          // [추가] 한 글자 꺼내기 (공백도 그대로 읽음)

	if (c != EOF)                              // [추가] 읽을 게 있으면
	{
		*va_arg(ap, char *) = c;               // [추가]   다음 가변인자(char *)가 가리키는 곳에 저장
		return (1);                            // [추가]   성공
	}
	return (0);                                // 뼈대 그대로 (실패)
}

int scan_int(FILE *f, va_list ap)
{
	int sign = 1;                              // [추가] 부호 (기본 +)
	int res = 0;                               // [추가] 누적 결과
	int count = 0;                             // [추가] 읽은 숫자 개수
	int c = fgetc(f);                          // [추가] 앞 공백은 match_conv가 이미 먹은 상태

	if (c == '-' || c == '+')                  // [추가] 부호가 있으면
	{
		if (c == '-')                          // [추가]
			sign = -1;                         // [추가]   음수 기억
		c = fgetc(f);                          // [추가]   부호는 먹고 다음 글자로
	}
	while (c != EOF && isdigit(c))             // [추가] 숫자인 동안
	{
		res = res * 10 + (c - '0');            // [추가]   atoi 원리: '7' - '0' = 7
		count++;                               // [추가]
		c = fgetc(f);                          // [추가]
	}
	if (c != EOF)                              // [추가] 숫자 아닌 글자는 돌려놓기
		ungetc(c, f);                          // [추가]   예) "17abc" → 'a' 돌려놓음
	if (count > 0)                             // [추가] 숫자를 하나라도 읽었으면
	{
		*va_arg(ap, int *) = res * sign;       // [추가]   다음 가변인자(int *)에 저장
		return (1);                            // [추가]   성공
	}
	return (0);                                // 뼈대 그대로 (숫자 0개 = 실패, 변수는 건드리지 않음)
}

int scan_string(FILE *f, va_list ap)
{
	char *s = va_arg(ap, char *);              // [추가] 사용자 배열 주소 먼저 꺼내기
	int count = 0;                             // [추가] 저장한 글자 수 = 다음 인덱스
	int c = fgetc(f);                          // [추가] 앞 공백은 match_conv가 이미 먹은 상태

	while (c != EOF && !isspace(c))            // [추가] 공백이 아닌 동안  ← scan_int와 쌍둥이 구조
	{
		s[count++] = c;                        // [추가]   배열에 저장
		c = fgetc(f);                          // [추가]
	}
	if (c != EOF)                              // [추가] 공백은 돌려놓기
		ungetc(c, f);                          // [추가]   예) "hello world" → ' ' 돌려놓음
	if (count > 0)                             // [추가] 한 글자라도 읽었으면
	{
		s[count] = '\0';                       // [추가]   끝 표시 (빠뜨리면 printf가 쓰레기까지 출력)
		return (1);                            // [추가]   성공
	}
	return (0);                                // 뼈대 그대로 (실패)
}


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

int ft_vfscanf(FILE *f, const char *format, va_list ap)
{
	int nconv = 0;

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
	if (nconv == 0 && feof(f))                 // [추가] 원본: 없음 (선택 사항)
		return EOF;                            // [추가]   뼈대는 맨 처음에만 EOF 검사해서,
	return nconv;                              //   format "%d" + 입력 "   " 일 때 0을 반환한다
}                                              //   (진짜 scanf는 -1) → 이 두 줄로 맞춤


int ft_scanf(const char *format, ...)
{
	va_list	ap;                                // [수정] 원본: // ...  → 가변인자 목록 변수 선언

	va_start(ap, format);                      // [수정] 원본: // ...  → format 다음 인자부터 시작
	int ret = ft_vfscanf(stdin, format, ap);   // 뼈대 그대로
	va_end(ap);                                // [수정] 원본: // ...  → va_start와 짝으로 정리
	return ret;                                // 뼈대 그대로
}
