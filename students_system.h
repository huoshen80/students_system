#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1001 //学生系统人数上限
void in_put();
void edit();
void shan();
void view();
void high();
void rank_10();
void load();
void insert();
void faid();

void sort_id();//学号排序
void sort_rank();//总分成绩排序
void sort_chi();//语文成绩排序
void sort_math();//数学成绩排序
void sort_eng();//英语成绩排序
void changestu(int k);//修改学生信息
void menu();//声明菜单函数
void read();//读取存储数据文件函数
void save();//保存数据文件函数
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
} ;


