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
