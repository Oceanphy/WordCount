#include <stdio.h> 
#include <string.h>

int main(int argc, char *argv[]) {
	int i;
	int count;//���� 
	int ch;//��ȡ�ַ� 

	FILE* fp;
	fp = fopen(argv[2],"r");
	
	if(fp == NULL){
		printf("�ļ� %s ��ʧ��",argv[2]);
		fclose(fp);
	}else{
		//ͳ���ַ����͵����� 
		if (!strcmp(argv[1],"-c") || !strcmp(argv[1],"-C")) {	
			printf("����ͳ���ַ���\n"); 
			ch = fgetc(fp);
			count = 0;
			while (ch != EOF) {
				count ++;
				ch = fgetc(fp);
			}
			printf("�ַ�����%d",count);
		} else if (!strcmp(argv[1],"-w") || !strcmp(argv[1],"-W")) {	
			printf("����ͳ�Ƶ�����\n");
			ch = fgetc(fp);
			count = 1;
			while (ch != EOF) {
				if(ch == ',' || ch == ' '){
					count ++;
				}
				ch = fgetc(fp);
			}
			printf("��������%d",count);	
		}else{
			printf("����ָ�");
		} 
	}
	fclose(fp);
		
	return 0;
}
