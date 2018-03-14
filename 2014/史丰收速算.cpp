#include<iostream>
#include<cstdio>
#include<cstring>
//�����λ 
int ge_wei(int a)
{
	if(a % 2 == 0)
	return (a * 2) % 10;
	else
	return (a * 2 + 5) % 10;
}


//�����λ 
int jin_wei(char* p)
{
	char* level[] = 
	{
	"142857",
	"285714",
	"428571",
	"571428",
	"714285",
	"857142"
	};	
	char buf[7];
	buf[6] = '\0';
	strncpy(buf,p,6);//��p��ǰ6��Ԫ�ظ��Ƶ�buf�� 
	int i;
	for(i=5; i>=0; i--)
	{
		int r = strcmp(level[i], buf);//buf����level�еĶ�Ӧֵ 
		if(r<0) return i+1;//�Ӵ�С  �ȽϽ�λ 
		while(r==0)//���ô����ٽ紦 
		{
			p += 6;
			strncpy(buf,p,6);
			r = strcmp(level[i], buf);
			if(r<0) return i+1;//����6λ��λ 
			if(r>0)return i;  //���
		}
	}

return 0;
}

//��λ������7
void f(char* s) 
{
	int head = jin_wei(s);
	if(head > 0) printf("%d", head);
	char* p = s;
	while(*p)
	{
		int a = (*p-'0');
		int x = (ge_wei(a) + jin_wei(p+1)) % 10;
		printf("%d",x);
		p++;
	}
	
	printf("\n");
}


int main()
{
	f("142857142857");
	f("34553834937543");
	return 0;
}

