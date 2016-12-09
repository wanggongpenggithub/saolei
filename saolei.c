#include"sweep.h"
void menu()
{
	printf("*****************************************************************\n");
	printf("***********************     扫雷     ****************************\n");
	printf("***********************    1.play    ****************************\n");
	printf("***********************    0.exit    ****************************\n");
	printf("*****************************************************************\n");
}
void display_mine(char mine[ ][COLS+2], int rows, int cols)//打印雷阵
{
	int i = 0;
	int j = 0;
	printf(" ");
	for(i=1;i<=rows;i++)
	{   
		printf(" %2d",i);
	}
	printf("\n");
	for (i = 1; i <=rows; i++)//输出行的标号
	{     
		printf("%2d",i);
		for(j=1;j<=cols;j++)
	{
	      printf(" %c ",mine[i][j]);
		}
		printf("\n");
	}
}
void display_show(char show[ ][COLS+2], int rows, int cols)
{
	int i = 0;
	int j = 0;
	printf("     ");
	for (i =1; i <=rows; i++)
	{
		printf("%2d ",i);
	}
	printf("\n  ");

	for (i =1; i <=rows; i++)
	{   
		printf("%2d ",i);


		for (j =1; j <=cols; j++)
		{
			printf(" %c ",show[i][j]);
		}
		printf("\n  ");

	}
}

void set_mines( char mine[][COLS+2] )//布雷
{     
	int count = MINES;//定义雷的个数
	srand((unsigned int)time(NULL));//为了每次产生不同的随机数
flag:
	while (count)//当雷没有布完时，执行循环
	{
		int  x = rand()%(ROWS)+1;//产生随机的下标
		int  y = rand()%(COLS)+1;
		  if(mine[x][y] =='#')//如果这个位置已经布过雷，则重新生成下标
		{
			goto flag;
		}
		else
		{
			mine[x][y] = '#';
			count--;//布一个雷之后雷的个数应该减一
		}
	}
}
void sweep(char mine[ ][COLS+2],char show[ ][COLS+2])//扫雷
{   
	int i = 0;
	int j = 0;
	int x = 0;
	int y = 0;
	int x1=0;
	int y1=0;
	printf("请输入要第一次排雷的位置>");
	scanf("%d %d",&x1, &y1);
		  if (mine[x1][y1] == '#')//如果第一次点击的就是雷的位置，则应该把这个雷移走
	{   
		for (i=0; i<x1; i++)
		{
			for (j = 0; j<y1-1; j++)
			{
				if (mine[i][j] != '#')
				{   
					mine[i][j] = mine[x1][y1] ;
					mine[x1][y1]=' ';
				}
			}
		}
	}
	else 
	{
		//如果点击的位置不是雷，则应该统计雷的个数
		show[x1][y1] = ((mine[x1-1][y1-1] == '#') 
			+ (mine[x1-1][y1] == '#') + (mine[x1-1][y1+1] == '#')
			+ (mine[x1][y1-1] == '#') + (mine[x1][y1+1] == '#')
			+ (mine[x1+1][y1-1] == '#') + (mine[x1+1][y] == '#')
			+ (mine[x1+1][y1+1] == '#'))+ '0';
		  if(show[x1][y1]=='0')
		{
			for(x=x1-1;x<=x1+1;x++)
				for(y=y1-1;y<=y1+1;y++)
				{
					show[x][y]=((mine[x-1][y-1] == '#') 
						+ (mine[x-1][y] == '#') + (mine[x-1][y+1] == '#')
						+ (mine[x][y-1] == '#') + (mine[x][y+1] == '#')
						+ (mine[x+1][y-1] == '#') + (mine[x+1][y] == '#')
						+ (mine[x+1][y+1] == '#'))+ '0';;
				}
		}
	}
	display_show(show, ROWS, COLS);  //打印出雷阵
	while(1)
	{
		printf("请输入要排的位置 :>");
		scanf("%d%d",&x1,&y1);
		if(mine[x1][y1] == '#')
		{   
			printf("炸死了\n");
			break;
		}
		else         //如果点击的位置不是雷，则应该统计雷的个数
		{                                         
			show[x1][y1] = ((mine[x1-1][y1-1] == '#') 
				+ (mine[x1-1][y1] == '#') + (mine[x1-1][y1+1] == '#')
				+ (mine[x1][y1-1] == '#') + (mine[x1][y1+1] == '#')
				+ (mine[x1+1][y1-1] == '#') + (mine[x1+1][y] == '#')
				+ (mine[x1+1][y1+1] == '#'))+ '0';
			if(show[x1][y1]=='0')
			{
				for(x=x1-1;x<=x1+1;x++)
					for(y=y1-1;y<=y1+1;y++)
					{
						show[x][y]=((mine[x-1][y-1] == '#') 
							+ (mine[x-1][y] == '#') + (mine[x-1][y+1] == '#')
							+ (mine[x][y-1] == '#') + (mine[x][y+1] == '#')
							+ (mine[x+1][y-1] == '#') + (mine[x+1][y] == '#')
							+ (mine[x+1][y+1] == '#'))+ '0';
						 
			}

			}}
		display_show(show, ROWS, COLS);//打印显示雷的个数的数组
	}
}