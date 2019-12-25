#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// 指针访问方式和数组访问方式变成一样,是为了掩盖曾经发生过降维,
// 让用户在函数内部使用数组时,依旧像在用数组一样,照顾用户
// 不然在函数内用纯指针访问数组,成本大,且一会指针一会儿数组,容易搞晕
int main1(){
	int a[5] = { 1, 2, 3, 4, 5 };
	int num = sizeof(a) / sizeof(a[0]);
	
	int* p = a;//一个指针p指向a
	
	int i = 0;
	for (; i < num;i++){
		printf("%d\n", a[i]);
		printf("%d\n", *(a + i));
		//指针和数组在元素访问上相似
		printf("%d\n", *(p + i));
		printf("%d\n", p[i]);
	}
	system("pause");
	return 0;

}

// 指针传参,只要传参就要发生拷贝,拷贝的是内容,p指向main函数的arr
void print(int* p, int sz){
	int i = 0;
	for (i = 0; i < sz;i++){
		printf("%d\n", *(p + i));
	}
}
int main2(){
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int* p = arr;// 数组首元素的地址
	int sz = sizeof(arr) / sizeof(arr[0]);
	// 一级指针p, 传给函数
	print(p, sz);
	system("pause");
	return 0;
}
// void test1(int* p){} 可以接收 int* p, int a = 10;&a, int a[10],
// void test2(char* p){} 可以接收 char* p, char ch = 'a'; &ch, "hello world"
void show(char* p){
	printf("%s\n", p);
}
void show2(char* p){
	printf("%c\n", *p);
}
int main3(){

	//char arr[] = { "hello world!" };
	//char *p = arr;
	//show(p);
	show("hello world!");// 两种都可以传字符串.

	char ch = 'a';
	show2(&ch);

	system("pause");
	return 0;
}

// 求两个数的最小公倍数
// 最小公倍数是指能被 A 和 B 整除的最小的正整数值
int main4(){
	int A,B ;
	scanf("%d %d", &A, &B);
	
	int i = 1;
	while(((A * i) % B ) != 0){
		i++;
	}
	printf("%d\n", A * i);
	system("pause");
	return 0;
}

// 倒置字符串
//void reverse(char* start, char* end){
//	while(start < end){
//		char tmp = *start;
//		*start = *end;
//		*end = tmp;
//
//		start++;
//		end--;
//	}
//}
//int main(){
//	char input[100];
//	// 这里不能用scanf, scanf一遇到空格,数据接收就结束了
//	gets(input);
//	// 翻转整个句子
//	reverse(input, input + strlen(input) - 1);
//	// 翻转单词
//	char* start = input;
//	while(*start){
//		char* end = start;
//		while (*end != ' ' && *end){
//			end++;
//		}
//			reverse(start, end - 1);
//		
//			if (*end){
//				start = end + 1;
//			}
//			else{
//				start = end;
//			}
//			printf("%c\n", input);
//		}
//
//	system("pause");
//	return 0;
//}

// 倒置字符串
int main5(){
	char str1[] = "Welcome to China !";
	char str2[] = "##################";
	int left = 0;
	int right = strlen(str2) - 1;
	while (left <= right){
		str2[left] = str1[right];
		str2[right] = str1[left];
		system("cls"); // 清屏操作
		printf("%s\n", str2);
		left++;
		right--;
		Sleep(250);
		//单位为ms,Sleep()为操作系统函数,Linux/Mac系统上,Sleep单位为s
	}
	system("pause");
	return 0;
}

// 二级指针传参
// 当函数的参数为二级指针(char** p)的时候, 可以接收以下:
// 1. 二级指针
// 2. 一级指针取地址 (*p &p)   &&ch 不行
// 3. char * p[10] (一维数组里10个,每个元素为 char* ,降维为 char** )

void test(int** ptr){
	printf("num = %d\n", **ptr);
}
int main7(){
	int n = 2;
	int* p = &n;
	int** pp = &p;
	test(pp);//pp 为二级指针变量 二级指针可以接收 输出 num = 10
	test(&p);//&p 传进去的是p的地址(p为一级指针)可以接收 输出 num = 10,
	system("pause");
	return 0;
}

// 函数指针
void test1(){
	
	printf("hehe\n");
}
int main(){
	printf("%p\n", test1);
	printf("%p\n", &test1);// 两种等价 相同结果 输出函数的地址

	system("pause");
	return 0;
}
