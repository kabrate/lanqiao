#include <cstdio>
#include <cstring>


void StringInGrid(int width, int height, const char* s)//ˮƽ���� ��ֱ���� �ַ���
{
	int i, k;
	char buf[1000];//buf�����ַ���
	strcpy_s(buf, s);
	if (strlen(s)>width - 2) buf[width - 2] = 0;

	printf("+");
	for (i = 0; i<width - 2; i++) printf("-");
	printf("+\n");

	for (k = 1; k<(height - 1) / 2; k++) {
		printf("|");
		for (i = 0; i<width - 2; i++) printf(" ");
		printf("|\n");
	}

	printf("|");

	printf("%*s%s%*s", (width - strlen(buf) - 2) / 2, " ", buf, width-(width - strlen(buf) - 2) / 2 + (width - strlen(buf) - 2) % 2, " "); 
	//��գ�ʹ�ո� ���ֱ�ռ�ݿ�Ϊ(width-strlen(buf)-2)/2��(width-strlen(buf)-2)/2+(width-strlen(buf)-2)%2�Ŀռ����Ҷ��룩  

	printf("|\n");

	for (k = (height - 1) / 2 + 1; k<height - 1; k++) {
		printf("|");
		for (i = 0; i<width - 2; i++) printf(" ");
		printf("|\n");
	}

	printf("+");
	for (i = 0; i<width - 2; i++) printf("-");
	printf("+\n");
}


int main()
{
	StringInGrid(20, 6, "abcd1234");
	return 0;
}
