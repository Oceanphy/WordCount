#include <stdio.h> 
#include <string.h>

int main(int argc, char *argv[]) {
	int i;
	int count;//计数 
	int ch;//读取字符 

	FILE* fp;
	fp = fopen(argv[2],"r");
	
	if(fp == NULL){
		printf("文件 %s 打开失败",argv[2]);
		fclose(fp);
	}else{
		//统计字符数和单词数 
		if (!strcmp(argv[1],"-c") || !strcmp(argv[1],"-C")) {	
			printf("正在统计字符数\n"); 
			ch = fgetc(fp);
			count = 0;
			while (ch != EOF) {
				count ++;
				ch = fgetc(fp);
			}
			printf("字符数：%d",count);
		} else if (!strcmp(argv[1],"-w") || !strcmp(argv[1],"-W")) {	
			printf("正在统计单词数\n");
			ch = fgetc(fp);
			count = 1;
			while (ch != EOF) {
				if(ch == ',' || ch == ' '){
					count ++;
				}
				ch = fgetc(fp);
			}
			printf("单词数：%d",count);	
		}else{
			printf("错误指令！");
		} 
	}
	fclose(fp);
		
	return 0;
}
