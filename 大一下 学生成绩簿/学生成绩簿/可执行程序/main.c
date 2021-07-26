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
			
			
				case 0:search_r(begin);break;//查找 
				case 1:begin=add(begin);break;//添加 
				case 2:begin=amend(begin);break;//修改 
				case 3:begin=delect(begin);break;//删除 
				case 4:seg(begin);break;//分段显示 
				case 5:exit(0);//退出 
				default: printf("请输入0~5\n"); printf("按Enter以继续"); getchar();getchar();
			}
		}
		else 
		{
			printf("请输入0~5\n");
			getchar();
			printf("按Enter以继续"); 
			getchar();
			getchar();
		}
	}
	
	

}
