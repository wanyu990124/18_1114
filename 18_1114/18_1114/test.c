#include <stdio.h>
int fun(char *s)
{
	char t[80];
	int i, j;
	for (i = 0; s[i]; i++)  /*����s��������t*/
		t[i] = s[i];
	t[i] = '\0';
	for (i = 0, j = 0; t[i]; i++)
		/*���������ַ���дһ��$���ţ���д�������ַ�*/
		if (t[i] >= '0' && t[i] <= '9')
		{
		s[j++] = '$';
		s[j++] = t[i];
		}
	/*���ڷ������ַ�ԭ��д�봮s*/
		else
			s[j++] = t[i];
	s[j] = '\0';  /*�ڴ�s��β�ӽ�����־*/
	return 0;
}
int main()
{
	char s[80];
	printf("Enter a string:");
	scanf("%s", s);  /*�����ַ���*/
	fun(s);
	printf("The result: %s\n", s);  /*������*/
	return 0;
}

//24����Ϸ
#include<stdio.h>
char op[5] = { '#', '+', '-', '*', '/', };
float cal(float x, float y, int op)
{
	switch (op)
	{
	case 1: return x + y;
	case 2: return x - y;
	case 3: return x*y;
	case 4: return x / y;
	default: return 0.0;
	}
}

float calculate_model1(float i, float j, float k, float t, int op1, int op2, int op3)
{
	float r1, r2, r3;
	r1 = cal(i, j, op1);
	r2 = cal(r1, k, op2);
	r3 = cal(r2, t, op3);
	return r3;
}

float calculate_model2(float i, float j, float k, float t, int op1, int op2, int op3)
{
	float r1, r2, r3;
	r1 = cal(j, k, op2);
	r2 = cal(i, r1, op1);
	r3 = cal(r2, t, op3);
	return r3;
}

float calculate_model3(float i, float j, float k, float t, int op1, int op2, int op3)
{
	float r1, r2, r3;
	r1 = cal(k, t, op3);
	r2 = cal(j, r1, op2);
	r3 = cal(i, r2, op1);
	return r3;
}

float calculate_model4(float i, float j, float k, float t, int op1, int op2, int op3)
{
	float r1, r2, r3;
	r1 = cal(j, k, op2);
	r2 = cal(r1, t, op3);
	r3 = cal(i, r2, op1);
	return r3;
}

float calculate_model5(float i, float j, float k, float t, int op1, int op2, int op3)
{
	float r1, r2, r3;
	r1 = cal(i, j, op1);
	r2 = cal(k, t, op3);
	r3 = cal(r1, r2, op2);
	return r3;
}

int get24(int i, int j, int k, int t)
{
	int op1, op2, op3;
	int flag = 0;
	for (op1 = 1; op1 <= 4; op1++)
		for (op2 = 1; op2 <= 4; op2++)
			for (op3 = 1; op3 <= 4; op3++)
			{
		if (calculate_model1(i, j, k, t, op1, op2, op3) == 24)
		{
			printf("((%d%c%d)%c%d)%c%d=24\n", i, op[op1], j, op[op2], k, op[op3], t);
			flag = 1;
		}
		if (calculate_model2(i, j, k, t, op1, op2, op3) == 24)
		{
			printf("(%d%c(%d%c%d))%c%d=24\n", i, op[op1], j, op[op2], k, op[op3], t);
			flag = 1;
		}
		if (calculate_model3(i, j, k, t, op1, op2, op3) == 24)
		{
			printf("%d%c(%d%c(%d%c%d))=24\n", i, op[op1], j, op[op2], k, op[op3], t);
			flag = 1;
		}
		if (calculate_model4(i, j, k, t, op1, op2, op3) == 24)
		{
			printf("%d%c((%d%c%d)%c%d)=24\n", i, op[op1], j, op[op2], k, op[op3], t);
			flag = 1;
		}
		if (calculate_model5(i, j, k, t, op1, op2, op3) == 24)
		{
			printf("(%d%c%d)%c(%d%c%d)=24\n", i, op[op1], j, op[op2], k, op[op3], t);
			flag = 1;
		}
			}
	return flag;
}

int main()
{
	int i, j, k, t;
	printf("Please input four integer (1~10)\n");
loop:    scanf("%d %d %d %d", &i, &j, &k, &t);
	if (i<1 || i>10 || j<1 || j>10 || k<1 || k>10 || t<1 || t>10)
	{
		printf("Input illege, Please input again\n");
		goto loop;
	}
	if (get24(i, j, k, t));
	else
		printf("Sorry, the four integer cannot be calculated to get 24\n");
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	char gamer;  // ��ҳ�ȭ
	int computer;  // ���Գ�ȭ
	int result;  // �������

	// Ϊ�˱�����һ����Ϸ���˳����򣬿��Խ��������ѭ����
	while (1){
		printf("����һ����ȭ��С��Ϸ����������Ҫ����ȭͷ��\n");
		printf("A:����\nB:ʯͷ\nC:��\nD:������\n");
		scanf("%c%*c", &gamer);
		switch (gamer){
		case 65:  //A
		case 97:  //a
			gamer = 4;
			break;
		case 66:  //B
		case 98:  //b
			gamer = 7;
			break;
		case 67:  //C
		case 99:  //c
			gamer = 10;
			break;
		case 68:  //D
		case 100:  //d
			return 0;

		default:
			printf("���ѡ��Ϊ %c ѡ�����,�˳�...\n", gamer);
			getchar();
			system("cls"); // ����
			return 0;
			break;
		}

		srand((unsigned)time(NULL));  // ���������
		computer = rand() % 3;  // �����������ȡ�࣬�õ����Գ�ȭ
		result = (int)gamer + computer;  // gamer Ϊ char ���ͣ���ѧ����ʱҪǿ��ת������
		printf("���Գ���");
		switch (computer)
		{
		case 0:printf("����\n"); break; //4    1
		case 1:printf("ʯͷ\n"); break; //7  2
		case 2:printf("��\n"); break;   //10 3
		}
		printf("�����");
		switch (gamer)
		{
		case 4:printf("����\n"); break;
		case 7:printf("ʯͷ\n"); break;
		case 10:printf("��\n"); break;
		}
		if (result == 6 || result == 7 || result == 11) printf("��Ӯ��!");
		else if (result == 5 || result == 9 || result == 10) printf("����Ӯ��!");
		else printf("ƽ��");
		system("pause>nul&&cls");  // ��ͣ������
	}
	return 0;
}