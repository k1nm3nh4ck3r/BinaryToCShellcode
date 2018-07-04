#include <stdio.h>
#include <stdlib.h>

void toShellcode(char* filename, int size){
	FILE* fp = fopen(filename, "rb");
	int c, count = 0;
	printf("char* shellcode = \"");
	if(fp){
		while(!feof(fp)){
			c = fgetc(fp);
			if(c == -1){
				break;
			}
			if(count == size){
				printf("\"\\\n%*c\"", 18, ' ');
				count = 0;
			}
			printf("\\x%02X", c);
			count++;
		}
		fclose(fp);
	}
	printf("\";\n");
} 

int main(int argc, char *argv[]) {
	if(argc == 2){
		toShellcode(argv[1],10);
	}else if(argc == 3){
		toShellcode(argv[1],atoi(argv[2]));
	}else{
		printf("Usage:\n\t%s\t[filename]\n", argv[0]);
	}
	return 0;
}
