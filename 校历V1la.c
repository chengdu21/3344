#include<stdio.h>
#include<string.h> 
int main()
{
	//江苏警官学院校历生成程序V1la(万年历功能考虑1582年消失的那10天，V1la不加入此功能，按照作业给出的额算法做) 
	//校历程序
	//IPO思想
	//这里我们先解决输入部分
	
	//第一个输入部分: 
	printf("----------江苏警官学院校历生成程序----------\n");
	printf("请你把校历的初始日期年.月.日给我[以点隔开]:");
	start0:
		;//因为不准这start0后面直接定义变量，所以呢我加了个分号 
	int y=0,m0=0,d0=0;	//初始日期的相关变量年月日 并初始化 
	scanf("%d.%d.%d",&y,&m0,&d0);	//输入校历起始日期
	if(d0==0){
		printf("输入错误，请重新输入。\n");
		goto start0; 
	}
	//爹日个输入部分: 
	printf("现在请给我校历的结束月.日给我[以点隔开]:");
	start1:
		;//同上个start 
	int m1=0,d1=0;
	scanf("%d.%d",&m1,&d1);
	if(d1==0||m1==0){
		printf("输入错误，请重新输入。");
		goto start1;
	} 
	
	//输入结束
	//开始处理输入的数据
	
	
	//现在以公元1年1月1日为初始计算日期以得到校历初始日期的周情况(防止胡乱而出现的1582年)
	//准备开始计算初始年的1月1日周几 
	int year=1970;
	int i=0;
	int r;
	while((y>=1970&&((m0>=1||d0>1)||(m0>1||d0>=1)))&&(year<=y)){
	i=++i%7+r;
	r=0;
	if((year%4==0&&year%100!=0)||year%400==0){
		r=1;
	}
	year++;
	//记录当前计算年份是否为闰年，此部结束计算后即可直接得到当前年份是否为闰年 
	} 
	//当年1月1日周几已成功获得
	//现在需要直到这一年月的日子数了 采用数组
	int mcnt[13]={31,28,31,30,31,30,31,31,30,31,30,31,29};
	if(r==1){
		int t=mcnt[1];
		mcnt[1]=mcnt[12];
		mcnt[12]=t;
	}
	int stdays=0;
	int j=0;
	for(j=0;j<m0;j++){
		if(j==m0-1){
			stdays+=1;
		}
		else stdays+=mcnt[j];
	}
	//printf("%d\n",stdays);
	stdays-=1;	//已经计算出了当年的1月1日周几了，但是这个是包括1月1日的，所以得减1
	i=(stdays+i+d0-1)%7;	//已经知道初始日周几了 
	//计算到这里大部分问题就是完成了 
	
	//以1970年1月1日(周4按照实际情况的算法余数对应周几)
	char wd[7][3]={"三","四","五","六","日","一","二"};	//应当需要多一个字符的位置，因为\0也是需要位置的
	//相关输出数据
	printf("----------江苏警官学院校历----------\n");
	printf("      %4d年%2d月%2d日--%4d年%2d月%2d日   \n",y,m0,d0,y,m1,d1);
	int wct=1;
	printf("周        日  一  二  三  四  五  六\n %d",wct);
	switch(i){
		case 5:
		;
		case 6:
		printf("    ");
		case 0:
		printf("    ");
		case 1:
		printf("    ");
		case 2:
		printf("    ");
		case 3:
		printf("    ");
		case 4:
		printf("    ");
		default:;
	}
	int x;	//计算时的日 
	int m;	//计算时的月份 
	if(m1>=m0){
		for(m=m0;m<=m1;m++){
			for(x=1;x<=mcnt[m-1];x++){
				if(x==1){
					printf("%2d~ ",m);
				}
				else{
					printf("%2d  ",x);
				}
				
				if(i==3){
					wct++;
					printf("\n");
						if(m==m1&&x==d1){
						goto out;
						}
						printf("%2d",wct);
						printf("        ");	
				}
				else if(m==m1&&x==d1){
					goto out;
				}
				
				
				i=++i%7;
				
			}
		}
		
		
	}
	
	out:
		printf("\n--------------生成结束--------------\n");
	printf("江苏警官学院校历生成程序V1.0la\nBy Chengdu Zhang\n%s--%s",wd[i],wd[i]);
	
	
	
	
	return 0;
 } 
