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

struct collage//ѧԱ��Ϣ ¼��ṹ������ 
{
	int male;// 
	int remale;
	char col_name[20]; //ѧԺ���� 
} input1[100];

struct student
{
	char name[100];//�˶�Ա���� 
	struct collage input; //ѧԺ����ѧԺ�Ա����� 
	char sex[100];//�Ա�
	int day;//��
	char eventname[20];
	int mouth;//��	 
	int grade; //���� 
	struct student* next;
};

struct PE//��ʼ�� 
{
	char event_name[20];
	char col_name[20];
	struct collage num[100];
	struct PE* next;
} input[100];

float grade11[100][100]; //�гɼ�����ɼ� 
float grade22[100][100]; //Ů�ɼ�����ɼ� 

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
		printf("\t\t\t\t\t\t�������%d��ѧԺ����\n", inputnum);
		setxy(60, 1);
		scanf("%s", input[num].col_name);
		printf("\n\n");
		printf("\t\t\t\t\t\t�Ƿ�������루�����������0�˳�)\n");
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
		printf("\t\t\t\t\t\t��������Ŀ����\n");
		setxy(60, 9 + z);
		scanf("%s", input[num].event_name);
		printf("\n\n");
		printf("\t\t\t\t\t\t�Ƿ�������루�����������0�˳�)\n");
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
	head = NULL;//����ͷָ�� 
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
	printf("\t\t\t\t\t\t�������%d���˶�Ա������", p + 1);
	setxy(60, 1);
	scanf("%s", p1->name);
	printf("\n\n");
JUMP0:	
	printf("\t\t\t\t\t\t������%s���Ա�", p1->name);
	setxy(63, 5 + z);
	scanf("%s", p1->sex);
	printf("\n\n");

	if (strcmp("��", p1->sex) != 0 && strcmp("Ů", p1->sex) != 0)
	{
		printf("\t\t\t\t\t\t�����������������\n");
		z += 4;
		goto JUMP0;
	}

JUMP5:	

	printf("\t\t\t\t\t\t������%s��ѧԺ", p1->name);
	setxy(63, 9 + z);
	scanf("%s", scolname);
	printf("\n\n");
	strcpy(p1->input.col_name, scolname);
	i = 0;

	while (1)
	{
		if (strlen(input[i].col_name) > 30 || input[i].col_name == NULL)
		{
			printf("\t\t\t\t\t\t���޴�ѧԺ\n");
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

	if (strcmp("��", p1->sex) == 0)
		p1->input.male++;
	else
		p1->input.remale++;


JUMP4:	
	printf("\t\t\t\t\t\t������%s����Ŀ\n", p1->name);
	setxy(66, 13 + z);
	scanf("%s", sevent);

	printf("\n\n");
	strcpy(p1->eventname, sevent);
	i = 0;

	while (1)
	{
		if (strlen(input[i].event_name) > 30 || input[i].event_name == NULL)
		{
			printf("\t\t\t\t\t\t���޴���Ŀ\n");
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

	printf("\t\t\t\t\t\t�������%d��ѧ���ĳɼ�", p + 1);
	setxy(63, 17 + z);
	scanf("%d", &p1->grade);
	printf("\n\n");
	printf("\t\t\t\t\t\t�������������  �س�����\n");
	setxy(63, 21 + z);

	scanf("%d", &p1->mouth);
	setxy(66, 21 + z);
	printf("��");
	scanf("%d", &p1->day);
	setxy(69, 21 + z);
	printf("��");
	printf("\n\n");
	head = p1;
	printf("\t\t\t\t\t\t�Ƿ�������밴�������������0�˳�\n");
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
		printf("\t\t\t\t\t\t�������%d��ѧ��������", p + 1);
		setxy(63, 25 + z);
		scanf("%s", p1->name);
		printf("\n\n");
	JUMP1:	
		printf("\t\t\t\t\t\t������%s���Ա�", p1->name);
		setxy(66, 28 + z);
		scanf("%s", p1->sex);
		printf("\n\n");
		if (strcmp("��", p1->sex) != 0 && strcmp("Ů", p1->sex) != 0)
		{
			printf("\t\t\t\t\t\t�����������������\n");
			z = z + 4;
			setxy(63, 31 + z);
			printf("\n\n");
			goto JUMP1;
		}
	JUMP6:	
		printf("\t\t\t\t\t\t������%s��ѧԺ", p1->name);
		setxy(63, 34 + z);
		scanf("%s", scolname);
		printf("\n\n");
		strcpy(p1->input.col_name, scolname);
		i = 0;
		while (1)
		{

			if (strlen(input[i].col_name) > 30 || input[i].col_name == NULL)
			{
				printf("\t\t\t\t\t\t���޴�ѧԺ\n");
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
		if (strcmp("��", p1->sex) == 0)
			p1->input.male++;
		else
			p1->input.remale++;
	JUMP7:	
		printf("\t\t\t\t\t\t������%s����Ŀ\n", p1->name);
		setxy(63, 40 + z);
		scanf("%s", sevent);

		printf("\n\n");
		strcpy(p1->eventname, sevent);
		i = 0;
		while (1)
		{
			if (strlen(input[i].event_name) > 30 || input[i].event_name == NULL)
			{
				printf("\t\t\t\t\t\t���޴���Ŀ\n");
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
		printf("\t\t\t\t\t\t�������%d��ѧ���ĳɼ�", p + 1);
		setxy(63, 46 + z);
		scanf("%d", &p1->grade);
		printf("\n\n");
		printf("\t\t\t\t\t\t�������������  �س�����\n");
		setxy(66, 50 + z);
		scanf("%d", &p1->mouth);
		setxy(69, 50 + z);
		printf("��");
		scanf("%d", &p1->day);
		setxy(72, 50 + z);
		printf("��\n");
		p2->next = p1;//�������������� (��Ҫ )
		printf("\t\t\t\t\t\t�Ƿ�������밴�������������0�˳�\n");
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
		printf("����¼����Ϣ\n") ;
		getch();
		return ;
	}*/
	printf("%s%30s%30s%30s%30s\n", "ѡ������", "ѡ���Ա�", "����ѧԺ", "��������", "��÷���");
	while (p)
	{
		printf("%s%30s%30s%25d��%d��%30d\n", p->name, p->sex, p->input.col_name, p->mouth, p->day, p->grade);
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
	printf("������ѧ��������");
	scanf("%s", p->name);
JUMP2:	
	printf("������%s���Ա�", p->name);
	scanf("%s", p->sex);
	if (strcmp("��", p->sex) != 0 && strcmp("Ů", p->sex) != 0)
	{
		printf("�����������������\n");
		goto JUMP2;
	}
	printf("������%s��ѧԺ", p->name);
	scanf("%s", p->input.col_name);
	if (strcmp("��", p->sex) == 0)
		p->input.male++;
	else
		p->input.remale++;
	printf("������ѧ���ĳɼ�");
	scanf("%d", &p->grade);
	printf("�������������  �س�����\n");
	scanf("%d\n%d", &p->mouth, &p->day);
	if (!pp) //���ͷָ��ĵ�ַΪ�� 
		head = p;
	else //���ͷָ���ַ��Ϊ�� 
	{
		pp = head;
		while (pp->next != NULL)//ͷָ��	  	  	

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
	printf("��������Ҫ���ҵ�����\n");
	rewind(stdin);
	gets_s(sname);
	if (!pp) //���ͷָ��ĵ�ַΪ�� 
		printf("���޴���\n");
	else
	{
		while (pp != NULL)//����	  	  	          
		{
			if (strcmp(pp->name, sname) == 0)
			{
				printf("�ҵ���%s\n", sname);
				printf("����");
				printf("%13s", "�Ա�");
				printf("%10s", "ѧԺ");
				printf("%12s", "��������");
				printf("%33s", "ѧ���ɼ�\n");
				printf("%s%10s%10s%10d��%d��%30d", pp->name, pp->sex, pp->input.col_name, pp->mouth, pp->day, pp->grade);
				getch();
				break;
			}
			else
			{
				if (!pp->next)
					printf("���޴���\n");
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
	char sname[20];//���� 
	char xname[20];//�޸����� 
	int xmouth, xday;//�޸����� 
	char cname[20];//�޸�ѧԺ����
	char csex[20];//�޸��Ա� 
	int xgrade;
	printf("��������Ҫ���ҵ�����\n");
	rewind(stdin);
	gets_s(sname);
	if (!pp) //���ͷָ��ĵ�ַΪ�� 
		printf("���޴���\n");
	else
	{
		while (pp != NULL)//����	  	  	          
		{
			if (strcmp(pp->name, sname) == 0)
			{
				printf("�ҵ���%s\n", sname);
				printf("����Ϊ%d\n", pp->grade);
				printf("�Ƿ��޸ģ���������޸ģ���0�����޸�\n");
				scanf("%d", &choice);
				if (choice)
				{
					printf("1.�޸�����\n");
					printf("2.�޸�ѧԺ\n");
					printf("3.�޸�����\n");
					printf("4.�޸ĳɼ�\n");
					printf("5.�޸��Ա�\n");
					printf("6.���ز˵�\n");
					scanf("%d", &choice1);
					switch (choice1)
					{
					case 1:
						printf("��������Ҫ�޸ĵ�����\n");
						rewind(stdin);
						gets_s(xname);
						strcpy(pp->name, xname);
						break;
					case 2:
						printf("��������Ҫ�޸ĵ�ѧԺ����\n");
						scanf("%s", &cname);
						strcpy(pp->input.col_name, cname);
						printf("�޸ĳɹ�\n");
						break;
					case 3:
						printf("��������Ҫ�޸ĵ�����(�º���)\n");
						scanf("%d\n%d", &xmouth, &xday);
						pp->mouth = xmouth;
						pp->day = xday;
						printf("�޸ĳɹ�\n");
						break;
					case 4:
						printf("��������Ҫ�޸ĵķ���\n");
						scanf("%d", &xgrade);
						pp->grade = xgrade;
						printf("�޸ĳɹ�\n");
						break;
					case 5:
						printf("��������Ҫ�޸ĵ��Ա�\n");
						scanf("%s", csex);
						strcpy(pp->sex, csex);
						printf("�޸ĳɹ�\n");
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
					printf("���޴���\n");
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
	p = pp = head;//p��ppָ��ͷָ�� 
	if (head == NULL)
	{
		printf("����¼��������ִ��ɾ��\n");
		getch();
		return head;
	}
	printf("������Ҫɾ��������\n");
	scanf("%s", sname);
	while (p)//����P 
	{
		if (strcmp(p->name, sname) == 0)
		{
			printf("�ҵ���%s��ѧ����Ϣ���Ƿ�ɾ�����������ɾ������0ȡ��\n", p->name);
			scanf("%d", &choice);
			if (choice)
			{
				if (p == head)//ɾ��ͷ��� 
				{
					head = head->next;
					printf("ɾ���ɹ�\n");
					getch();
					break;
				}
				else
				{
					pp->next = p->next;//pp����һ�����ָ��ǰp��ָ��Ľڵ����һ����� 
					ppp = p;//ppp�浱ǰ��� 
					p = pp->next; //pָ���������һ����� 
					printf("ɾ���ɹ�\n");
					getch();
					break;
				}
			}
		}
		else//���������һ��ѭ�� 
		{
			pp = p;
			p = p->next;
			if (!p->next)
			{
				printf("���޴���\n");
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
	printf("��������Ҫ�����λ��(����1�����뵽��һ�����֮��)\n");
	scanf("%d", &num);
	num = num - 1;
	if (num < 0)
		printf("�������\n");
	while (i < num)
	{
		p = p->next;
		i++;
	}
	printf("������ѧ��������");
	scanf("%s", pp->name);
	printf("������ѧ���ĳɼ�");
	scanf("%d", &pp->grade);
JUMP3:
	printf("������%s���Ա�", pp->name);
	scanf("%s", pp->sex);
	if (strcmp("��", pp->sex) != 0 && strcmp("Ů", pp->sex) != 0)
	{
		printf("�����������������\n");
		goto JUMP3;
	}
	printf("������%s��ѧԺ", pp->name);
	scanf("%s", pp->input.col_name);
	if (strcmp("��", pp->sex) == 0)
		pp->input.male++;
	else
		pp->input.remale++;
	printf("�������������  �س�����\n");
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
	printf("������Ϣ�ɹ�\n");
	getch();
	return head;
}

struct student* rank(struct student* head)
{

	struct student* p1, * p2, * q1, * q2;
	int i = 0;
	p1 = head; //p1Ϊ������������ 
	p2 = p1->next;//p2Ϊp1������� 
	while (p2)
	{
		if (p1->grade > p2->grade)//���ǰ��ĳɼ����ں��� ��ֱ��λ�� 
		{
			p1 = p2;
			p2 = p2->next;
		}
		else//���p1С�ڵ���p2���Ͳ��û�λ�ã� 
		{
			p1->next = p2->next;//�Ͱ�p2����һ�����������Ϊ��p2 
			q1 = head;//��q1=ͷ��� 
			q2 = q1->next;//q2Ϊq1������� 
			if (p2->grade > head->grade)//�����p2����ͷ��㣬ֱ�ӻ�λ�� �����ڵ�head����p2���棬p2Ϊ��ͷ 
			{
				p2->next = head;
				head = p2;
			}
			else//�����p2С�ڻ��ߵ���ͷ��㣬����λ�� 
			{
				q1 = head;
				q2 = head->next;//q2Ϊq1������� 
				while (p2->grade < q2->grade)//��p2��ֵ��q2��ֵСΪ�� 
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
		printf("%s%30s%30s%30s%30s%30s\n", "����", "ѡ������", "ѡ���Ա�", "����ѧԺ", "��������", "��÷���");
		if (i + 1 != 1 && i + 1 != 2 && i + 1 != 3)
			printf("��%d��%30s%30s%30s%25d��%d��%30d\n", i + 1, head->name, head->sex, head->input.col_name, head->mouth, head->day, head->grade);
		if (i + 1 == 1)
			printf("%s%30s%30s%30s%25d��%d��%30d\n", "�ھ�", head->name, head->sex, head->input.col_name, head->mouth, head->day, head->grade);
		if (i + 1 == 2)
			printf("%s%30s%30s%30s%25d��%d��%30d\n", "�Ǿ�", head->name, head->sex, head->input.col_name, head->mouth, head->day, head->grade);
		if (i + 1 == 3)
			printf("%s%30s%30s%30s%25d��%d��%30d\n", "����", head->name, head->sex, head->input.col_name, head->mouth, head->day, head->grade);
		printf("\n");
		head = head->next;
		i++;
	}
	getch();
	return head;
}

struct student* output(struct student* head)//���� 
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
	printf("����������Ҫ��ӡ��ѧԺ:\n");
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
	printf("û�����ѧԺ\n");
	getch();
	return 0;
JUMP8:	
	fp = fopen(strcat(dayin1, "ѧԺ�ı����ļ�.txt"), "w");
	//fprintf(fp,"%s%d%d%.1f%s%s%s",input[x].col_name,input[x].mouth,input[x].day,input[x].grade,input[x].name,input[x].sex,input[x].xiangmu) ; 
	fprintf(fp, "-------------------------------------------------------------------------%sѧԺ-------------------------------------------------------------------------\n", dayin);
	while (1)
	{

		if (strcmp(dayin, pp->input.col_name) != 0)
			continue;
		fprintf(fp, "%87s%d��ѧ��\n", " ", x + 1);
		fprintf(fp, "%87s����:%s%57s\n", " ", pp->name, " ");
		fprintf(fp, "%87s�Ա�:%s%64s\n", " ", pp->sex, " ");
		fprintf(fp, "%87s������Ŀ:%s\n", " ", pp->eventname);
		fprintf(fp, "%87s����ʱ��:%d��%d��%50s\n", " ", pp->mouth, pp->day, " ");
		if (strcmp(pp->sex, "��") == 0)
			fprintf(fp, "%87s������%s��Ŀ�ĳɼ�:%d%62s\n", " ", pp->eventname, pp->grade, " ");
		else
			fprintf(fp, "%87s��Ů��%s��Ŀ�ĳɼ�:%d%62s\n", " ", pp->eventname, pp->grade, " ");
		fprintf(fp, "-------------------------------------------------------------------------------------------------------------------------------------------------------------\n", dayin);
		pp = pp->next;
		x++;
		if (!pp)
			break;
	}
	fclose(fp);
	printf("����ɹ�\n");
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
	printf("\n\t��������һ�����У������ں�Ŀ�ĵأ��ں�������;�ķ羰�Լ����羰�����飬������ȥ����!\n\n\n");
	for (int i = 0; i < 100; i++)
	{
		DoProgress(i, 100); // ��ʾ������
		rewind(stdout);
		Sleep(50); // ÿ����ʾ�ӳ�1s
	}
}

void DoProgress(int t, int n)
{
	putchar('[');
	for (int i = 0; i < n; i++) {
		putchar(i < t ? '>' : ' '); // ���> ���� ' '
	}
	putchar(']');
	printf("%3d%%", (int)((double(t) / n) * 100));

	// �����ˣ�ʵ��ˢ��
	for (int i = 0; i != n + 6; i++) {
		putchar('\b');
	}

}

void setxy(int x, int y)  //����CMD���ڹ��λ��
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
	printf("*��ǰʱ��:%4d-%2d-%d %2d:%2d:%2d*\n", t_time->year_time + 1900, t_time->mouth_time, t_time->day_time, t_time->hour_time, t_time->min_time, t_time->sec_time);
}

int main()
{

	progress_bar(1);
	printf("\n\t\t\t\t\t\t\t\t��½�ɹ�\n");
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
		"                                                  ��.��ʼ����Ϣ                                                  ",
		"                                                  ��.¼����Ϣ                                                    ",
		"                                                  ��.��ѯ��Ϣ                                                    ",
		"                                                  ��.��ӳɼ�                                                    ",
		"                                                  ��.�����˶�Ա�ɼ�                                              ",
		"                                                  ��.�޸��˶�Ա�ɼ�                                              ",
		"                                                  ��.ɾ���˶�Ա�ɼ�                                              ",
		"                                                  ��.�����˶�Ա�ɼ�                                              ",
		"                                                  ��.�鿴�ɼ����а�                                              ",
		"                                                  ��.��ӡ�˶��ᱨ��                                              ",
		"                                                  ��.�˳�                                                        ", };

		char key = 0;
		int t, select = 0;
		HANDLE ohandle = GetStdHandle(STD_OUTPUT_HANDLE);
		while (true)
		{

			headline();
			for (t = 0; t < 11; t++)
			{                 //���ﹲ10��ѡ��
				if (t == select)//���ý������
					SetConsoleTextAttribute(ohandle, FOREGROUND_GREEN);
				else if (t == select + 1 || t == select - 1 || t == select - 2 || t == select - 3 || t == select - 4 || t == select - 5 || t == select - 6 || t == select - 7 || t == select - 8 || t == select - 9 || t == select - 10)//||t==select-1||t==select-2||t==select-3||t==select-4||t==select-5||t==select-6||t==select-7||t==select-8||t==select-9||t==select-10)//�ָ�����
					SetConsoleTextAttribute(ohandle, FOREGROUND_RED | FOREGROUND_GREEN);
				puts(option[t]);
			}
			SetConsoleTextAttribute(ohandle, FOREGROUND_INTENSITY);//�ָ�����
			SetConsoleCursorPosition(hout, coord);
			SetConsoleTextAttribute(hout, FOREGROUND_RED);
			printf("\n");
			printf("%47s�T�T�T�T�T�T�T��ܰ��ʾ:�T�T�T�T�T�T�T\n%65s%66s%66s%94s", " ", "�ٰ�ESC���˳�����\n", "�ڰ��س���ִ�в���\n", "�ۡ����������ѡ��\n", "�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T\n");
			SetConsoleTextAttribute(ohandle, FOREGROUND_RED | FOREGROUND_GREEN);//�ָ�����

			key = getch();
			if (key == 0x1b)  //ESC ��
				exit(0);
			if (key == 0xd)  //Enter ��
				break;
			if (key < 0)
			{  //��ascii���2���ֽ�
				key = getch();

				switch (MapVirtualKey(key, 1))
				{
				case VK_UP:
					select = (select + 10) % 11;//�������ƣ���һ������ѡ�񣬹�4��ѡ��
					break;
				case VK_DOWN:
					select = (select + 1) % 11;//�������ƣ���һ
					break;

				}



			}

			system("cls");
		}



		switch (select)
		{
		case 0://��ʼ�� 
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
	printf("ѧ���˶������ϵͳ\n");
	printf("\n");
	time();
}

void time()
{
	SYSTEMTIME sys;
	printf("\n\n\t\t\t\t\t\t\t��ǰʱ��Ϊ��\n");
	GetLocalTime(&sys); //��ȡϵͳʱ�� 
	printf("\t\t\t\t\t\t\t\t%4d��-%02d��-%02d�� %02dʱ:%02d��:%02d��\n",
		sys.wYear, sys.wMonth, sys.wDay, sys.wHour, sys.wMinute,
		sys.wSecond, sys.wDayOfWeek); //������/��/�� ʱ/��/�� ���ڼ���ʽ��ӡ 
	return;
}
