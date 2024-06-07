#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1001 //学生系统人数上限
void sort_id();//学号排序
void sort_rank();//总分成绩排序
void sort_chi();//语文成绩排序
void sort_math();//数学成绩排序
void sort_eng();//英语成绩排序
void changestu(int k);//修改学生信息
void menu();//声明菜单函数
int search_id();//声明查找学号函数
int search_name();//声明查找姓名函数
int search();//声明查找总函数


struct Stu {
	long int id;//学号
	char name[20];//学生姓名
	float chi_mark;//语文成绩
	float math_mark;//数学成绩
	float eng_mark;//英语成绩
	float sum;//总成绩
	float ave;//平均分
} stus[N];

int cnt = 0; //记录人数
int choose = 1;//选择

void in_put() { //插入学生信息函数
	while (1) {
		system("cls");
		printf("请输入学生的学号：\n");
		scanf("%ld", &stus[cnt].id);
		getchar();
		printf("请输入学生的姓名：\n");
		scanf("%s", stus[cnt].name);
		getchar();
		printf("请输入学生的语文成绩：\n");
		scanf("%f", &stus[cnt].chi_mark);
		getchar();
		printf("请输入学生的数学成绩：\n");
		scanf("%f", &stus[cnt].math_mark);
		getchar();
		printf("请输入学生的英语成绩：\n");
		scanf("%f", &stus[cnt].eng_mark);
		getchar();
		stus[cnt].sum = stus[cnt].chi_mark + stus[cnt].math_mark + stus[cnt].eng_mark;
		stus[cnt].ave = (stus[cnt].chi_mark + stus[cnt].math_mark + stus[cnt].eng_mark) / 3;
		++cnt;
		printf("是否继续输入数据？(y/n)\n");
		char ch;
		ch = getchar();
		if (ch == 'y') {
			continue;
		} else if (ch == 'n') {
			break;
		} else {
			printf("输入错误，返回主菜单\n");
			system("pause");
			break;
		}
	}

}

void edit() { //编辑学生信息函数
	char choice;
	int biao;
	while (1) {
		system("cls");
		getchar();
		biao = search();
		if (biao != N) {
			printf("请确认你要修改的学生是否如上所示(y/n)\n");
			getchar();
			choice = getchar();
			if (choice == 'y') {
				changestu(biao);
			} else if (choice == 'n') {
				printf("可能你输错了，请重试\n");
				system("pause");
			} else {
				printf("输入错误,请输入[y/n]\n");
				system("pause");
				continue;
			}
		} else if (biao == N) {
			continue;
		}
		system("cls");
		printf("是否继续修改其他学生信息(y/n):");
		char ch;
		getchar();
		scanf("%c", &ch);
		if (ch == 'y') {
			continue;
		} else {
			return;
		}
	}
}

void shan() {////删除学生信息函数
	char mych;
	int biao;
	while (1) {
		system("cls");
		getchar();
		biao = search();
		if (biao != N) {
			printf("是否确认删除[y/n]\n");
			getchar();
			mych = getchar();
			if (mych == 'y') {
				for (int i = biao; i < cnt; ++i) {
					stus[biao] = stus[biao + 1];
				}
				printf("删除成功！\n");
				--cnt;
				system("pause");
			} else if (mych == 'n') {
				printf("未能完成删除任务\n");
				system("pause");
			} else {
				printf("输入错误，请重新查询\n");
				system("pause");
				continue;
			}
		} else if (biao == N) {
			continue;
		}
		printf("是否继续删除(y/n)\n");
		char ch;
		getchar();
		ch = getchar();
		if (ch == 'y') {
			continue;
		} else if (ch == 'n') {
			break;
		}
	}
}

void view() {//总览学生信息函数
	char mych;
	system("cls");
	printf("是否启用按总分从高到低排名顺序[y/n]\n");
	getchar();
	mych = getchar();
	if (mych == 'y') {
		system("cls");
		printf("学生成绩总览表(总分排序)\n");
		sort_rank();
		printf("学号\t\t姓名\t\t语文成绩\t数学成绩\t英语成绩\t总分\t\t平均分\n");
		for (int j = 0; j < cnt; ++j) {
			printf("%ld\t\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n",
			       stus[j].id, stus[j].name, stus[j].chi_mark, stus[j].math_mark, stus[j].eng_mark, stus[j].sum, stus[j].ave);
		}
		system("pause");
	} else if (mych == 'n') {
		sort_id();
		system("cls");
		printf("学生成绩总览表\n");
		printf("学号\t\t姓名\t\t语文成绩\t数学成绩\t英语成绩\t总分\t\t平均分\n");
		for (int j = 0; j < cnt; ++j) {
			printf("%ld\t\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n",
			       stus[j].id, stus[j].name, stus[j].chi_mark, stus[j].math_mark, stus[j].eng_mark, stus[j].sum, stus[j].ave);
		}
		system("pause");
	} else {
		printf("输入错误，请重试\n");
		system("pause");
		view();
	}

}

void high() {//各学科最高分函数
	system("cls");
	sort_chi();
	printf("语文最高分学生：学号:%ld 姓名:%s 语文成绩:%.2f 数学成绩:%.2f 英语成绩:%.2f 总分:%.2f 平均分:%.2f\n",
	       stus[0].id, stus[0].name, stus[0].chi_mark, stus[0].math_mark, stus[0].eng_mark, stus[0].sum, stus[0].ave);
	sort_math();
	printf("数学最高分学生：学号:%ld 姓名:%s 语文成绩:%.2f 数学成绩:%.2f 英语成绩:%.2f 总分:%.2f 平均分:%.2f\n",
	       stus[0].id, stus[0].name, stus[0].chi_mark, stus[0].math_mark, stus[0].eng_mark, stus[0].sum, stus[0].ave);
	sort_eng();
	printf("英语最高分学生：学号:%ld 姓名:%s 语文成绩:%.2f 数学成绩:%.2f 英语成绩:%.2f 总分:%.2f 平均分:%.2f\n",
	       stus[0].id, stus[0].name, stus[0].chi_mark, stus[0].math_mark, stus[0].eng_mark, stus[0].sum, stus[0].ave);
	system("pause");
}

void rank_10() {//总分前十函数
	system("cls");
	sort_rank();
	printf("学号\t\t姓名\t\t语文成绩\t数学成绩\t英语成绩\t总分\t\t平均分\n");
	for (int j = 0; j < 10; ++j) {
		printf("%ld\t\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n",
		       stus[j].id, stus[j].name, stus[j].chi_mark, stus[j].math_mark, stus[j].eng_mark, stus[j].sum, stus[j].ave);
	}
	system("pause");
}

int search() {//查找总函数
	int choice;
	int biao;
	while (1) {
		system("cls");
		printf("请选择查找方式[1.学号/2.姓名](用数字1，2进行选择)\n");
		scanf("%d", &choice);
		if (choice == 1) {
			biao = search_id();
			break;
		} else if (choice == 2) {
			biao = search_name();
			break;
		} else {
			printf("输入错误请重试！[请输入1或2]\n");
			system("pause");
		}
	}
	return biao;
}

void load() { //初始化学生数据函数
	char temp[1000] = {0};
	int j;
	for (j = 0; j < 50; ++j) {
		itoa(j + 1, temp, 10);
		stus[j].id = 10001 + j;
		strcpy(stus[j].name, "学生_");
		strcat(stus[j].name, temp);
		stus[j].chi_mark = j;
		stus[j].math_mark = j + 1;
		stus[j].eng_mark = j + 2;
		stus[j].sum = stus[j].chi_mark + stus[j].math_mark + stus[j].eng_mark;
		stus[j].ave = (stus[j].chi_mark + stus[j].math_mark + stus[j].eng_mark) / 3;
		++cnt;
	}
	system("pause");
}

void insert() {//插入函数
	int biao;
	system("cls");
	sort_id();
	printf("学生成绩总览表\n");
	printf("[学号]\t\t姓名\t\t语文成绩\t数学成绩\t英语成绩\t总分\t\t平均分\n");
	for (int j = 0; j < cnt; ++j) {
		printf("%ld\t\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n",
		       stus[j].id, stus[j].name, stus[j].chi_mark, stus[j].math_mark, stus[j].eng_mark, stus[j].sum, stus[j].ave);
	}
	printf("可插入到输入的[学号]之前，请填写[学号]:\n");
	system("pause");
	biao = search_id();
	if (biao != N) {
		for (int i = cnt; i >= biao; --i) {
			stus[i + 1] = stus[i];

		}
		printf("请输入学生的学号：\n");
		scanf("%ld", &stus[biao].id);
		getchar();
		printf("请输入学生的姓名：\n");
		scanf("%s", stus[biao].name);
		getchar();
		printf("请输入学生的语文成绩：\n");
		scanf("%f", &stus[biao].chi_mark);
		getchar();
		printf("请输入学生的数学成绩：\n");
		scanf("%f", &stus[biao].math_mark);
		getchar();
		printf("请输入学生的英语成绩：\n");
		scanf("%f", &stus[biao].eng_mark);
		getchar();
		stus[biao].sum = stus[biao].chi_mark + stus[biao].math_mark + stus[biao].eng_mark;
		stus[biao].ave = (stus[biao].chi_mark + stus[biao].math_mark + stus[biao].eng_mark) / 3;
		printf("插入成功！\n");
		printf("插入的数据:\n");
		printf("学号\t\t姓名\t\t语文成绩\t数学成绩\t英语成绩\t总分\t\t平均分\n");
		printf("%ld\t\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n",
		       stus[biao].id, stus[biao].name, stus[biao].chi_mark, stus[biao].math_mark, stus[biao].eng_mark, stus[biao].sum, stus[biao].ave);
		++cnt;
		system("pause");
	} else if (biao == N)
		return;

}



int main() {
	do {
		menu();
		scanf("%d", &choose);
		switch (choose) {
			case 1:
				in_put();
				break;
			case 2:
				edit();
				break;
			case 3:
				shan();
				break;
			case 4:
				view();
				break;
			case 5:
				high();
				break;
			case 6:
				rank_10();
				break;
			case 7:
				search();
				break;
			case 8:
				load();//初始化学生数据
				break;
			case 9:
				insert();
				break;
			case 0:
				break;
			default : {
				printf("输入错误！请重试！");
				system("pause");
			}
		};
		system("cls");
	} while (choose);
	printf("\ngood bye~");
	return 0;
}

void sort_id() {//学号排序功能
	for (int k = 0; k < cnt - 1; k++) {
		for (int j = 0; j < cnt - k - 1; ++j) {
			if (stus[j].id > stus[j + 1].id) {
				struct Stu rank;
				rank = stus[j];
				stus[j] = stus[j + 1];
				stus[j + 1] = rank;
			}
		}
	}
}

void sort_rank() {//总成绩排序功能
	for (int k = 0; k < cnt - 1; k++) {
		for (int j = 0; j < cnt - k - 1; ++j) {
			if (stus[j].sum < stus[j + 1].sum) {
				struct Stu rank;
				rank = stus[j];
				stus[j] = stus[j + 1];
				stus[j + 1] = rank;
			}
		}
	}
}

void sort_chi() {//语文成绩排名功能
	for (int k = 0; k < cnt - 1; k++) {
		for (int j = 0; j < cnt - k - 1; ++j) {
			if (stus[j].chi_mark < stus[j + 1].chi_mark) {
				struct Stu rank;
				rank = stus[j];
				stus[j] = stus[j + 1];
				stus[j + 1] = rank;
			}
		}
	}
}

void sort_math() {//数学成绩排名功能
	for (int k = 0; k < cnt - 1; k++) {
		for (int j = 0; j < cnt - k - 1; ++j) {
			if (stus[j].math_mark < stus[j + 1].math_mark) {
				struct Stu rank;
				rank = stus[j];
				stus[j] = stus[j + 1];
				stus[j + 1] = rank;
			}
		}
	}
}

void sort_eng() {//英语成绩排名功能
	for (int k = 0; k < cnt - 1; k++) {
		for (int j = 0; j < cnt - k - 1; ++j) {
			if (stus[j].eng_mark < stus[j + 1].eng_mark) {
				struct Stu rank;
				rank = stus[j];
				stus[j] = stus[j + 1];
				stus[j + 1] = rank;
			}
		}
	}
}



void changestu(int k) {//修改学生成绩功能
	int mych;
	while (1) {
		printf("请选择你需要修改的部分:\n1.学号\n2.姓名\n3.语文成绩\n4.数学成绩\n5.英语成绩\n");
		scanf("%d", &mych);
		switch (mych) {
			case 1:
				getchar();
				printf("请输入学生的学号：\n");
				scanf("%ld", &stus[k].id);
				break;
			case 2:
				getchar();
				printf("请输入学生的姓名：\n");
				scanf("%s", stus[k].name);
				break;
			case 3:
				getchar();
				printf("请输入学生的语文成绩：\n");
				scanf("%f", &stus[k].chi_mark);
				break;
			case 4:
				getchar();
				printf("请输入学生的数学成绩：\n");
				scanf("%f", &stus[k].math_mark);
				break;
			case 5:
				getchar();
				printf("请输入学生的英语成绩：\n");
				scanf("%f", &stus[k].eng_mark);
				break;
			default:
				printf("输入错误，请按序号进行选择！\n");
				system("pause");
				break;
		}
		stus[k].sum = stus[k].chi_mark + stus[k].math_mark + stus[k].eng_mark;
		stus[k].ave = (stus[k].chi_mark + stus[k].math_mark + stus[k].eng_mark) / 3;
		printf("修改后的数据:\n");
		printf("学号\t\t姓名\t\t语文成绩\t数学成绩\t英语成绩\t总分\t\t平均分\n");
		printf("%ld\t\t%s\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n",
		       stus[k].id, stus[k].name, stus[k].chi_mark, stus[k].math_mark, stus[k].eng_mark, stus[k].sum, stus[k].ave);
		printf("是否继续修改该学生的信息(y/n)\n");
		char mych_1;
		getchar();
		scanf("%c", &mych_1);
		if (mych_1 == 'y') {
			continue;
		} else if (mych_1 == 'n') {
			return;
		} else {
			printf("输入错误，结束修改\n");
			system("pause");
			return;
		}
	}

}

void menu() {//菜单
	printf("*               ***********\n");
	printf("*               *\n");
	printf("*               *\n");
	printf("*               *\n");
	printf("*               *\n");
	printf("********        *********** \n");
	printf("*      *                  * \n");
	printf("*      *                  * \n");
	printf("*      *                  * \n");
	printf("*      *                  * \n");
	printf("*      *        *********** \n\n");//logo
	printf(">>**学生成绩管理系统**<< \n");
	printf("请选择下面的一项功能，输入0~9数字进行选择：\n");
	printf("1.学生成绩数据录入\n2.学生成绩数据修改\n3.学生成绩数据删除\n4.学生成绩总览\n5.查看各学科最高分\n6.查看总分前十\n7.查询学生信息\n8.初始化学生数据\n9.插入学生信息\n0.退出系统\n");
}

int search_id() {//查找学号功能
	long int f;
	int j;
	system("cls");
	printf("请输入你想要查找的学生学号\n");
	scanf("%ld", &f);
	for (j = 0; j < cnt; ++j) {
		if (f == stus[j].id) {
			printf("学号:%ld 姓名:%s 语文成绩:%.2f 数学成绩:%.2f 英语成绩:%.2f 总分:%.2f 平均分:%.2f\n", stus[j].id, stus[j].name, stus[j].chi_mark, stus[j].math_mark, stus[j].eng_mark, stus[j].sum, stus[j].ave);
			system("pause");
			break;
		}
	}
	if (f != stus[j].id) {
		printf("学号不存在，请重新输入\n");
		system("pause");
		return N;
	}
	return j;
}

int search_name() {//查找姓名功能
	char f[20];
	int j;
	system("cls");
	printf("请输入你想要查找的学生姓名\n");
	getchar();
	scanf("%s", f);
	for (j = 0; j < cnt; ++j) {
		if (strcmp(f, stus[j].name) == 0) {
			printf("学号:%ld 姓名:%s 语文成绩:%.2f 数学成绩:%.2f 英语成绩:%.2f 总分:%.2f 平均分:%.2f\n", stus[j].id, stus[j].name, stus[j].chi_mark, stus[j].math_mark, stus[j].eng_mark, stus[j].sum, stus[j].ave);
			system("pause");
			break;
		}
	}
	if (strcmp(f, stus[j].name) != 0) {
		printf("姓名不存在，请重新输入\n");
		system("pause");
		return N;
	}
	return j;
}


