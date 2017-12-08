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
	
	함수 설명 : (d > 0 일때) 전체 길이 n에서 앞에서 부터 d만큼의 문자열을 뒤에서 부터 d만큼의 문자열과 교체하고
				다시 block_swap function에 넣는다.(재귀함수)				
		   (d < 0 일때) 전체 길이 n에서 뒤에서 부터 d만큼의 문자열을 앞에서 부터 d만큼의 문자열과 교체하고
		   		다시 block_swap function에 넣는다.(재귀함수)
				이런식으로 반복을 하면서 d와 n-d가 같을 때까지 반복하면 block_swap이 된다.
2. triv.c
	input : str, d, n
	output : str
3. juggling.c
	input : str, d, n
	output : str
4. block_swap.c
	input : str, n, d
	output : str

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

- block-swap은 문자열을 str Length의 크기와 rotate distance의 크기로 묶고 swap을 하고 다시 재귀하면서
  str Length와 rotate distance가 같아질 때까지 block-swap을 실행하는 것이어서 같은 str Length에서 rotate distance
  의 크기를 str Length/2 와 가깝게 설정하였을 때 처리 속도가 빠를 것을 추론할 수 있다.
  실행 결과, rotate distance가 str Length/2와 값이 비슷할 때 처리 속도가 다른 것에 비해서 가장 빠른 것을 알 수가 있다.

- reverse
- - -
