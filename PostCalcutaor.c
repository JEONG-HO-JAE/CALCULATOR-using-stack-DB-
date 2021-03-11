#include "PostCalculator.h"
#include "Stack.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int EvalRPNExp(char exp[]) {
	Stack stack;

	int length = strlen(exp);

	char tok;


	//와 이거 안적은 거 찾아냄 와 개쩐다
	StackInit(&stack);


	for (int i = 0; i < length; i++) {

		tok = exp[i];
		int result;

	

		//문자열이 만약 숫자라면 stack에 집어 넣기
		if (isdigit(tok)) 
			SPush(&stack, tok-'0');


		// 연산자일때 아래가 실행되고 무조건 스택에는 두개의 스택데이터가 쌓여 있다
		else {

			//숫자 두개 추출
			
			int back = SPop(&stack);
			int front = SPop(&stack);
			

			//연산
			switch (tok) {
			case '*':
				result = front * back;
				break;
			case '/':
				result = front / back;
				break;
			case '+':
				result = front + back;
				break;
			case '-':
				result = front - back;
				break;
			}
			//연산 완료후 stack 집어 넣기
			SPush(&stack, result);
		}
	}

	return SPop(&stack);
	
}
