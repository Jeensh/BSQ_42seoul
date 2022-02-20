# BSQ_42seoul
지도에서 장애물을 피해 만들 수 있는 가장 큰 사각형을 만들어 출력하기

다이나믹 프로그래밍

- 테이블을 만들어 문제를 푸는 프로그래밍 방식


다이나믹 프로그래밍의 조건 3가지

- 문제가 더 작은 서브 문제로 쪼개질 때
- 작은 서브 문제들의 솔루션으로 더 큰 문제의 솔루션을 구할 수 있을 때
- 이러한 서브 문제들이 곂칠 때
---

### 문제 조건들

- 제출해야 하는 파일 목록
	- Makefile, 모든 필요한 파일들
- 인자
	- square을 돌릴 맵 파일들
- 사용 가능한 함수
	- open
	- close
	- read
	- write
	- malloc
	- free
	- exit
- 사용가능한 라이브러리
	- 없음


### 문제

- 주어진 영역 안에서 만들 수 있는 가장 큰 사각형을 그리고 프린트하는 프로그램 만들기


### 플로우

- 지도가 들어있는 파일을 받게됨 -> 이 지도가 프로그램에 대한 인자로 전달 되어야 함
- 지도의 첫 번째 행에는 지도를 읽는 방법에 대한 다음과 같은 정보가 나와 있음
	- 지도에 있는 줄 수
	- '빈' 문자
	- '장애물' 문자
	- ' 차 있는' 문자
	  
- 유효한 지도의 정의
  	- <img src="https://user-images.githubusercontent.com/78855847/154825456-57136b40-1ae3-4fe2-81ae-c7d13f2cf7fc.png" width="500" height="400">
	- 모든 행의 길이가 같아야 함
	- 최소 한 개의 상자에 최소한 한 개의 행이 있어야 함
	- 행의 양쪽 끝에는 각각 줄바꿈이 있어야 함
	- 지도의 문자는 첫 번째 행에서 등장한 문자만 나올 수 있음
	- 첫 번째 행에 어떤 문자가 없거나 두 개의 문자(빈 문자, 차 있는 문자, 장애물 문자)가 동일한 경우 지도는 유효하지 않음
	- 출력 가능한 모든 문자가 문자가 될 수 있음, 숫자도 가능
	- 지도가 유효하지 않은 경우, 프로그램은 오류 출력값에 지도 오류를 표시하고 줄 바꿈이 되어야 함
	- 그런 다음 프로그램은 다음 지도로 넘어감


### 지도 생성기
- <img src="https://user-images.githubusercontent.com/78855847/154825459-eec9b710-bc03-4dd8-9ab0-94c741f8682b.png" width="500" height="400">


---

## 설계



### 필요 파일

- 프로그램 생성기 - 완성
	- 파일명 : map_maker.pl
	- perl map_maker.pl 10 10 2 > map1 과 같이 쉘에 명령하면 파일이 만들어짐
		- 첫 번째 인자 : 가로 길이
		- 두 번째 인자 : 세로 길이
		- 세 번째 인자 : 장애물 비율
		- map1 : 만들어질 파일 이름
- main 파일
	- main 함수만 존재
- 헤더파일
	- 메인을 제외한 모든 함수 및 라이브러리를 담고 있어야 함
- Makefile


### 필요 함수 
- 지도 파일 열기 함수
	- 메인 함수에 문자열 인자로 지도의 이름이 들어옴
		- 여러개도 처리할 수 있어야 함
	- 문자열 인자가 없을 경우 표준 입력으로 지도의 이름을 받음
- 지도 유효 확인 함수
	- 필요 기능
		- 첫 행 인자 확인
		- 최소 행 개수 확인
		- 모든 행 길이 확인
		- 행의 끝에 줄바꿈 확인
		- 지도의 각 문자 확인 -> 첫 행의 규칙을 따르는지
		- 지도 유효하지 않을 시 -> 오류 출력 값에 지도 오류를 표시하고 줄바꿈 해야 함 그 후 다음 지도로 넘어감
			- ->  메인쪽에서 기능 구현할 듯
- 문제 풀이 함수
	- 원래 지도를 보고 숫자 행렬을 만드는 함수
		- 숫자 행렬의 각 요소는 자기가 우측 하단 꼭짓점일때 만들어 질 수 있는 정사각형 한 변의 크기를 담고 있음
		- 알고리즘
			- 모든 인덱스를 참조
				- 1행과 1열의 수는 1로 초기화
				- 장애물은 0으로 할당
				- 해당 인덱스의 왼쪽, 왼쪽 대각선, 위쪽의 인덱스 값 중 가장 작은 값 + 1을 할당
	- 숫자 행렬을 보고 가장 큰 숫자를 찾는 함수
	- 숫자 행렬의 가장 큰 숫자로 만들어지는 사각형을 원래 지도에 그림
		- 가장 큰 숫자 행렬의 인덱스부터 시작해 왼쪽으로 해당 숫자만큼 차있는 문자로 치환
		- 해당 숫자만큼 위쪽 행으로 올라가면서 위의 과정 반복
- 지도 출력 함수
	- 행렬을 출력하는 느낌으로 하면 될듯
- open 한 지도 파일 닫기 함수
	- close 이용
