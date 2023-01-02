#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define N 30
void print(int [][N]);//輸出函式
void movebul(int [][N]);//子彈移動函式
void movepla(int [][N]);//敵機移動函式
int scr[25][N]={0},pl=9,width=60,speed=3,density=30,score=0,death=0;//全域性變數：介面、我機初始位、介面寬度、敵機速度、敵機密度、得分、死亡
int main()
{
	int i=0,j=0;
	scr[21][pl]=1;
	scr[0][5]=3;
	while(1)
	{
		if(kbhit())
		switch(getch())//控制左右移動和進入選單
		{
			case 'a':
			case 'A':
			if(pl>0)scr[21][pl]=0,scr[21][--pl]=1;
			break;
			case 'd':
			case 'D':
			if(pl<width-2)scr[21][pl]=0,scr[21][++pl]=1;
			break;
			case 'w':
			case 'W':scr[20][pl]=2;
			break;
			case 27 :
			break;
	}
	if(++j%density==0)//控制生產敵機的速度
	{
		j=0;srand(time(NULL));
		scr[0][rand()%width]=3;
	}
	if(++i%speed==0)//控制敵機移動速度，相對於子彈移動速度
	movepla(scr);
	movebul(scr);
	print(scr);
	if(i==30000)
	i=0;//以免i 越界
	}
	return 0;
}


void print(int a[][N])
{
system("cls");
int i,j;
for(i=0;i<22;i++)
{
a[i][width-1]=4;
for(j=0;j<width;j++)
{
if(a[i][j]==0)printf(" ");
if(a[i][j]==1)printf("\5");//輸出我機的符號
if(a[i][j]==2)printf(".");//子彈
if(a[i][j]==3)printf("@"); //輸出敵機符號
if(a[i][j]==4)printf("|");
if(i==0&&j==width-1)printf("得分：%d",score);//右上角顯示得分
if(i==1&&j==width-1)printf("死亡：%d",death);
//if(i==3&&j==width-1)printf("Copyright:");
}
printf("\n");
}
}


void movebul(int a[][N])
{
int i,j;
for(i=0;i<22;i++)
for(j=0;j<width;j++)
{
if(i==0&&a[i][j]==2)a[i][j]=0;if(a[i][j]==2)
{
if(a[i-1][j]==3)
score+=10,printf("\7");
a[i][j]=0,a[i-1][j]=2;
}
}
}
void movepla(int a[][N])
{
int i,j;
for(i=21;i>=0;i--)//從最後一行往上是為了避免把敵機直接衝出陣列。
for(j=0;j<width;j++)
{
if(i==21&&a[i][j]==3)
a[i][j]=0;//底行賦值0 以免越界。
if(a[i][j]==3)
a[i][j]=0,a[i+1][j]=3;
}
if(a[20][pl]==3&&a[21][pl]==1)
death++;
}
