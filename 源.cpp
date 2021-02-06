#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include<windows.h>
void display(struct student* head), progress_bar(int y), setxy(int x, int y), dis_system_time(), time(), headline();
void creat1();
void DoProgress(int, int);

struct system_time 
{
	int sec_time;
	int min_time;
	int hour_time;
	int day_time;
	int mouth_time;
	int year_time;
};

struct collage//学员信息 录入结构集合体 
{
	int male;// 
	int remale;
	char col_name[20]; //学院名字 
} input1[100];

struct student
{
	char name[100];//运动员名字 
	struct collage input; //学院名字学院性别人数 
	char sex[100];//性别
	int day;//日
	char eventname[20];
	int mouth;//月	 
	int grade; //分数 
	struct student* next;
};

struct PE//初始化 
{
	char event_name[20];
	char col_name[20];
	struct collage num[100];
	struct PE* next;
} input[100];

float grade11[100][100]; //男成绩分类成绩 
float grade22[100][100]; //女成绩分类成绩 

HANDLE hout;
COORD coord;

struct student* creat();
struct student* head;
struct PE* head_h;
struct student* add(struct student* head);
struct student* search(struct student* head);
struct student* change(struct student* head);
struct student* del(struct student* head);
struct student* insert(struct student* head);
struct student* rank(struct student* head);

void creat1()
{
	int q = 1;
	int z = 0;
	int inputnum = 1;
	int num = 0;
	while (q)
	{
		system("cls");
		printf("\t\t\t\t\t\t请输入第%d个学院名称\n", inputnum);
		setxy(60, 1);
		scanf("%s", input[num].col_name);
		printf("\n\n");
		printf("\t\t\t\t\t\t是否继续输入（任意键继续，0退出)\n");
		setxy(60, 5);
		scanf("%d", &q);
		printf("\n\n");
		inputnum++;
		num++;
	}
	q = 1;
	num = 0;
	inputnum = 1;
	while (q)
	{
		printf("\t\t\t\t\t\t请输入项目名称\n");
		setxy(60, 9 + z);
		scanf("%s", input[num].event_name);
		printf("\n\n");
		printf("\t\t\t\t\t\t是否继续输入（任意键继续，0退出)\n");
		setxy(60, 13 + z);
		scanf("%d", &q);
		printf("\n\n");
		if (q)
			z = z + 8;
		num++;
		inputnum++;
	}
}

struct student* creat()
{
	struct PE* x;
	x = (struct PE*)malloc(sizeof(struct PE));
	head = NULL;//重置头指针 
	int p = 0;
	int i = 0;
	int z = 0;
	int choice;
	char scolname[20];
	char sevent[20];
	struct student* p1;
	struct student* p2;


	p1 = p2 = (struct student*)malloc(sizeof(struct student));
	p1->input.male = 0;
	p1->input.remale = 0;
	system("cls");
	printf("\t\t\t\t\t\t请输入第%d个运动员的姓名", p + 1);
	setxy(60, 1);
	scanf("%s", p1->name);
	printf("\n\n");
JUMP0:	
	printf("\t\t\t\t\t\t请输入%s的性别", p1->name);
	setxy(63, 5 + z);
	scanf("%s", p1->sex);
	printf("\n\n");

	if (strcmp("男", p1->sex) != 0 && strcmp("女", p1->sex) != 0)
	{
		printf("\t\t\t\t\t\t输入错误，请重新输入\n");
		z += 4;
		goto JUMP0;
	}

JUMP5:	

	printf("\t\t\t\t\t\t请输入%s的学院", p1->name);
	setxy(63, 9 + z);
	scanf("%s", scolname);
	printf("\n\n");
	strcpy(p1->input.col_name, scolname);
	i = 0;

	while (1)
	{
		if (strlen(input[i].col_name) > 30 || input[i].col_name == NULL)
		{
			printf("\t\t\t\t\t\t查无此学院\n");
			z = z + 4;
			getch();
			goto JUMP5;
		}
		if (strcmp(input[i].col_name, scolname) == 0)
			break;
		else
		{
			i++;
			continue;
		}
	}

	if (strcmp("男", p1->sex) == 0)
		p1->input.male++;
	else
		p1->input.remale++;


JUMP4:	
	printf("\t\t\t\t\t\t请输入%s的项目\n", p1->name);
	setxy(66, 13 + z);
	scanf("%s", sevent);

	printf("\n\n");
	strcpy(p1->eventname, sevent);
	i = 0;

	while (1)
	{
		if (strlen(input[i].event_name) > 30 || input[i].event_name == NULL)
		{
			printf("\t\t\t\t\t\t查无此项目\n");
			getch();
			z = z + 8;
			goto JUMP4;
		}
		if (strcmp(input[i].event_name, sevent) == 0)
			break;
		else
		{
			i++;
			continue;
		}
	}

	printf("\t\t\t\t\t\t请输入第%d个学生的成绩", p + 1);
	setxy(63, 17 + z);
	scanf("%d", &p1->grade);
	printf("\n\n");
	printf("\t\t\t\t\t\t请输入参赛月日  回车隔开\n");
	setxy(63, 21 + z);

	scanf("%d", &p1->mouth);
	setxy(66, 21 + z);
	printf("月");
	scanf("%d", &p1->day);
	setxy(69, 21 + z);
	printf("日");
	printf("\n\n");
	head = p1;
	printf("\t\t\t\t\t\t是否继续输入按任意键继续，按0退出\n");
	setxy(63, 24 + z);
	printf("\n\n");
	p++;
	z = z + 4;
	scanf("%d", &choice);

	while (choice)
	{
		if (p == 1)
			head = p1;
		else
			p2 = p1;
		p1 = (struct student*)malloc(sizeof(struct student));
		printf("\t\t\t\t\t\t请输入第%d个学生的姓名", p + 1);
		setxy(63, 25 + z);
		scanf("%s", p1->name);
		printf("\n\n");
	JUMP1:	
		printf("\t\t\t\t\t\t请输入%s的性别", p1->name);
		setxy(66, 28 + z);
		scanf("%s", p1->sex);
		printf("\n\n");
		if (strcmp("男", p1->sex) != 0 && strcmp("女", p1->sex) != 0)
		{
			printf("\t\t\t\t\t\t输入错误，请重新输入\n");
			z = z + 4;
			setxy(63, 31 + z);
			printf("\n\n");
			goto JUMP1;
		}
	JUMP6:	
		printf("\t\t\t\t\t\t请输入%s的学院", p1->name);
		setxy(63, 34 + z);
		scanf("%s", scolname);
		printf("\n\n");
		strcpy(p1->input.col_name, scolname);
		i = 0;
		while (1)
		{

			if (strlen(input[i].col_name) > 30 || input[i].col_name == NULL)
			{
				printf("\t\t\t\t\t\t查无此学院\n");
				z = z + 4;
				setxy(63, 37 + z);
				printf("\n\n");
				getch();
				goto JUMP6;
			}
			if (strcmp(input[i].col_name, scolname) == 0)
				break;
			else
			{
				i++;
				continue;
			}

		}
		if (strcmp("男", p1->sex) == 0)
			p1->input.male++;
		else
			p1->input.remale++;
	JUMP7:	
		printf("\t\t\t\t\t\t请输入%s的项目\n", p1->name);
		setxy(63, 40 + z);
		scanf("%s", sevent);

		printf("\n\n");
		strcpy(p1->eventname, sevent);
		i = 0;
		while (1)
		{
			if (strlen(input[i].event_name) > 30 || input[i].event_name == NULL)
			{
				printf("\t\t\t\t\t\t查无此项目\n");
				z = z + 4;
				setxy(66, 43 + z);
				printf("\n\n");
				getch();
				goto JUMP7;
			}
			if (strcmp(input[i].event_name, sevent) == 0)
				break;
			else
			{
				i++;
				continue;
			}
		}
		printf("\t\t\t\t\t\t请输入第%d个学生的成绩", p + 1);
		setxy(63, 46 + z);
		scanf("%d", &p1->grade);
		printf("\n\n");
		printf("\t\t\t\t\t\t请输入参赛月日  回车隔开\n");
		setxy(66, 50 + z);
		scanf("%d", &p1->mouth);
		setxy(69, 50 + z);
		printf("月");
		scanf("%d", &p1->day);
		setxy(72, 50 + z);
		printf("日\n");
		p2->next = p1;//把链表连接起来 (重要 )
		printf("\t\t\t\t\t\t是否继续输入按任意键继续，按0退出\n");
		setxy(63, 53 + z);
		scanf("%d", &choice);
		printf("\n\n");
		p++;
		z = z + 32;
	}
	p1->next = NULL;
	return head;
}

void display(struct student* head)
{

	struct student* p;
	p = (struct student*)malloc(sizeof(struct student));
	p = head;
	/*if(head->grade==0) ;
	{
		printf("请先录入信息\n") ;
		getch();
		return ;
	}*/
	printf("%s%30s%30s%30s%30s\n", "选手姓名", "选手性别", "属于学院", "参赛日期", "获得分数");
	while (p)
	{
		printf("%s%30s%30s%25d月%d日%30d\n", p->name, p->sex, p->input.col_name, p->mouth, p->day, p->grade);
		printf("   \n");
		p = p->next;

	}
	getch();
}

struct student* add(struct student* head)
{
	struct student* p, * pp;
	pp = head;
	p = (struct student*)malloc(sizeof(struct student));
	printf("请输入学生的姓名");
	scanf("%s", p->name);
JUMP2:	
	printf("请输入%s的性别", p->name);
	scanf("%s", p->sex);
	if (strcmp("男", p->sex) != 0 && strcmp("女", p->sex) != 0)
	{
		printf("输入错误，请重新输入\n");
		goto JUMP2;
	}
	printf("请输入%s的学院", p->name);
	scanf("%s", p->input.col_name);
	if (strcmp("男", p->sex) == 0)
		p->input.male++;
	else
		p->input.remale++;
	printf("请输入学生的成绩");
	scanf("%d", &p->grade);
	printf("请输入参赛月日  回车隔开\n");
	scanf("%d\n%d", &p->mouth, &p->day);
	if (!pp) //如果头指针的地址为空 
		head = p;
	else //如果头指针地址不为空 
	{
		pp = head;
		while (pp->next != NULL)//头指针	  	  	

		{
			pp = (struct student*)malloc(sizeof(struct student));
			pp = pp->next;
		}
		pp->next = p;
	}
	p->next = NULL;
	return head;
}

struct student* search(struct student* head)
{
	struct student* p, * pp;
	pp = head;
	p = (struct student*)malloc(sizeof(struct student));
	char sname[20];
	printf("请输入你要查找的姓名\n");
	rewind(stdin);
	gets_s(sname);
	if (!pp) //如果头指针的地址为空 
		printf("查无此人\n");
	else
	{
		while (pp != NULL)//遍历	  	  	          
		{
			if (strcmp(pp->name, sname) == 0)
			{
				printf("找到了%s\n", sname);
				printf("姓名");
				printf("%13s", "性别");
				printf("%10s", "学院");
				printf("%12s", "参赛日期");
				printf("%33s", "学生成绩\n");
				printf("%s%10s%10s%10d月%d日%30d", pp->name, pp->sex, pp->input.col_name, pp->mouth, pp->day, pp->grade);
				getch();
				break;
			}
			else
			{
				if (!pp->next)
					printf("查无此人\n");
				pp = pp->next;
				continue;
			}
		}
	}
	return head;
}

struct student* change(struct student* head)
{
	int choice;
	int choice1;
	struct student* p, * pp;
	pp = head;
	p = (struct student*)malloc(sizeof(struct student));
	char sname[20];//查找 
	char xname[20];//修改名字 
	int xmouth, xday;//修改月日 
	char cname[20];//修改学院名字
	char csex[20];//修改性别 
	int xgrade;
	printf("请输入你要查找的姓名\n");
	rewind(stdin);
	gets_s(sname);
	if (!pp) //如果头指针的地址为空 
		printf("查无此人\n");
	else
	{
		while (pp != NULL)//遍历	  	  	          
		{
			if (strcmp(pp->name, sname) == 0)
			{
				printf("找到了%s\n", sname);
				printf("分数为%d\n", pp->grade);
				printf("是否修改，按任意键修改，按0放弃修改\n");
				scanf("%d", &choice);
				if (choice)
				{
					printf("1.修改名字\n");
					printf("2.修改学院\n");
					printf("3.修改日期\n");
					printf("4.修改成绩\n");
					printf("5.修改性别\n");
					printf("6.返回菜单\n");
					scanf("%d", &choice1);
					switch (choice1)
					{
					case 1:
						printf("请输入你要修改的姓名\n");
						rewind(stdin);
						gets_s(xname);
						strcpy(pp->name, xname);
						break;
					case 2:
						printf("请输入你要修改的学院名字\n");
						scanf("%s", &cname);
						strcpy(pp->input.col_name, cname);
						printf("修改成功\n");
						break;
					case 3:
						printf("请输入你要修改的日期(月和日)\n");
						scanf("%d\n%d", &xmouth, &xday);
						pp->mouth = xmouth;
						pp->day = xday;
						printf("修改成功\n");
						break;
					case 4:
						printf("请输入你要修改的分数\n");
						scanf("%d", &xgrade);
						pp->grade = xgrade;
						printf("修改成功\n");
						break;
					case 5:
						printf("请输入你要修改的性别\n");
						scanf("%s", csex);
						strcpy(pp->sex, csex);
						printf("修改成功\n");
						break;
					case 6:
						return 0;
						break;
					}


				}
				system("pause");
				break;
			}
			else
			{
				if (!pp->next)
					printf("查无此人\n");
				getch();
				pp = pp->next;
				continue;
			}
		}
	}
}

struct student* del(struct student* head)
{
	struct student* p, * pp, * ppp;
	char sname[20];
	int choice;
	p = pp = head;//p和pp指向头指针 
	if (head == NULL)
	{
		printf("请先录入数据再执行删除\n");
		getch();
		return head;
	}
	printf("请输入要删除的名字\n");
	scanf("%s", sname);
	while (p)//遍历P 
	{
		if (strcmp(p->name, sname) == 0)
		{
			printf("找到了%s的学生信息，是否删除，按任意键删除，按0取消\n", p->name);
			scanf("%d", &choice);
			if (choice)
			{
				if (p == head)//删除头结点 
				{
					head = head->next;
					printf("删除成功\n");
					getch();
					break;
				}
				else
				{
					pp->next = p->next;//pp的下一个结点指向当前p所指向的节点的下一个结点 
					ppp = p;//ppp存当前结点 
					p = pp->next; //p指向自身的下一个结点 
					printf("删除成功\n");
					getch();
					break;
				}
			}
		}
		else//否则进行新一轮循环 
		{
			pp = p;
			p = p->next;
			if (!p->next)
			{
				printf("查无此人\n");
				getch();
				break;
			}
		}
	}
	return head;
}

struct student* insert(struct student* head)
{
	struct student* p, * pp;
	p = pp = head;
	pp = (struct student*)malloc(sizeof(struct student));
	int num;
	int i = 0;
	printf("请输入你要插入的位置(输入1将插入到第一个结点之后)\n");
	scanf("%d", &num);
	num = num - 1;
	if (num < 0)
		printf("输入错误\n");
	while (i < num)
	{
		p = p->next;
		i++;
	}
	printf("请输入学生的姓名");
	scanf("%s", pp->name);
	printf("请输入学生的成绩");
	scanf("%d", &pp->grade);
JUMP3:
	printf("请输入%s的性别", pp->name);
	scanf("%s", pp->sex);
	if (strcmp("男", pp->sex) != 0 && strcmp("女", pp->sex) != 0)
	{
		printf("输入错误，请重新输入\n");
		goto JUMP3;
	}
	printf("请输入%s的学院", pp->name);
	scanf("%s", pp->input.col_name);
	if (strcmp("男", pp->sex) == 0)
		pp->input.male++;
	else
		pp->input.remale++;
	printf("请输入参赛月日  回车隔开\n");
	scanf("%d\n%d", &pp->mouth, &pp->day);
	if (head == NULL)
	{
		head = pp;
		head->next = NULL;
	}
	else
	{
		if (p->next)
		{
			pp->next = p->next;
			p->next = pp;
		}
		else
		{
			pp->next = NULL;
			p->next = pp;
		}
	}
	printf("插入信息成功\n");
	getch();
	return head;
}

struct student* rank(struct student* head)
{

	struct student* p1, * p2, * q1, * q2;
	int i = 0;
	p1 = head; //p1为传过来的链表 
	p2 = p1->next;//p2为p1后驱结点 
	while (p2)
	{
		if (p1->grade > p2->grade)//如果前面的成绩大于后面 就直接位置 
		{
			p1 = p2;
			p2 = p2->next;
		}
		else//如果p1小于等于p2，就不用换位置， 
		{
			p1->next = p2->next;//就把p2的下一个结点数据作为新p2 
			q1 = head;//让q1=头结点 
			q2 = q1->next;//q2为q1后驱结点 
			if (p2->grade > head->grade)//如果新p2大于头结点，直接换位置 把现在的head放在p2后面，p2为新头 
			{
				p2->next = head;
				head = p2;
			}
			else//如果新p2小于或者等于头结点，不换位置 
			{
				q1 = head;
				q2 = head->next;//q2为q1后驱结点 
				while (p2->grade < q2->grade)//当p2的值比q2的值小为真 
				{
					q1 = q2;
					q2 = q2->next;
				}
				p2->next = q2;
				q1->next = p2;
			}
			p2 = p1->next;
		}
	}
	while (head)
	{
		printf("%s%30s%30s%30s%30s%30s\n", "名次", "选手姓名", "选手性别", "属于学院", "参赛日期", "获得分数");
		if (i + 1 != 1 && i + 1 != 2 && i + 1 != 3)
			printf("第%d名%30s%30s%30s%25d月%d日%30d\n", i + 1, head->name, head->sex, head->input.col_name, head->mouth, head->day, head->grade);
		if (i + 1 == 1)
			printf("%s%30s%30s%30s%25d月%d日%30d\n", "冠军", head->name, head->sex, head->input.col_name, head->mouth, head->day, head->grade);
		if (i + 1 == 2)
			printf("%s%30s%30s%30s%25d月%d日%30d\n", "亚军", head->name, head->sex, head->input.col_name, head->mouth, head->day, head->grade);
		if (i + 1 == 3)
			printf("%s%30s%30s%30s%25d月%d日%30d\n", "季军", head->name, head->sex, head->input.col_name, head->mouth, head->day, head->grade);
		printf("\n");
		head = head->next;
		i++;
	}
	getch();
	return head;
}

struct student* output(struct student* head)//报表 
{
	struct student* p, * pp;
	pp = (struct student*)malloc(sizeof(struct student));
	p = pp = head;
	int x = 0;
	int X, i;
	char dayin[100];
	char dayin1[100];
	char fname[100];
	FILE* fp;
	printf("请输入你需要打印的学院:\n");
	rewind(stdin);
	gets_s(dayin1);
	strcpy(dayin, dayin1);
	for (i = 0; i < 100; i++)
	{
		if (strcmp(input[i].col_name, dayin1) != 0)
			continue;
		else
			goto JUMP8;
	}
	printf("%s", input[i].col_name);
	printf("没有这个学院\n");
	getch();
	return 0;
JUMP8:	
	fp = fopen(strcat(dayin1, "学院的报表文件.txt"), "w");
	//fprintf(fp,"%s%d%d%.1f%s%s%s",input[x].col_name,input[x].mouth,input[x].day,input[x].grade,input[x].name,input[x].sex,input[x].xiangmu) ; 
	fprintf(fp, "-------------------------------------------------------------------------%s学院-------------------------------------------------------------------------\n", dayin);
	while (1)
	{

		if (strcmp(dayin, pp->input.col_name) != 0)
			continue;
		fprintf(fp, "%87s%d号学生\n", " ", x + 1);
		fprintf(fp, "%87s名字:%s%57s\n", " ", pp->name, " ");
		fprintf(fp, "%87s性别:%s%64s\n", " ", pp->sex, " ");
		fprintf(fp, "%87s参与项目:%s\n", " ", pp->eventname);
		fprintf(fp, "%87s参与时间:%d月%d日%50s\n", " ", pp->mouth, pp->day, " ");
		if (strcmp(pp->sex, "男") == 0)
			fprintf(fp, "%87s该男生%s项目的成绩:%d%62s\n", " ", pp->eventname, pp->grade, " ");
		else
			fprintf(fp, "%87s该女生%s项目的成绩:%d%62s\n", " ", pp->eventname, pp->grade, " ");
		fprintf(fp, "-------------------------------------------------------------------------------------------------------------------------------------------------------------\n", dayin);
		pp = pp->next;
		x++;
		if (!pp)
			break;
	}
	fclose(fp);
	printf("保存成功\n");
}



void progress_bar(int y) 
{
	system("cls");
	printf("\33[36;40m\t\t                                 *                                                       \n");
	printf("\t\t                               \33[36;40m*****\33[0m        *         *      * * * * *                   \n");
	printf("\t\t                              \33[36;40m*******\33[0m       *         *      *         *                 \n");
	printf("\t\t                             \33[36;40m*********\33[0m      *         *      *         *                 \n");
	printf("\t\t                             \33[36;40m*********\33[0m      *         *      * * * * *                   \n");
	printf("\t\t                             \33[36;40m*********\33[0m      *         *      *         *                 \n");
	printf("\t\t                             \33[36;40m*********\33[0m      *         *      *         *                 \n");
	printf("\t\t                          \33[36;40m***************\33[0m    * * * * *       * * * * *                   \n");
	printf("\t\t\33[36;40m                       *********************                                             \n");
	printf("\t\t                    ***************************                                          \n");
	printf("\t\t                 *********************************                                       \n");
	printf("\t\t             *****************************************                                   \n");
	printf("\t\t          ***********************************************                                \n");
	printf("\t\t       *************         *********          *************                            \n");
	printf("\t\t   **********                *********                 **********                        \n");
	printf("\t\t*********                    *********                     *********                     \n");
	printf("\t\t                             *********                                                   \n");
	printf("\t\t                             *********                                                   \n");
	printf("\t\t                             *********                                                   \n");
	printf("\t\t                           *************                                                 \n");
	printf("\t\t                         *****************                                               \n");
	printf("\t\t                       *********   *********                                             \33[0m\n");
	printf("\n\t人生就像一场旅行，不必在乎目的地，在乎的是沿途的风景以及看风景的心情，让心灵去旅行!\n\n\n");
	for (int i = 0; i < 100; i++)
	{
		DoProgress(i, 100); // 显示进度条
		rewind(stdout);
		Sleep(50); // 每次显示延迟1s
	}
}

void DoProgress(int t, int n)
{
	putchar('[');
	for (int i = 0; i < n; i++) {
		putchar(i < t ? '>' : ' '); // 输出> 或者 ' '
	}
	putchar(']');
	printf("%3d%%", (int)((double(t) / n) * 100));

	// 光标回退，实现刷新
	for (int i = 0; i != n + 6; i++) {
		putchar('\b');
	}

}

void setxy(int x, int y)  //设置CMD窗口光标位置
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void dis_system_time() 
{ 
	int m;
	printf("\r");
	printf("                          ");
	struct system_time* t_time;
	time_t system_sec_time;
	time(&system_sec_time);
	t_time = (struct system_time*)localtime(&system_sec_time);
	printf("*当前时间:%4d-%2d-%d %2d:%2d:%2d*\n", t_time->year_time + 1900, t_time->mouth_time, t_time->day_time, t_time->hour_time, t_time->min_time, t_time->sec_time);
}

int main()
{

	progress_bar(1);
	printf("\n\t\t\t\t\t\t\t\t登陆成功\n");
	Sleep(1500);
	system("cls");
	/*while(1)
	{

	dis_system_time();
		if(kbhit()){
			setxy(0,14);
		}
	}*/
	while (1)
	{
		system("cls");
		const char* option[] = {
		"                                                  ★.初始化信息                                                  ",
		"                                                  ★.录入信息                                                    ",
		"                                                  ★.查询信息                                                    ",
		"                                                  ★.添加成绩                                                    ",
		"                                                  ★.搜索运动员成绩                                              ",
		"                                                  ★.修改运动员成绩                                              ",
		"                                                  ★.删除运动员成绩                                              ",
		"                                                  ★.插入运动员成绩                                              ",
		"                                                  ★.查看成绩排行榜                                              ",
		"                                                  ★.打印运动会报表                                              ",
		"                                                  ★.退出                                                        ", };

		char key = 0;
		int t, select = 0;
		HANDLE ohandle = GetStdHandle(STD_OUTPUT_HANDLE);
		while (true)
		{

			headline();
			for (t = 0; t < 11; t++)
			{                 //这里共10个选项
				if (t == select)//设置焦点高亮
					SetConsoleTextAttribute(ohandle, FOREGROUND_GREEN);
				else if (t == select + 1 || t == select - 1 || t == select - 2 || t == select - 3 || t == select - 4 || t == select - 5 || t == select - 6 || t == select - 7 || t == select - 8 || t == select - 9 || t == select - 10)//||t==select-1||t==select-2||t==select-3||t==select-4||t==select-5||t==select-6||t==select-7||t==select-8||t==select-9||t==select-10)//恢复设置
					SetConsoleTextAttribute(ohandle, FOREGROUND_RED | FOREGROUND_GREEN);
				puts(option[t]);
			}
			SetConsoleTextAttribute(ohandle, FOREGROUND_INTENSITY);//恢复设置
			SetConsoleCursorPosition(hout, coord);
			SetConsoleTextAttribute(hout, FOREGROUND_RED);
			printf("\n");
			printf("%47s═══════温馨提示:═══════\n%65s%66s%66s%94s", " ", "①按ESC键退出程序\n", "②按回车键执行操作\n", "③↑或↓键进行选择\n", "═══════════════════════\n");
			SetConsoleTextAttribute(ohandle, FOREGROUND_RED | FOREGROUND_GREEN);//恢复设置

			key = getch();
			if (key == 0x1b)  //ESC 键
				exit(0);
			if (key == 0xd)  //Enter 键
				break;
			if (key < 0)
			{  //非ascii码键2个字节
				key = getch();

				switch (MapVirtualKey(key, 1))
				{
				case VK_UP:
					select = (select + 10) % 11;//焦点上移，减一，滚动选择，共4个选项
					break;
				case VK_DOWN:
					select = (select + 1) % 11;//焦点下移，加一
					break;

				}



			}

			system("cls");
		}



		switch (select)
		{
		case 0://初始化 
			creat1();
			break;
		case 1:
			creat();
			break;
		case 2:
			display(head);
			break;
		case 3:
			head = add(head);
			break;
		case 4:
			search(head);
			break;
		case 5:
			change(head);
			break;
		case 6:
			head = del(head);
			break;
		case 7:
			head = insert(head);
			break;
		case 8:
			head = rank(head);
			break;
		case 9:
			output(head);
			break;
		case 10:
			exit(0);

		}

	}

}

void headline()
{
	int m, n;
	m = 48;
	n = 1;
	HANDLE hout;
	COORD coord;
	coord.X = m;
	coord.Y = n;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, coord);
	SetConsoleTextAttribute(hout, FOREGROUND_GREEN | FOREGROUND_BLUE);
	printf("学生运动会管理系统\n");
	printf("\n");
	time();
}

void time()
{
	SYSTEMTIME sys;
	printf("\n\n\t\t\t\t\t\t\t当前时间为：\n");
	GetLocalTime(&sys); //获取系统时间 
	printf("\t\t\t\t\t\t\t\t%4d年-%02d月-%02d日 %02d时:%02d分:%02d秒\n",
		sys.wYear, sys.wMonth, sys.wDay, sys.wHour, sys.wMinute,
		sys.wSecond, sys.wDayOfWeek); //按照年/月/日 时/分/秒 星期几格式打印 
	return;
}
