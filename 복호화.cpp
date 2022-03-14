#include <stdio.h>
#include <stdlib.h>
int main()
{
	int k = 0;
	int special = 0;
	int point = 0;
	int h = 0;
	int p = 0;
	char password_code_small[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	char password_code_big[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	//평문 문자열  
	
	char password_key_small[26] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'z', 'x', 'c', 'v', 'b', 'n', 'm'};
	char password_key_big[26] = {'M', 'N', 'B', 'V', 'C', 'X', 'Z', 'L', 'K', 'J', 'H', 'G', 'F', 'D', 'S', 'A', 'P', 'O', 'I', 'U', 'Y', 'T', 'R', 'E', 'W', 'Q'};
	//암호화 문자열  
	
	int front = 0;
	//공유키 
	 
	int codetext;
	printf("암호문을 입력후, 문자 끝에 \";\"를 입력해주십시오.\n\n암호문 : ");
	
	do
	{
		special = 0;
		p = 0;
		
		codetext = getchar();
		
		if(point == 0) //point가 0일 시  
		{
			if(k == 0)
			{
				for(int j = 0; j<=25; j++)
				{
					if(codetext == password_code_small[j])
					{
						front = j+1;
						break;
					}
					else if(codetext == password_code_big[j])
					{
						front = j+1;
						
						break;
					}
				}
				k++;
				point++;
				//첫 번째 front공유 키값 받기. 
				
				printf("\n\n복호화 결과 : ");
				/*printf("디버깅프론트 값 : %d\n", front);*/
			}
			//일회용
			 
			else
			{
				for(int i = 0; i<=25; i++)
				{
					if(codetext == password_key_big[i]) 
					{
						if(i+front>25)
						{
							printf("%c", password_code_small[front - (26 - i)]);
						}
						else
						{
							printf("%c", password_code_small[front+i]);
						}
						special++;
					}
					//특수 대문자 입력시. 일반 소문자로 복호 
					 
					else if(codetext == password_key_small[i])
					{
						if(i+front>25)
						{
							printf("%c", password_code_big[front - (26 - i)]);
						}
						else
						{
							printf("%c", password_code_big[front+i]);
						}
						special++;
					}
					//특수 소문자 입력시. 일반 대문자로 복호  
				}
				if(special == 0)
				{
					if(codetext == ';')
					{
						printf(".");
					}
					else
					{
						printf("%c", codetext);		
					}
					continue;
				}
				point++;
				//실질적 복호화. 
			}
		}
		
		else//point가 1일이고, 숫자 혹은 특수기호가 아닐경우. 
		{
			for(h = 0; h<=25; h++)
			{
				if(codetext == password_key_big[h])
				{
					point--;
					p++;
					break;
				}
				else if(codetext == password_key_small[h])
				{
					point--;
					p++;
					break;
				}
			}
			if(p == 0)
			{
				if(codetext == ';')
				{
					printf(".");
				}
				else
				{
					printf("%c", codetext);
				}
				point--;
			}
		}
	}while (codetext != ';');
	
	return 0; 
}
