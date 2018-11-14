#include <stdio.h>
int fun(char *s)
{
	char t[80];
	int i, j;
	for (i = 0; s[i]; i++)  /*将串s拷贝至串t*/
		t[i] = s[i];
	t[i] = '\0';
	for (i = 0, j = 0; t[i]; i++)
		/*对于数字字符先写一个$符号，再写该数字字符*/
		if (t[i] >= '0' && t[i] <= '9')
		{
		s[j++] = '$';
		s[j++] = t[i];
		}
	/*对于非数字字符原样写入串s*/
		else
			s[j++] = t[i];
	s[j] = '\0';  /*在串s结尾加结束标志*/
	return 0;
}
int main()
{
	char s[80];
	printf("Enter a string:");
	scanf("%s", s);  /*输入字符串*/
	fun(s);
	printf("The result: %s\n", s);  /*输出结果*/
	return 0;
}

//24点游戏
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
	char gamer;  // 玩家出拳
	int computer;  // 电脑出拳
	int result;  // 比赛结果

	// 为了避免玩一次游戏就退出程序，可以将代码放在循环中
	while (1){
		printf("这是一个猜拳的小游戏，请输入你要出的拳头：\n");
		printf("A:剪刀\nB:石头\nC:布\nD:不玩了\n");
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
			printf("你的选择为 %c 选择错误,退出...\n", gamer);
			getchar();
			system("cls"); // 清屏
			return 0;
			break;
		}

		srand((unsigned)time(NULL));  // 随机数种子
		computer = rand() % 3;  // 产生随机数并取余，得到电脑出拳
		result = (int)gamer + computer;  // gamer 为 char 类型，数学运算时要强制转换类型
		printf("电脑出了");
		switch (computer)
		{
		case 0:printf("剪刀\n"); break; //4    1
		case 1:printf("石头\n"); break; //7  2
		case 2:printf("布\n"); break;   //10 3
		}
		printf("你出了");
		switch (gamer)
		{
		case 4:printf("剪刀\n"); break;
		case 7:printf("石头\n"); break;
		case 10:printf("布\n"); break;
		}
		if (result == 6 || result == 7 || result == 11) printf("你赢了!");
		else if (result == 5 || result == 9 || result == 10) printf("电脑赢了!");
		else printf("平手");
		system("pause>nul&&cls");  // 暂停并清屏
	}
	return 0;
}