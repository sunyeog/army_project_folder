/*
 * broken_gnl — 정답본
 *
 * 외우기: 유틸은 "끝 · 개수 · NULL · 방향"   (FIX 1~5)
 *         GNL은  "누수 · EOF · 갱신 · 밀기"   (FIX 6~9)
 *
 * 표기: // [FIX n] 수정 | 원본: ...   → 원본 줄을 고친 곳
 *       // [FIX n] 추가 | 원본: 없음  → 원본에 없던 줄
 *       주석 없는 줄은 원본 그대로
 */

#include "get_next_line.h"

char *ft_strchr(char *s, int c)
{
	int i = 0;
	while (s[i] && s[i] != c)                        // [FIX 1] 수정 | 원본: while (s[i] != c)
		i++;                                         //   → c가 없으면 '\0'을 지나 메모리 밖까지 달림
	if (s[i] == c)                                   //   → s[i]가 '\0'이면 멈추도록 조건 추가
		return s + i;
	else
		return NULL;
}

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	while (n-- > 0)                                  // [FIX 2] 수정 | 원본: while (--n > 0)
		((char *)dest)[n] = ((char *)src)[n];        // [FIX 2] 수정 | 원본: dest[n - 1] = src[n - 1]
	return dest;                                     //   → 원본은 먼저 줄고 비교해서 1글자 덜 복사 (n=1이면 0글자)
}                                                    //   → 수정본은 n-1, ..., 0 순서 = "뒤에서부터" 복사 (FIX 4에서 활용)

size_t ft_strlen(char *s)
{
	size_t res = 0;
	if (!s)                                          // [FIX 3] 추가 | 원본: 없음
		return (0);                                  //   → 첫 호출 때 ret == NULL → ft_strlen(NULL) → 세그폴트 방지
	while (*s)
	{
		s++;
		res++;
	}
	return res;
}

int str_append_mem(char **s1, char *s2, size_t size2)
{
	size_t size1 = ft_strlen(*s1);
	char *tmp = malloc(size2 + size1 + 1);
	if (!tmp)
		return 0;                                    // (원본 그대로) 실패 시 free(*s1) 전에 나감 → *s1은 살아 있음
	ft_memcpy(tmp, *s1, size1);
	ft_memcpy(tmp + size1, s2, size2);
	tmp[size1 + size2] = '\0';
	free(*s1);                                       // (원본 그대로) 성공했을 때만 옛 문자열 반납
	*s1 = tmp;
	return 1;
}

int str_append_str(char **s1, char *s2)
{
	return str_append_mem(s1, s2, ft_strlen(s2));
}

void *ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest > src)
		return ft_memcpy(dest, src, n);              // [FIX 4] 수정 | 원본: return ft_memmove(dest, src, n);
	else if (dest == src)                            //   → 자기 자신을 똑같이 호출 = 무한 재귀
		return dest;                                 //   → dest가 뒤면 "뒤에서부터" 복사해야 안전 = FIX 2의 memcpy
	size_t i = 0;                                    // [FIX 5] 수정 | 원본: size_t i = ft_strlen((char *)src) - 1;
	while (i < n)                                    // [FIX 5] 수정 | 원본: while (i >= 0)
	{                                                //   → size_t는 음수가 없어 i >= 0 은 항상 참 = 무한 루프
		((char *)dest)[i] = ((char *)src)[i];        //   → 개수도 strlen이 아니라 n 기준이어야 함
		i++;                                         // [FIX 5] 수정 | 원본: i--;
	}                                                //   → dest가 앞이면 "앞에서부터" 복사 (GNL은 항상 이 경로)
	return dest;
}

char *get_next_line(int fd)
{
	static char b[BUFFER_SIZE + 1] = "";             // 컨베이어 벨트: 호출 사이에 남은 글자 보관
	char *ret = NULL;                                // 이번에 반환할 줄
	char *tmp = ft_strchr(b, '\n');                  // b 안의 '\n' 위치 (없으면 NULL)
	while (!tmp)
	{
		if (!str_append_str(&ret, b))
			return (free(ret), NULL);                // [FIX 6] 수정 | 원본: return (NULL);
		int read_ret = read(fd, b, BUFFER_SIZE);     //   → 모아 둔 ret이 누수. 실패 시 ret은 아직 살아 있어 free 안전
		if (read_ret <= 0)                           // [FIX 7] 수정 | 원본: if (read_ret == -1)
		{                                            //   → 0(EOF)을 안 잡아서 루프가 영원히 돎
			b[0] = '\0';                             // [FIX 7] 추가 | 원본: 없음 → 다음 호출에 옛 내용이 안 나오게 비움
			if (read_ret == 0 && ret && *ret)        // [FIX 7] 추가 | 원본: 없음 → EOF + 모은 게 있으면 마지막 줄 반환
				return ret;                          //   → ret이 ""(빈 문자열)일 수 있어서 *ret까지 확인
			free(ret);                               // [FIX 7] 추가 | 원본: 없음 → 모은 게 없거나 에러면 정리
			return (NULL);                           // (원본 그대로)
		}
		b[read_ret] = 0;
		tmp = ft_strchr(b, '\n');                    // [FIX 8] 추가 | 원본: 없음
	}                                                //   → tmp를 다시 안 찾아서 영원히 NULL = 루프 탈출 불가
	if (!str_append_mem(&ret, b, tmp - b + 1))       // (원본 그대로) '\n'까지 포함: 길이 = (tmp - b) + 1
	{
		free(ret);
		return NULL;
	}
	ft_memmove(b, tmp + 1, ft_strlen(tmp + 1) + 1);  // [FIX 9] 추가 | 원본: 없음 (memmove가 안 쓰이던 이유!)
	return ret;                                      //   → 반환한 줄을 b에서 안 지워서 같은 줄이 또 나옴
}                                                    //   → '\n' 다음부터 '\0'까지(+1) b 맨 앞으로 당김
                                                     //     전: [L i n e 1 \n L i n e 2 \0]
                                                     //     후: [L i n e 2 \0 ...]
