#include"a.h"

/**********************************************************
Function:Password
Description�����벢����������ȷ�� 
Calls���� 
Called By: main() 
parameter��  pass ��������	,a ,d 
Return:�� 
**********************************************************/
void Password()
{
	
	char pass[10];													//�����û���������� 
	printf("		ѧ���ɼ���		\n\n\n");
	printf("���������룬������             (abc)\n");
	
	for(int a=0;a<CHANCE;a++)
	{	
		int d=11;
		scanf("%s",&pass);											//�������� 
		d=strcmp(PASS,pass);										//�û�������Ԥ�����ȶ� 
		if(d==0)
		{
			break;           										//������ȷ 
		}
		if(a==2)
		{
			printf("���������������"); 
			exit(1);  												//���볢�Դ����������ޣ������˳� 
		}
		printf("��������㻹ʣ%d�λ���",CHANCE-a-1);
		printf("������"); 
	}																//end of for(int a=0;a<CHANCE;a++) 
	printf("������ȷ\n\n"); 
	printf("�ļ���������ĳɼ�\n"); 
	
 } 
/**********************************************************
Function:menu
Description�� �˵���ʾ 
Calls���� 
Called By: main 
parameter���� 
Return:�� 
**********************************************************/
void menu()
{
	printf("==============================================================\n");
	printf("                            �˵�����\n");
	printf("                        0.��ѯѧ���ɼ�\n");
	printf("                        1.������ѧ���ɼ�\n");
	printf("                        2.�޸�ѧ���ɼ�\n");
	printf("                        3.ɾ��ѧ���ɼ�\n");
	printf("                        4.�ֶ���ʾ����ѧ���ɼ�\n");
	printf("                        5.�˳�\n");
	printf("==============================================================\n");
}
/**********************************************************
Function:read
Description�� ���ļ��ж�ȡ���ݲ���ѧ��˳��д�����������ļ� 
Calls���� 
Called By:main 
parameter:begin , *p ,*end, *fp, *p9 ,*p10 ,*fp1 
Return:*begin ����ͷ 
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
		printf("�ļ��򿪴���");
		exit(1); 
	}
	
	p=(struct student*)malloc(sizeof(struct student));
	end->next=p;
	end=p;
	p->next=NULL;
	fscanf(fp,"%d %s %s %lf",&p->num,&p->name,&p->sub,&p->score);//��һ�� 
	
	

	while(!feof(fp))//��ʽ��ʼ���� 
	{
	
		p=(struct student*)malloc(sizeof(struct student));
	
		fscanf(fp,"%d %s %s %lf\n",&p->num,&p->name,&p->sub,&p->score);
	
		struct student *p9,*p10; //Ҫ�ĵ�ǰ��һ��
		p9=(struct student*)malloc(sizeof(struct student));
		
		p10=begin->next;
		p9=begin;//��ֹ��һ���ʹ��� 
	
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
		
		loop:;    //goto ���� 
	
	
		
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
Description�� ��ӡ��ǰ�ļ����� 
Calls���� 
Called By: main 
parameter: *p ,*begin
Return:�� 
**********************************************************/
void print(struct student *begin)
{
	struct student *p;
	p=(struct student*)malloc(sizeof(struct student));
	system("cls");
	printf("ѧ��	   ����	      ��Ŀ	 ����\n"); 
	p=begin->next;
	while(p!=NULL)
	{
	
		printf("%-10d %-10s %-10s %-10.2lf\n",p->num,p->name,p->sub,p->score);
		p=p->next;
	}
	
}
/**********************************************************
Function:search_r
Description�� ��ѧ���������Ҳ���ӡ��������Ϣ 
Calls���� 
Called By: main 
parameter�� *begin ,*p ,*search 
Return:�� 
**********************************************************/
void search_r(struct student *begin)
{
	struct student *p;
	p=(struct student*)malloc(sizeof(struct student));
	char search[10];
	printf("������Ҫ���ѧ������"); 
	if((scanf("%s",&search))==1) //�ж������ʽ��ȷ�� 
	{
		p=begin->next;
		while(strcmp(search,p->name)&&p->next!=NULL)
		{
			p=p->next;
		}
		if((strcmp(search,p->name))==0)
		{
			printf("%-10d %-10s %-10s %-10.2lf\n",p->num,p->name,p->sub,p->score);
			printf("��Enter�Լ���"); 
			getchar();
			getchar();
		}
		else
		{
			printf("δ�ҵ�\n"); 
			printf("��Enter�Լ���"); 
			getchar();
			getchar();
		}
	}
	else
	{
		printf("�������\n");
		printf("��Enter�Լ���"); 
		getchar();
		getchar(); 
	}
}
/**********************************************************
Function: add
Description�� ����һ��ѧ������ѧ��˳������������������ļ� 
Calls���� 
Called By: main 
parameter��*begin ,*p1 ,*p ,*p5 ,*d ,*fp1 
Return:*begin ����ͷ 
**********************************************************/
struct student *add(struct student *begin)
{
	struct student *p1; 
	p1=(struct student*)malloc(sizeof(struct student));
	
	struct student *p;
	p=(struct student*)malloc(sizeof(struct student));
	
	printf("������Ҫ���ѧ����ѧ�š���������Ŀ������");
	if((scanf("%d %s %s %lf",&p1->num,&p1->name,&p1->sub,&p1->score))==4) //�ж������ʽ��ȷ�� 
	{
		
		//����
		struct student *p5; //Ҫ�ĵ�ǰ��һ��
		p5=(struct student*)malloc(sizeof(struct student));
		p=begin->next;
		int d=0;
		p5=begin;//��ֹ��һ���ʹ��� 
		
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
		
		A:;   //goto ���� 
		
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
		printf("�������\n");
		getchar();
		printf("��Enter�Լ���"); 
		getchar();

		getchar(); 
	}
		

	return begin;
	
	
}
/**********************************************************
Function: amend 
Description�� ������Ҫ�޸ĵ�ѧ����ѧ�ţ��޸���ɼ������������ļ� 
Calls�� �� 
Called By:  main 
parameter��*begin ,*p ,a ,*fp2 
Return: *begin ����ͷ 
**********************************************************/
struct student *amend(struct student *begin)
{
	struct student *p;
	p=(struct student*)malloc(sizeof(struct student));
	
	int a; //Ҫ�޸ĵ�ѧ�� 
	printf("������Ҫ�޸ĵ�ѧ����ѧ��");
	if((scanf("%d",&a))==1) //�ж������ʽ��ȷ�� 
	{
		p=begin->next;
		while(p->num!=a&&p->next!=NULL)
		{
		
	
			p=p->next;
		}
		if(p->num==a)//�ж���������� 
		{
			printf("%-10d %-10s %-10s %-10.2lf\n",p->num,p->name,p->sub,p->score);
			printf("�������޸ĵķ���");
			if((scanf("%lf",&p->score))==1) //�ж������ʽ��ȷ�� 
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
				printf("�������\n");
				getchar();
				printf("��Enter�Լ���"); 
				getchar();
				getchar(); 
			}
		}
		else
		{
			printf("���޴���\n");
			getchar();
			printf("��Enter�Լ���"); 
			getchar();
		 
		}
		
		
		
		
	}
	else
	{
		printf("�������\n");
		getchar();
		printf("��Enter�Լ���"); 
		getchar();
		getchar(); 
	}

	return begin;
}
/**********************************************************
Function: delect 
Description�� ����ѧ��ѧ��ɾ������Ϣ������ɾ���������ļ� 
Calls���� 
Called By: main 
parameter��*begin ,*p ,b ,*del ,*fp3 
Return:*begin ����ͷ 
Others: 
**********************************************************/
struct student *delect(struct student *begin)
{
	struct student *p;
	p=(struct student*)malloc(sizeof(struct student));
	int b;
	struct student *front;  //ǰһ�� 
	front=(struct student*)malloc(sizeof(struct student));
	printf("Ҫɾ����ѧ����ѧ��");
	if((scanf("%d",&b))==1)//�ж������ʽ��ȷ�� 
	{
		p=begin;
		while(p->num!=b&&p->next!=NULL)
		{
			front=p; 
	
			p=p->next;
		}
		if(p->num==b) //�ж����������  
		{
			front->next=front->next->next;
	
			struct student *del; //Ҫɾ�������� 
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
			printf("���޴���\n");
			getchar();
			printf("��Enter�Լ���"); 
			getchar();
		}
		
		
	}
	else
	{
		printf("�������\n");
		getchar();
		printf("��Enter�Լ���"); 
		getchar();
		getchar();
	}
	
	return begin;
}
/**********************************************************
Function: seg 
Description���ֶ���ʾѧ���ɼ� 
Calls���� 
Called By: main  
parameter��*begin ,*p ,c 
Return:�� 
**********************************************************/
void seg(struct student *begin)
{
	struct student *p;
	p=(struct student*)malloc(sizeof(struct student));
	printf("ѧ��	   ����	      ��Ŀ	 ����\n"); 
	printf("60������\n");
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
				printf("%d�� ~ %d��\n",a,a+10);
			c++; 
			if(p->score>=a&&p->score<a+10) 
				printf("%-10d %-10s %-10s %-10.2lf\n",p->num,p->name,p->sub,p->score);
			p=p->next;
		}
		printf("\n");
	}
	
	printf("90������\n");
	p=begin->next;
	while(p!=NULL)
	{
		if(p->score>=90) 
			printf("%-10d %-10s %-10s %-10.2lf\n",p->num,p->name,p->sub,p->score);
		p=p->next;
	}
	printf("��Enter�Լ���"); 
	getchar();
	getchar();

}
