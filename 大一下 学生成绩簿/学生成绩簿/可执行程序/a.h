#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

#ifndef _A					//��ֹ����redefinition of 'struct student'
#define _A
struct student				 
{
	char name[10],sub[10];		//sub��Ŀ
	double score;
	int num;					//ѧ�� 
	struct student *next;
};

const char PASS[]="abc"; 		//Ԥ������� 
const int CHANCE=3;				//����Դ��� 

#endif



void Password();
void menu();
struct student *read(struct student *begin);
void print(struct student *begin);
void search_r(struct student *begin);
struct student *add(struct student *begin);
struct student *amend(struct student *begin);
struct student *delect(struct student *begin);
void seg(struct student *begin);
