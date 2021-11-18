#include <stdio.h>
int i;
int main() {
	int flag = 0;
	char frame[8];
	FILE *f1, *f2;
	while(1) {
		f1 = fopen("file1.txt", "r");
		char ch = fgetc(f1);
		fclose(f1);
		if(ch == '1') {
			printf("\nDidn't received ACK in time.");
		}
		if(ch == '0') {
			printf((flag!=0)?"\nACK received\n":"");
			flag = 1;
			printf("\nEnter frame data: ");
			scanf("%s", frame);
			
			f2 = fopen("file2.txt", "w");
			fprintf(f2, "%s", frame);
			fclose(f2);

			f1 = fopen("file1.txt", "w");
			putc('1', f1);
			fclose(f1);
			Sleep(1000);
			printf("\nData sent Successfully!!!");
			Sleep(1000);
		}
	}
	return 0;
}

