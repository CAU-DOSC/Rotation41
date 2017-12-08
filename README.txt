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
	
	함수 설명 : 문자열 포인터와 n, d를 인수로 넘겨 받는다. d가 음수일 경우와 양수일 경우로 분류한다. d가 음수일 경우 문자열의 첫 번째 value를
		 temp에 임시 저장하고, d칸 간격으로 문자열을 이동시킨 뒤 마지막으로 마지막 value에 temp를 저장한다. 이를 d와 n의 최대공약수 만큼 
		 반복한다. d가 양수일 경우 value를 temp에 임시 저장하고, d칸 간격으로 문자열을 이동시킨 뒤 마지막으로 첫번째 value에 temp를 저장
		 한다. 이 과정 또한 d와 n의 최대공약수 만큼 반복한다.
	
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
  juggling은 적어도 trivial 알고리즘의 계산량에서 Rotate 횟수인 d로 나눈 만큼(즉, N만큼)의 계산을 수행해야 한다. 하지만 N과 d의 GCD(최대공약수)
  가 1이면, 그 계산량이 1이 아닐 때 보다 증가하므로 계산량이 N보다 커질 수 있다. 따라서 juggle 알고리즘은 "적어도 N만큼"의 계산량을 수행하므로 실
  행 시간을 t라하면, 그 시간은 t>=N/170000000초 정도로 추론할 수 있다.
  
- block-swap은 문자열을 str Length의 크기와 rotate distance의 크기로 묶고 swap을 하고 다시 재귀하면서
  str Length와 rotate distance가 같아질 때까지 block-swap을 실행하는 것이어서 같은 str Length에서 rotate distance
  의 크기를 str Length/2 와 가깝게 설정하였을 때 처리 속도가 빠를 것을 추론할 수 있다.
  실행 결과, rotate distance가 str Length/2와 값이 비슷할 때 처리 속도가 다른 것에 비해서 가장 빠른 것을 알 수가 있다.

- reverse는 총 세 번에 걸쳐 이루어진다. reverse(str, 0, d - 1);에서는 첫 번째부터 d번째까지, 
  reverse(str, d, n - 1);에서는 그 뒤부터 마지막까지, reverse(str, 0, n-1);에서는 처음부터 끝까지 reverse 한다. 
  따라서 각각 d/2번, n-d/2번, n/2번의 연산이 이루어지므로 총 d/2 + n-d/2 + n/2 = n번의 연산이 이루어진다. 
  이를 통해 reverse에 걸리는 시간은 d값과 관련이 없다는 것을 알 수 있다. 
- - -
