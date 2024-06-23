#include"students_system.h"

int main() {
	int choose = 1;//选择
	read();
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
		case 10:
			faid();
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
	sort_id();
	save();
	printf("\ngood bye~");
	return 0;
}

