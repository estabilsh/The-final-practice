#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

#ifndef _A					//防止报错：redefinition of 'struct student'
#define _A
struct student				 
{
	char name[10],sub[10];		//sub科目
	double score;
	int num;					//学号 
	struct student *next;
};

const char PASS[]="abc"; 		//预设的密码 
const int CHANCE=3;				//最大尝试次数 

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
