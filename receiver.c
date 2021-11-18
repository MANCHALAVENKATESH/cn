#include <stdio.h>
#include <malloc.h>
int i;
int main() {
	char * frame = (char*)malloc(9);
	FILE *f1, *f2;
	while(1) {
		f1 = fopen("file1.txt", "r");
		char ch = fgetc(f1);
		if(ch == '1') {
			f2 = fopen("file2.txt", "r");
			fscanf(f2, "%s", frame);
			fclose(f2);
	
			printf("\nData is ");
			puts(frame);
			f1 = fopen("file1.txt", "w");
			putc('0', f1);
			printf("Data Received Successfully!!!");
			Sleep(1000);
			printf("\nACK sent\n");
		}
		fclose(f1);
	}
	return 0;
}
