# [Gold IV] Road Reconstruction - 20046 

[문제 링크](https://www.acmicpc.net/problem/20046) 

### 성능 요약

메모리: 97852 KB, 시간: 788 ms

### 분류

그래프 이론, 그래프 탐색, 최단 경로, 데이크스트라, 격자 그래프

### 제출 일자

2025년 7월 28일 15:56:44

### 문제 설명

<p>홍수의 발생으로 인해 도시의 도로들이 유실되어 많은 ICP(International Computational Plan) 시민들이 불편을 겪고 있다. 도시는 아래와 같은 격자 형태로 표현이 된다고 가정하자. 검정색 단위 격자가 ‘단위도로’를 의미하며 흰색 단위 격자는 도로가 없었거나 유실된 상태를 의미한다. X로 표시된 단위 격자는 도로를 건설할 수 없는 곳을 의미한다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/df7d65d1-1d60-4456-9c6e-a6803e331039/-/preview/" style="width: 277px; height: 181px;"></p>

<p>도시의 차들은 단위 도로 상에서 가로나 세로 방향으로만 움직인다고 가정했을 때 도시의 기능을 회복시키기 위해 맨 왼쪽 위 단위 격자에서 맨 오른쪽 아래 단위 격자로 도시의 차들이 가는 경로를 만들기 위해 필요한 최소한의 도로 건설 비용을 계산하고자 한다. 단위 도로 하나를 건설하기 위해 1 또는 2 의 비용이 소요된다고 가정하자. 위 그림에서는 흰색 단위 격자에 단위 도로 하나를 건설하기 위해서는 1 의 비용이 든다고 가정한다.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/d9529215-aabf-4b65-875a-94bd6752386c/-/preview/" style="width: 273px; height: 179px;"></p>

<p>위와 같이 회색으로 표시된 단위 도로들을 4 의 비용으로 건설하면 목적을 달성할 수 있다.</p>

<p>도시가 위와 같이 격자 형태로 주어졌을 때 맨 왼쪽 위 단위 격자에서 맨 오른쪽 아래 단위 격자로 가는 경로를 만들기 위해 필요한 최소 도로 건설 비용을 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>입력은 표준입력을 사용한다. 첫 번째 줄에 도시를 표현하는 격자의 행과 열의 크기를 각각 나타내는 두 개의 양의 정수 <em>m</em>, <em>n</em> (1 ≤ <em>m</em>, <em>n</em> ≤ 1,000, 1 < m×n)이 주어진다. 다음 <em>m</em>개의 각 줄에 격자의 각 열의 정보를 나타내는 <em>n</em>개의 숫자가 주어진다. 각 열의 정보는 정수 0, 1, 2, -1 로 나타내며 0 은 단위도로가 이미 존재하는 것을, 즉, 도로에 유실이 없는 상태, 1 은 단위 도로가 없고 1 의 비용으로 도로를 건설할 수 있는 단위 격자, 2 는 단위 도로가 없고 2 의 비용으로 도로를 건설할 수 있는 단위 격자를 의미한다. -1 은 X로 표시된 단위 격자로 그 위치에 단위 도로를 건설할 수 없는 상태를 의미한다.</p>

### 출력 

 <p>출력은 표준출력을 사용한다. 도시의 맨 왼쪽 위 단위 격자에서 맨 오른쪽 아래 단위 격자로 가는 경로를 만들기 위해 필요한 최소한의 도로 건설 비용을 한 줄에 출력한다. 해당 경로를 건설할 수 없을 때는 -1 을 출력한다.</p>

