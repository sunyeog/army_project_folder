*This project has been created as part of the 42 curriculum by sunhnoh.*

# Minitalk

## Description

Minitalk은 UNIX 신호(signal)만을 이용해 두 프로세스(client와 server) 사이에서 문자열을 주고받는 소규모 데이터 교환 프로그램입니다.

server를 먼저 실행하면 자신의 PID를 출력하고, client는 그 PID를 받아 전달할 문자열을 신호로 변환해 전송합니다. 문자 하나(1바이트 = 8비트)를 두 종류의 신호로 표현하며, `SIGUSR1`을 비트 `1`, `SIGUSR2`를 비트 `0`으로 대응시켜 한 글자당 8번의 신호로 전송합니다. server는 수신한 신호를 비트 단위로 재조립해 문자로 복원하고 출력합니다.

문자열의 끝은 널 문자(`\0`)로 표시하며, server는 재시작 없이 여러 client의 요청을 연속으로 처리할 수 있습니다.

## Instructions

### 컴파일

```bash
# 필수(mandatory) 파트 빌드
make

# 보너스(bonus) 파트 빌드
make bonus
```

| 규칙 | 설명 |
|------|------|
| `make` / `make all` | `server`, `client` 실행 파일 생성 |
| `make bonus` | `server_bonus`, `client_bonus` 실행 파일 생성 |
| `make clean` | 오브젝트 파일(`.o`) 삭제 |
| `make fclean` | 오브젝트 파일과 실행 파일 모두 삭제 |
| `make re` | 전체 재빌드 |

### 실행

터미널을 두 개 사용합니다.

```bash
# 터미널 1 — server 먼저 실행 (PID 출력됨)
./server

# 터미널 2 — 출력된 PID와 보낼 문자열을 인자로 전달
./client [SERVER_PID] "Hello, 42!"
```

보너스 버전도 동일한 방식으로 실행합니다.

```bash
./server_bonus
./client_bonus [SERVER_PID] "Hello, 42!"
```

## Features

- **Mandatory**: 신호 기반 문자열 전송, PID 출력, 다중 client 연속 처리, 인자 개수 예외 처리
- **Bonus**: server가 각 신호 수신 시 client에게 확인(ACK) 신호를 되돌려주는 동기화 방식 구현. `SA_SIGINFO`와 `siginfo_t`의 `si_pid`를 이용해 신호를 보낸 client의 PID를 식별합니다.

## Technical Choices

- **동기화 방식**
  - Mandatory: client가 각 신호 전송 후 `usleep`으로 짧은 지연을 두어 신호 유실을 방지합니다.
  - Bonus: `usleep` 대신 `pause`로 server의 ACK 응답을 기다린 뒤 다음 신호를 전송합니다. 짐작에 의존하는 지연 대신 확실한 확인 응답을 사용하므로 더 안정적입니다.
- **경쟁 상태(race condition) 처리**: 보너스에서 client가 `pause`에 진입하기 전에 server의 ACK가 먼저 도착하면 데드락이 발생할 수 있습니다. 이를 막기 위해 server 핸들러에서 ACK를 보내기 직전 짧은 `usleep`을 두어 client가 대기 상태에 안전하게 진입할 시간을 확보했습니다.
- **`sigaction` 사용**: 구버전 `signal` 대신 동작이 명확하고 이식성이 높은 `sigaction`을 사용했습니다.
- **`static` 변수**: server 핸들러는 인자로 신호 번호만 받으므로, 비트 위치(`i`)와 조립 중인 문자(`c`)를 `static` 지역 변수로 유지해 신호 호출 간에 값을 보존합니다.

## Resources

- **`man` 페이지**: `signal`, `sigaction`, `sigemptyset`, `kill`, `getpid`, `pause`, `usleep`
- **UNIX 신호 개념**: 프로세스 간 통신(IPC), `SIGUSR1`/`SIGUSR2` 사용자 정의 신호
- **비트 연산**: 시프트(`<<`, `>>`)와 마스킹(`&`, `|=`)을 이용한 문자↔비트 변환
- **AI 사용 내역**: 학습 과정에서 AI(Claude)를 프로세스·PID·신호·비트 연산 등 배경 개념 이해와 코드 리뷰(로직 흐름 점검, race condition 원인 분석, Makefile 검토)에 활용했습니다. 코드 작성 자체는 직접 수행했으며, AI가 생성한 완성 코드를 그대로 복사해 사용하지 않았습니다.
