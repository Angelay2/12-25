#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// ָ����ʷ�ʽ��������ʷ�ʽ���һ��,��Ϊ���ڸ�������������ά,
// ���û��ں����ڲ�ʹ������ʱ,��������������һ��,�չ��û�
// ��Ȼ�ں������ô�ָ���������,�ɱ���,��һ��ָ��һ�������,���׸���
int main1(){
	int a[5] = { 1, 2, 3, 4, 5 };
	int num = sizeof(a) / sizeof(a[0]);
	
	int* p = a;//һ��ָ��pָ��a
	
	int i = 0;
	for (; i < num;i++){
		printf("%d\n", a[i]);
		printf("%d\n", *(a + i));
		//ָ���������Ԫ�ط���������
		printf("%d\n", *(p + i));
		printf("%d\n", p[i]);
	}
	system("pause");
	return 0;

}

// ָ�봫��,ֻҪ���ξ�Ҫ��������,������������,pָ��main������arr
void print(int* p, int sz){
	int i = 0;
	for (i = 0; i < sz;i++){
		printf("%d\n", *(p + i));
	}
}
int main2(){
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int* p = arr;// ������Ԫ�صĵ�ַ
	int sz = sizeof(arr) / sizeof(arr[0]);
	// һ��ָ��p, ��������
	print(p, sz);
	system("pause");
	return 0;
}
// void test1(int* p){} ���Խ��� int* p, int a = 10;&a, int a[10],
// void test2(char* p){} ���Խ��� char* p, char ch = 'a'; &ch, "hello world"
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
	show("hello world!");// ���ֶ����Դ��ַ���.

	char ch = 'a';
	show2(&ch);

	system("pause");
	return 0;
}

// ������������С������
// ��С��������ָ�ܱ� A �� B ��������С��������ֵ
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

// �����ַ���
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
//	// ���ﲻ����scanf, scanfһ�����ո�,���ݽ��վͽ�����
//	gets(input);
//	// ��ת��������
//	reverse(input, input + strlen(input) - 1);
//	// ��ת����
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

// �����ַ���
int main5(){
	char str1[] = "Welcome to China !";
	char str2[] = "##################";
	int left = 0;
	int right = strlen(str2) - 1;
	while (left <= right){
		str2[left] = str1[right];
		str2[right] = str1[left];
		system("cls"); // ��������
		printf("%s\n", str2);
		left++;
		right--;
		Sleep(250);
		//��λΪms,Sleep()Ϊ����ϵͳ����,Linux/Macϵͳ��,Sleep��λΪs
	}
	system("pause");
	return 0;
}

// ����ָ�봫��
// �������Ĳ���Ϊ����ָ��(char** p)��ʱ��, ���Խ�������:
// 1. ����ָ��
// 2. һ��ָ��ȡ��ַ (*p &p)   &&ch ����
// 3. char * p[10] (һά������10��,ÿ��Ԫ��Ϊ char* ,��άΪ char** )

void test(int** ptr){
	printf("num = %d\n", **ptr);
}
int main7(){
	int n = 2;
	int* p = &n;
	int** pp = &p;
	test(pp);//pp Ϊ����ָ����� ����ָ����Խ��� ��� num = 10
	test(&p);//&p ����ȥ����p�ĵ�ַ(pΪһ��ָ��)���Խ��� ��� num = 10,
	system("pause");
	return 0;
}

// ����ָ��
void test1(){
	
	printf("hehe\n");
}
int main(){
	printf("%p\n", test1);
	printf("%p\n", &test1);// ���ֵȼ� ��ͬ��� ��������ĵ�ַ

	system("pause");
	return 0;
}
