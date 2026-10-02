#include "get_next_line.h"

/* ============================================================
** ft_strchr
** [수정] while 조건에 s[i] && 추가
**        -> 원본은 c가 없으면 '\0'을 지나쳐 메모리 끝까지 달려감
** ============================================================ */
char	*ft_strchr(char *s, int c)
{
	int	i = 0;

	while (s[i] && s[i] != c)	// [수정] 원본: while (s[i] != c)
		i++;
	if (s[i] == c)
		return (s + i);
	else
		return (NULL);
}

/* ============================================================
** ft_memcpy
** [수정] --n > 0, [n - 1]  ->  n-- > 0, [n]
**        -> 원본은 마지막 1바이트를 빼먹음 (n=3이면 [1],[0]만 복사)
**        -> 뒤에서부터 복사하는 방식은 그대로 유지
**           (그래서 memmove의 dest > src 경우에도 안전함)
** ============================================================ */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	while (n-- > 0)	// [수정] 원본: while (--n > 0)
		((char *)dest)[n] = ((char *)src)[n];	// [수정] 원본: [n - 1]
	return (dest);
}

/* ============================================================
** ft_strlen
** [추가] NULL 가드
**        -> gnl 첫 호출 때 ret == NULL 상태로 str_append_mem이
**           ft_strlen(*s1)을 부르므로, 가드가 없으면 바로 segfault
** ============================================================ */
size_t	ft_strlen(char *s)
{
	size_t	ret = 0;

	if (!s)	// [추가]
		return (0);	// [추가]
	while (*s)
	{
		s++;
		ret++;
	}
	return (ret);
}

/* ============================================================
** str_append_mem
** [변경 없음] 원본 그대로 (ft_strlen이 NULL을 처리하게 되어 정상 동작)
** ============================================================ */
int	str_append_mem(char **s1, char *s2, size_t size2)
{
	size_t	size1 = ft_strlen(*s1);
	char	*tmp = malloc(size2 + size1 + 1);

	if (!tmp)
		return (0);
	ft_memcpy(tmp, *s1, size1);
	ft_memcpy(tmp + size1, s2, size2);
	tmp[size1 + size2] = 0;
	free(*s1);
	*s1 = tmp;
	return (1);
}

/* ============================================================
** str_append_str
** [변경 없음]
** ============================================================ */
int	str_append_str(char **s1, char *s2)
{
	return (str_append_mem(s1, s2, ft_strlen(s2)));
}

/* ============================================================
** ft_memmove
** [수정] 마지막 루프를 "앞에서부터 i < n 까지"로 교체
**        -> 원본: size_t i = strlen(src) - 1; while (i >= 0) i--;
**           size_t는 음수가 없어서 i >= 0은 항상 참 = 무한루프
**           또 n 대신 strlen을 써서 길이도 틀림
**        -> 여기 오는 건 dest < src인 경우라 앞에서부터 복사해야 안전
** ============================================================ */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i = 0;	// [수정] 원본: size_t i = ft_strlen((char *)src) - 1;

	if (dest > src)
		return (ft_memcpy(dest, src, n));
	else if (dest == src)
		return (dest);
	while (i < n)	// [수정] 원본: while (i >= 0)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;	// [수정] 원본: i--;
	}
	return (dest);
}

/* ============================================================
** get_next_line
** [수정 1] str_append_str 실패 시 free(ret) 추가 (누수 방지)
** [수정 2] read_ret == -1만 보던 것을 <= 0 으로
**          -> 0(EOF)일 때 버퍼 비우고, 모은 게 있으면 반환 / 없으면 NULL
** [추가 3] 루프 끝에서 tmp = ft_strchr(b, '\n') 다시 검사
**          -> 원본은 tmp를 갱신하지 않아 무한루프
** [추가 4] 줄을 잘라 준 뒤 '\n' 뒤 나머지를 b 맨 앞으로 당기기 (memmove)
**          -> 원본은 이게 없어서 다음 호출 때 같은 줄을 또 반환
** ============================================================ */
char	*get_next_line(int fd)
{
	static char	b[BUFFER_SIZE + 1] = "";
	char		*ret = NULL;
	char		*tmp = ft_strchr(b, '\n');

	while (!tmp)
	{
		if (!str_append_str(&ret, b))
			return (free(ret), NULL);	// [수정 1] 원본: return (NULL);
		int read_ret = read(fd, b, BUFFER_SIZE);
		if (read_ret <= 0)	// [수정 2] 원본: if (read_ret == -1)
		{
			b[0] = '\0';	// [추가 2] 다음 호출을 위해 버퍼 비우기
			if (read_ret == 0 && ret && *ret)	// [추가 2] EOF + 모은 내용 있음
				return (ret);	// [추가 2] 마지막 줄(개행 없음) 반환
			free(ret);	// [추가 2] 에러거나 빈 내용이면 해제
			return (NULL);
		}
		b[read_ret] = 0;
		tmp = ft_strchr(b, '\n');	// [추가 3] 새로 읽은 버퍼에서 '\n' 다시 찾기
	}
	if (!str_append_mem(&ret, b, tmp - b + 1))
	{
		free(ret);
		return (NULL);
	}
	ft_memmove(b, tmp + 1, ft_strlen(tmp + 1) + 1);	// [추가 4] +1은 '\0'까지 옮기기
	return (ret);
}
