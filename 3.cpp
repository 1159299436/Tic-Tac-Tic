#include<stdio.h>
#include<stdlib.h>
#include<time.h>
# define row 3
# define lie 3

void menu()
{
printf("*******************\n");
printf("**����1��ʼ*0����**\n");
printf("*******************\n");
}
int isfull(char arr[row][lie],int r,int l)
{int i=0;
int j=0;

	for(i=0;i<r;i++)
	{
for(j=0;j<l;j++)
{
if(arr[i][j]==' ')
{return 0;}

}



	}

return 1;

}
void csh(char arr[row][lie],int r,int l)
{
	int i=0;
	int j=0;
for(i=0;i<r;i++)
{

for(j=0;j<l;j++)
{
	arr[i][j]=' ';
}
}
}
void dyqp(char arr[row][lie],int r,int l)
{
int i=0;

for(i=0;i<r;i++)
{
         int j=0;
         for(j=0;j<l;j++)
		 {printf("  %c  ",arr[i][j]);
           if(j<l-1)
		   {
           printf("|");
		   }
		 }
           printf("\n");
     if(i<r)
	  { 
     	for(j=0;j<l;j++)
		{
      printf("_ _ _");
         if(j<l-1)
		 {
          printf("|");
		 }
		}
		printf("\n");
	  }
}
}
void player(char arr[row][lie],int r,int l)
{int x=0;
int y=0;
printf("�������\n");

while(1)
{
	printf("������Ҫ�µ�λ��\n");
	scanf("%d%d",&x,&y);
if(x>=1&&x<=r&&y>=1&&y<=l&&arr[x-1][y-1]==' ')
{
arr[x-1][y-1]='*';
break;
}
else
printf("�����������������\n");

}

}
void aier(char arr[row][lie],int r,int l)
{int c=rand();
int ax=0;
int ay=0;
printf("��������\n");
while(1)
{ax=rand()%r;
ay=rand()%l;
 if(arr[ax][ay]==' ')
 {arr[ax][ay]='#';
 break;
 }
}
}

char pd (char arr[row][lie],int r,int l)
{int i=0;
for(i=0;i<r;i++)
{
if(arr[i][0]==arr[i][1]&&arr[i][1]==arr[i][2]&&arr[i][1]!=' ')
{ 
return arr[i][0];
}

else if(arr[0][i]==arr[1][i]&&arr[1][i]==arr[2][i]&&arr[1][i]!=' ')
{
return arr[0][i];
}
 else if(arr[0][0]==arr[1][1]&&arr[1][1]==arr[2][2]&&arr[1][1]!=' ')
{return arr[1][1];}
else if(arr[0][2]==arr[1][1]&&arr[1][1]==arr[2][0]&&arr[1][1]!=' ')
{return arr[1][1];}}
  if(isfull(arr,row,lie)==1)
return 'a';
else
return 'b';
}
void game()
{
	char arr[row][lie]={0};
	char ret=0;
csh(arr,row,lie);//��ʼ������
dyqp(arr,row,lie);//��ӡ����
while(1){

	
	
		
player(arr,row,lie);//���
dyqp(arr,row,lie);//��ӡ����
ret=pd(arr,row,lie);
if(ret!='b')
{break;}
aier(arr,row,lie);//����
dyqp(arr,row,lie);//��ӡ����
ret=pd(arr,row,lie);
if(ret!='b')//�ж���Ӯ retΪ'b'������� Ϊ'*'���Ӯ��Ϊ'#'����Ӯ��Ϊ'����'��ƽ�ֵ���˼
{break;}
}if(ret=='*')
{printf("���Ӯ\n");}
else if(ret=='#')
{printf("����Ӯ\n");
}
else 
printf("ƽ��\n");

}
int main()
{
menu();
int p=0;
 srand((unsigned int)time(NULL));
do
{
	printf("����������\n");
scanf("%d",&p);
switch(p)
{
case 1: game();
	break;
case 0:printf("��������\n");
	break;
default:printf("�������\n");
	break;
}
}while(p);
return 0;

}