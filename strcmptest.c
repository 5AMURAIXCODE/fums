
#include <string.h>
#include <stdio.h>

int main() {

	char *cmd = "cmd";
	char *input_cmd; 
	scanf("%s" ,input_cmd);

	int diff = strcmp(cmd,input_cmd);
	printf("diff : %d", diff);

	return 0;
}
