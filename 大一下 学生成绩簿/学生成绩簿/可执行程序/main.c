#include"a.h"
#include"func.c"
int main()
{
	int se;
	Password();
	struct student *begin; 
	begin=(struct student*)malloc(sizeof(struct student));
	begin=read(begin);
	
	for(;;)
	{
		print(begin); 
		menu();
		if((scanf("%d",&se))==1)
		{
			switch(se)
			{
			
			
				case 0:search_r(begin);break;//���� 
				case 1:begin=add(begin);break;//��� 
				case 2:begin=amend(begin);break;//�޸� 
				case 3:begin=delect(begin);break;//ɾ�� 
				case 4:seg(begin);break;//�ֶ���ʾ 
				case 5:exit(0);//�˳� 
				default: printf("������0~5\n"); printf("��Enter�Լ���"); getchar();getchar();
			}
		}
		else 
		{
			printf("������0~5\n");
			getchar();
			printf("��Enter�Լ���"); 
			getchar();
			getchar();
		}
	}
	
	

}
