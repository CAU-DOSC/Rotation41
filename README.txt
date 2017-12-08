# README file for TEAM[4,1]:

This text file describes brief but precise and complete specification of project including:
- funtion descriptions: name, input/output parameters
- declaration of of important data and data types to be included in user header file
- your team's brief ideas of implementions

- - -
Your description start form next line and do not delete lines upto this point

- - -

>>Ownership

노제원 : README.txt , juggling.c
범동권 : main.c , block_swap.c
금아현 : header.h , reverse.c
이승연 : trivial.c

- - -

>>Function description

d > 0 일 때 clockwise rotation
d < 0 일 때 counterclockwise rotation

1. reverse.c
	input : str, n, d
	output : str
		
        함수 설명 : 문자열을 reverse 시키는 reverse 함수가 있고, 이 함수를 세 번 호출하는 함수 reversal이 있다. 
                   reverse 함수에서는 문자열, reverse할 구간의 처음과 끝을 입력받아 reverse 한다. 
                   reversal 함수에서는 d>0일 때와 d<0일때로 나누어서 
		   d>0일 때는 reverse(str, 0, d -1);, reverse(str, d, n - 1);, reverse(str, 0, n - 1); 로 호출하고
		   d<0일 때는 d를 -d 로 바꿔서 양수로 만들어 준 후, 
		   reverse(str, n-d, n-1);, reverse(str, 0, n-d-1);, reverse(str, 0, n-1); 로 세번 호출한다.
2. triv.c
	input : str, d, n
	output : str
3. juggling.c
	input : str, d, n
	output : str
4. block_swap.c
	input : str, n, d
	output : str
	
	함수 설명 : (d > 0 일때) 전체 길이 n에서 앞에서 부터 d만큼의 문자열을 뒤에서 부터 d만큼의 문자열과 교체하고
				다시 block_swap function에 넣는다.(재귀함수)				
		   (d < 0 일때) 전체 길이 n에서 뒤에서 부터 d만큼의 문자열을 앞에서 부터 d만큼의 문자열과 교체하고
		   		다시 block_swap function에 넣는다.(재귀함수)
				이런식으로 반복을 하면서 d와 n-d가 같을 때까지 반복하면 block_swap이 된다.

- - -

>>Declaration of important data and data types in user header file
 - name : header.h
 - used header file : <stdio.h> <stdlib.h> <string.h> <time.h>
 - data form : array
 - used function : reverse.c, triv.c, juggling.c, block-swap.c

- - -

>> Test Results

[STRLength]  	ROTATE distance  	T.trivial	T.juggle	T.bw	 	T.reverse
10		4			0.000000	0.000000	0.000000 	0.000000
100		50			0.000000	0.000000	0.000000	0.000000
1000		333			0.001000	0.000000	0.000000	0.000000
5000		345			0.006000	0.000000	0.000000	0.000000
10000		2384			0.072000	0.000000	0.000000	0.000000
50000		5948			0.824000	0.005000	0.003000	0.004000
100000		500			0.242000	0.001000	0.001000	0.001000
500000		10000			24.174000	0.003000	0.002000	0.002000
500000		250000			610.849000	0.003000	0.002000	0.002000
1000000		50000			262.648000	0.008000	0.005000	0.005000
1000000		500000			2542.510000	0.006000	0.002000	0.006000
5000000		100000			2506.528000	0.036000	0.022000	0.026000



추론

결과를 보면 시간이 오래걸리는 순은

trivial > juggle > block-swap ≒ reverse 이라는 것을 알 수 있다.

- trivial

- juggle
  저글링 스왑은 n과 d의 최대공약수만큼 i(=0) loop를 반복하며, { ( 현재 배열 + d) / n } 이 i 와 다를 동안 현재 배열의 데이터에 { ( 현재 배열 + d)   / n }번째의 데이터를 복사하고 복사한 데이터의 위치로 이동하는 과정을 반복한다. 예를 들어 n = 6, d = 3일 때는  [0]에 [3]의 데이터, [3]에 [0]의   데이터, [1]에 [4]의 데이터, [4]에 [1]의 데이터, [2]에 [5]의 데이터, [5]에 [2]의 데이터가 들어가는 방식이며, n = 7, d = 3일 때는 [0]에 [3],     [3]에 [6], [6]에 [2], [2]에 [5], [5]에 [1], [1]에 [4], [4]에 [0]의 데이터가 들어가는 방식이다.
  
- block-swap은 문자열을 str Length의 크기와 rotate distance의 크기로 묶고 swap을 하고 다시 재귀하면서
  str Length와 rotate distance가 같아질 때까지 block-swap을 실행하는 것이어서 같은 str Length에서 rotate distance
  의 크기를 str Length/2 와 가깝게 설정하였을 때 처리 속도가 빠를 것을 추론할 수 있다.
  실행 결과, rotate distance가 str Length/2와 값이 비슷할 때 처리 속도가 다른 것에 비해서 가장 빠른 것을 알 수가 있다.

- reverse는 총 세 번에 걸쳐 이루어진다. reverse(str, 0, d - 1);에서는 첫 번째부터 d번째까지, 
  reverse(str, d, n - 1);에서는 그 뒤부터 마지막까지, reverse(str, 0, n-1);에서는 처음부터 끝까지 reverse 한다. 
  따라서 각각 d/2번, n-d/2번, n/2번의 연산이 이루어지므로 총 d/2 + n-d/2 + n/2 = n번의 연산이 이루어진다. 
  이를 통해 reverse에 걸리는 시간은 d값과 관련이 없다는 것을 알 수 있다. 
- - -
