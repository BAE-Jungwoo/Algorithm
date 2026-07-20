# [Gold IV] N Queen - 1889 

[문제 링크](https://jungol.co.kr/problem/1889) 

### 성능 요약

메모리: 0.6 MB, 시간: 299 ms

### 분류

dfs, backtracking, bfs

### 제출 일자

2026년 07월 20일 17:21:10

### 문제 설명

<p style="text-align: justify;">체스에서 queen은 가로, 세로, 대각선 방향으로 어느 곳이나 한 번에 움직일 수 있다.</p><p style="text-align: justify;">즉 다음과 같은 체스판에서 queen이 X라고 표시된 위치에 있을 때,&nbsp;</p><p style="text-align: justify;">그 다음 queen이 움직여 갈수 있는 부분은 어둡게 칠해진 부분 중의 하나이다.</p><figure data-bubble-menu="false"><img crossorigin="anonymous" src="https://u.jungol.co.kr/problem/1889/b4146095-a079-4a9b-ac4d-f548e8896388.png"></figure><p style="text-align: justify;"><math-inline>N \times N</math-inline> 크기의 정방형 체스판이 주어졌다.&nbsp;</p><p style="text-align: justify;">우리는 거기에 <math-inline>N</math-inline>개의 queen을 배치하려고 하는데, 모든 queen들은 서로 잡아먹을 수 없어야 한다.&nbsp;</p><p style="text-align: justify;">그렇다면 queen들을 어떻게 배치해야만 할까?&nbsp;</p><p style="text-align: justify;">&nbsp;</p><p style="text-align: justify;">가능한 모든 경우의 개수를 출력한다.</p>

### 입력

<p>queen의 수 <math-inline>N</math-inline>(<math-inline>1≤N≤13</math-inline>)을 입력 받는다.</p>

### 출력

<p><math-inline>N \times N</math-inline>의 체스판에서 <math-inline>N</math-inline>개의 queen들이 서로 잡아먹지 않는 위치로 놓을 수 있는 방법의 수를 출력한다.</p>

> 출처: JUNGOL, https://jungol.co.kr/problem/1889