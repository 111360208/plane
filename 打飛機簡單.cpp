#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define N 30
void print(int [][N]);//��X�禡
void movebul(int [][N]);//�l�u���ʨ禡
void movepla(int [][N]);//�ľ����ʨ禡
int scr[25][N]={0},pl=9,width=60,speed=3,density=30,score=0,death=0;//������ܼơG�����B�ھ���l��B�����e�סB�ľ��t�סB�ľ��K�סB�o���B���`
int main()
{
	int i=0,j=0;
	scr[21][pl]=1;
	scr[0][5]=3;
	while(1)
	{
		if(kbhit())
		switch(getch())//����k���ʩM�i�J���
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
	if(++j%density==0)//����Ͳ��ľ����t��
	{
		j=0;srand(time(NULL));
		scr[0][rand()%width]=3;
	}
	if(++i%speed==0)//����ľ����ʳt�סA�۹��l�u���ʳt��
	movepla(scr);
	movebul(scr);
	print(scr);
	if(i==30000)
	i=0;//�H�Ki �V��
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
if(a[i][j]==1)printf("\5");//��X�ھ����Ÿ�
if(a[i][j]==2)printf(".");//�l�u
if(a[i][j]==3)printf("@"); //��X�ľ��Ÿ�
if(a[i][j]==4)printf("|");
if(i==0&&j==width-1)printf("�o���G%d",score);//�k�W����ܱo��
if(i==1&&j==width-1)printf("���`�G%d",death);
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
for(i=21;i>=0;i--)//�q�̫�@�橹�W�O���F�קK��ľ������ĥX�}�C�C
for(j=0;j<width;j++)
{
if(i==21&&a[i][j]==3)
a[i][j]=0;//������0 �H�K�V�ɡC
if(a[i][j]==3)
a[i][j]=0,a[i+1][j]=3;
}
if(a[20][pl]==3&&a[21][pl]==1)
death++;
}
