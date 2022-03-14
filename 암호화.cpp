#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int front_code_number()
{
	int front;
	srand(time(NULL));
	front = rand() % 26 + 1;
	return front;
}
//앞쪽 암호화 조건 수
 
int back_code_number()
{
	int back;
	srand(time(NULL));
	back = rand() % 10 + 1;
	return back;
}
//뒷쪽 암호화 조건 수  

int small_or_big(int front, int back)
{
	if((front + back) %  6== 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
} 
//front, back 암호 대소문자 여부 결정 

int main()
{
	int k = 0;
	int special = 0;
	char password_code_small[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	char password_code_big[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	//평문 문자열  
	
	char password_key_small[26] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm'};
	char password_key_big[26] = {'M', 'N', 'B', 'V', 'C', 'X', 'Z', 'L', 'K', 'J', 'H', 'G', 'F', 'D', 'S', 'A', 'P', 'O', 'I', 'U', 'Y', 'T', 'R', 'E', 'W', 'Q'};
	//암호화 문자열  
	
	int front = front_code_number();
	int back =back_code_number();
	//난수 받기 
	
	int sob = small_or_big(front, back); 
	//sob의 결과에 따라 암호화할 키 값의 소문자 or 대문자 방식 결정

	char plaintext;
	printf("문자 끝에 \";\"를 입력해주십시오. 문장 중간에는 \";\"이 없어야합니다.\n\nplaintext : ");
	//안내  
	
	/*printf("디버깅용 front : %d back : %d\n", front, back);*/
		
	do
	{
		special = 0;
		//툭수문자 여부 결정 값 초기화 
		 
		plaintext = getchar();
		//평문 글자당 받기  
		
		if(k == 0)
		{
			printf("\n\n암호화 결과 : ");
			if(sob == 1)
			{
				printf("%c", password_code_small[front-1]);	
				printf("%c", password_code_big[back+1]);
			}
			else
			{
				printf("%c", password_code_big[front-1]);
				printf("%c", password_code_small[back+1]);
			}	
			k++;
		}
		//front, back 암호화 출력 
		
		for(int i = 0; i<=25; i++)
		{
			if(plaintext == password_code_small[i])
			{	
				if( i - front < 0)
				{
					printf("%c", password_key_big[26 + (i-front)]);
				}
				else
				{
					printf("%c", password_key_big[i-front]);
				} 
				//프론트 
				 
				if( i + back > 25 )
				{
					printf("%c", password_key_big[back - (26 - i)]);
				}
				else
				{
					printf("%c", password_key_big[i+back]);
				}
				//백  
				
				special++;
				//특수문자 여부 결정 값  
			}
			//소문자 입력시 대문자 암호로 변환. 
			
			else if(plaintext == password_code_big[i])
			{	
				if( i - front < 0)
				{
					printf("%c", password_key_small[26 + (i-front)]);
				}
				else
				{
					printf("%c", password_key_small[i-front]);
				} 
				//프론트 
				 
				if( i + back > 25 )
				{
					printf("%c", password_key_small[back - (26 - i)]);
				}
				else
				{
					printf("%c", password_key_small[i+back]);
				}
				//백  
				
				special++;
				//특수문자 여부 결정 값  
			}
			//대문자 입력시 소문자 암호로 변환.  
			
		}
		//평문을 암호로 변환
		
		if(special == 0)
		{
			if(plaintext == ';')
			{
				printf(".");
			}
			else
			{
				printf("%c", plaintext);	
			}
		}
		//특수문자값으로 특수문자 여부 결정 확인 후 출력  
		
	}while (plaintext != ';');
	 
	return 0;
}
