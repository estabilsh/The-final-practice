#include"a.h"

/**********************************************************
Function:Password
Description：输入并检验密码正确性 
Calls：无 
Called By: main() 
parameter：  pass 输入密码	,a ,d 
Return:无 
**********************************************************/
void Password()
{
	
	char pass[10];													//保存用户输入的密码 
	printf("		学生成绩簿		\n\n\n");
	printf("已设置密码，请输入             (abc)\n");
	
	for(int a=0;a<CHANCE;a++)
	{	
		int d=11;
		scanf("%s",&pass);											//输入密码 
		d=strcmp(PASS,pass);										//用户输入与预设代码比对 
		if(d==0)
		{
			break;           										//密码正确 
		}
		if(a==2)
		{
			printf("错误次数超过上限"); 
			exit(1);  												//密码尝试次数超过上限，错误退出 
		}
		printf("密码错误，你还剩%d次机会",CHANCE-a-1);
		printf("请输入"); 
	}																//end of for(int a=0;a<CHANCE;a++) 
	printf("密码正确\n\n"); 
	printf("文件中已输入的成绩\n"); 
	
 } 
/**********************************************************
Function:menu
Description： 菜单显示 
Calls：无 
Called By: main 
parameter：无 
Return:无 
**********************************************************/
void menu()
{
	printf("==============================================================\n");
	printf("                            菜单界面\n");
	printf("                        0.查询学生成绩\n");
	printf("                        1.增加新学生成绩\n");
	printf("                        2.修改学生成绩\n");
	printf("                        3.删除学生成绩\n");
	printf("                        4.分段显示所有学生成绩\n");
	printf("                        5.退出\n");
	printf("==============================================================\n");
}
/**********************************************************
Function:read
Description： 从文件中读取数据并按学号顺序写入链表，更新文件 
Calls：无 
Called By:main 
parameter:begin , *p ,*end, *fp, *p9 ,*p10 ,*fp1 
Return:*begin 链表头 
Others: 
**********************************************************/
struct student *read(struct student *begin)
{
	struct student *p,*end;

	begin=(struct student*)malloc(sizeof(struct student));
	end=begin;
	
	FILE *fp;
	if((fp=fopen("1.txt","r"))==NULL)
	{
		printf("文件打开错误");
		exit(1); 
	}
	
	p=(struct student*)malloc(sizeof(struct student));
	end->next=p;
	end=p;
	p->next=NULL;
	fscanf(fp,"%d %s %s %lf",&p->num,&p->name,&p->sub,&p->score);//第一项 
	
	

	while(!feof(fp))//正式开始输入 
	{
	
		p=(struct student*)malloc(sizeof(struct student));
	
		fscanf(fp,"%d %s %s %lf\n",&p->num,&p->name,&p->sub,&p->score);
	
		struct student *p9,*p10; //要改的前面一个
		p9=(struct student*)malloc(sizeof(struct student));
		
		p10=begin->next;
		p9=begin;//防止第一个就大于 
	
		while(p->num>p10->num)
		{
			if(p10->next==NULL)
			{
				p10->next=p;
				p->next=NULL;
				goto loop;
			 } 
			p9=p10; 
			p10=p10->next;
		} 
	
		p9->next=p;
		
		p->next=p10; 
		
		loop:;    //goto 到这 
	
	
		
	}
	fclose(fp); 
	p=begin->next;
	while(p!=NULL)
	{
	
		printf("%d %s %s %lf\n",p->num,p->name,p->sub,p->score); 
		
		p=p->next;
	}
	
	FILE *fp1;
	fp1=fopen("1.txt","w+");
	
	p=begin->next;
	while(p!=NULL)
	{
	
		fprintf(fp1,"%d %s %s %.2lf\n",p->num,p->name,p->sub,p->score);
		p=p->next;
	}
	fclose(fp1);

	return begin;
 } 
/**********************************************************
Function: print 
Description： 打印当前文件内容 
Calls：无 
Called By: main 
parameter: *p ,*begin
Return:无 
**********************************************************/
void print(struct student *begin)
{
	struct student *p;
	p=(struct student*)malloc(sizeof(struct student));
	system("cls");
	printf("学号	   姓名	      科目	 分数\n"); 
	p=begin->next;
	while(p!=NULL)
	{
	
		printf("%-10d %-10s %-10s %-10.2lf\n",p->num,p->name,p->sub,p->score);
		p=p->next;
	}
	
}
/**********************************************************
Function:search_r
Description： 按学生姓名查找并打印其完整信息 
Calls：无 
Called By: main 
parameter： *begin ,*p ,*search 
Return:无 
**********************************************************/
void search_r(struct student *begin)
{
	struct student *p;
	p=(struct student*)malloc(sizeof(struct student));
	char search[10];
	printf("输入你要查的学生姓名"); 
	if((scanf("%s",&search))==1) //判断输入格式正确性 
	{
		p=begin->next;
		while(strcmp(search,p->name)&&p->next!=NULL)
		{
			p=p->next;
		}
		if((strcmp(search,p->name))==0)
		{
			printf("%-10d %-10s %-10s %-10.2lf\n",p->num,p->name,p->sub,p->score);
			printf("按Enter以继续"); 
			getchar();
			getchar();
		}
		else
		{
			printf("未找到\n"); 
			printf("按Enter以继续"); 
			getchar();
			getchar();
		}
	}
	else
	{
		printf("输入错误\n");
		printf("按Enter以继续"); 
		getchar();
		getchar(); 
	}
}
/**********************************************************
Function: add
Description： 增加一个学生，按学号顺序添加入链表，并更新文件 
Calls：无 
Called By: main 
parameter：*begin ,*p1 ,*p ,*p5 ,*d ,*fp1 
Return:*begin 链表头 
**********************************************************/
struct student *add(struct student *begin)
{
	struct student *p1; 
	p1=(struct student*)malloc(sizeof(struct student));
	
	struct student *p;
	p=(struct student*)malloc(sizeof(struct student));
	
	printf("输入你要添加学生的学号、姓名、科目、分数");
	if((scanf("%d %s %s %lf",&p1->num,&p1->name,&p1->sub,&p1->score))==4) //判断输入格式正确性 
	{
		
		//排序
		struct student *p5; //要改的前面一个
		p5=(struct student*)malloc(sizeof(struct student));
		p=begin->next;
		int d=0;
		p5=begin;//防止第一个就大于 
		
		while(p1->num>p->num)
		{
			if(p->next==NULL)
				{
					p->next=p1;
					p1->next=NULL;
					goto A;
				 } 
			p5=p; 
			p=p->next;
		} 
		
		p5->next=p1;
		
		p1->next=p; 
		
		A:;   //goto 到这 
		
		FILE *fp1;
		fp1=fopen("1.txt","w+");
		
		p=begin->next;
		while(p!=NULL)
		{
		
			fprintf(fp1,"%d %s %s %.2lf\n",p->num,p->name,p->sub,p->score);
			p=p->next;
		}
		fclose(fp1);
	}
	else
	{
		printf("输入错误\n");
		getchar();
		printf("按Enter以继续"); 
		getchar();

		getchar(); 
	}
		

	return begin;
	
	
}
/**********************************************************
Function: amend 
Description： 输入你要修改的学生的学号，修改其成绩，并保存至文件 
Calls： 无 
Called By:  main 
parameter：*begin ,*p ,a ,*fp2 
Return: *begin 链表头 
**********************************************************/
struct student *amend(struct student *begin)
{
	struct student *p;
	p=(struct student*)malloc(sizeof(struct student));
	
	int a; //要修改的学号 
	printf("输入你要修改的学生的学号");
	if((scanf("%d",&a))==1) //判断输入格式正确性 
	{
		p=begin->next;
		while(p->num!=a&&p->next!=NULL)
		{
		
	
			p=p->next;
		}
		if(p->num==a)//判断输入存在性 
		{
			printf("%-10d %-10s %-10s %-10.2lf\n",p->num,p->name,p->sub,p->score);
			printf("输入你修改的分数");
			if((scanf("%lf",&p->score))==1) //判断输入格式正确性 
			{
				FILE *fp2;
				fp2=fopen("1.txt","w+");
				
				p=begin->next;
				while(p!=NULL)
				{
				
					fprintf(fp2,"%d %s %s %.2lf\n",p->num,p->name,p->sub,p->score);
					p=p->next;
					fclose(fp2);
				}
			}
			else
			{
				printf("输入错误\n");
				getchar();
				printf("按Enter以继续"); 
				getchar();
				getchar(); 
			}
		}
		else
		{
			printf("查无此人\n");
			getchar();
			printf("按Enter以继续"); 
			getchar();
		 
		}
		
		
		
		
	}
	else
	{
		printf("输入错误\n");
		getchar();
		printf("按Enter以继续"); 
		getchar();
		getchar(); 
	}

	return begin;
}
/**********************************************************
Function: delect 
Description： 输入学生学号删除其信息，将其删除，更新文件 
Calls：无 
Called By: main 
parameter：*begin ,*p ,b ,*del ,*fp3 
Return:*begin 链表头 
Others: 
**********************************************************/
struct student *delect(struct student *begin)
{
	struct student *p;
	p=(struct student*)malloc(sizeof(struct student));
	int b;
	struct student *front;  //前一项 
	front=(struct student*)malloc(sizeof(struct student));
	printf("要删除的学生的学号");
	if((scanf("%d",&b))==1)//判断输入格式正确性 
	{
		p=begin;
		while(p->num!=b&&p->next!=NULL)
		{
			front=p; 
	
			p=p->next;
		}
		if(p->num==b) //判断输入存在性  
		{
			front->next=front->next->next;
	
			struct student *del; //要删除的那项 
			del=p;
			free(del);
			
			
			FILE *fp3;
			fp3=fopen("1.txt","w+");
			
			p=begin->next;
			while(p!=NULL)
			{
			
				fprintf(fp3,"%d %s %s %.2lf\n",p->num,p->name,p->sub,p->score);
				p=p->next;
			}
			fclose(fp3);
		}
		else
		{
			printf("查无此人\n");
			getchar();
			printf("按Enter以继续"); 
			getchar();
		}
		
		
	}
	else
	{
		printf("输入错误\n");
		getchar();
		printf("按Enter以继续"); 
		getchar();
		getchar();
	}
	
	return begin;
}
/**********************************************************
Function: seg 
Description：分段显示学生成绩 
Calls：无 
Called By: main  
parameter：*begin ,*p ,c 
Return:无 
**********************************************************/
void seg(struct student *begin)
{
	struct student *p;
	p=(struct student*)malloc(sizeof(struct student));
	printf("学号	   姓名	      科目	 分数\n"); 
	printf("60分以下\n");
	p=begin->next;
	while(p!=NULL)
	{
		if(p->score<60) 
			printf("%-10d %-10s %-10s %-10.2lf\n",p->num,p->name,p->sub,p->score);
		p=p->next;
	}
	printf("\n");
	
	for(int a=60;a<=80;a+=10)
	{
		int c=0;
		p=begin->next;
		while(p!=NULL)
		{
		
			if(c==0)
				printf("%d分 ~ %d分\n",a,a+10);
			c++; 
			if(p->score>=a&&p->score<a+10) 
				printf("%-10d %-10s %-10s %-10.2lf\n",p->num,p->name,p->sub,p->score);
			p=p->next;
		}
		printf("\n");
	}
	
	printf("90分以上\n");
	p=begin->next;
	while(p!=NULL)
	{
		if(p->score>=90) 
			printf("%-10d %-10s %-10s %-10.2lf\n",p->num,p->name,p->sub,p->score);
		p=p->next;
	}
	printf("按Enter以继续"); 
	getchar();
	getchar();

}
