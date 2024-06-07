#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "strategies.c"


struct fums curr;
// indicates the current stategy set


struct fums fb;
struct fums dr;
// add more here. Will be initialised in initStrats function

struct fums strats[2]; 
// make sure to increment the size of the array for each new strategy that you add


void printIntro() {
	printf("\n\nIntroducing...\n\n");
	char c;
	// Open file 
	FILE *fptr = fopen("asciiart.txt", "r"); 
	if (fptr == NULL) 
	{ 
		printf("Cannot open file \n"); 
		exit(0); 
	} 
	// Read contents from file 
	c = fgetc(fptr); 
	while (c != EOF) 
	{ 
		printf ("%c", c); 
		c = fgetc(fptr); 
	} 
	fclose(fptr); 

	printf("\nby 5amuraix\n");
	printf("\n\n\nNo joke, this is meant to f*** up your system\n\n");
	printf("Type 'help' to learn how to f*** up your system\n\n");
	return;
}



void list() {
	printf("\nfb - Fork Bomb - Descpition\ndr - Delete Root - rm -rf / \nfa - Fill All - Fill the whole system with junk and fill up the storage\nea - Encrypt All - Encrypt all file and delete the key\n\n"); 
}

void execute(char *cmd) {
	// remember curr is the current strategy
	if (strcmp(cmd,"fb") == 0) {
		printf("Are you sure you would like to choose death by forkbomb: y/n: ");
		char answer;
		scanf("%s" , &answer);
		if (strcmp(&answer,"y") == 0) {
			curr = createFbfums();
		}
	} else if (strcmp(cmd, "help") == 0) {

		printf("\nHere is some help\n");
		for(int i = 0; i < 2; i ++) { // CHANGE THE VALUE AS YOU ADD MORE; // TODO this ain't the sexiest. Maybe define a constant for this.
			//printf("%s\n", strats[i].help); // TODO
		}
	} else if (strcmp(cmd, "list") == 0) {
		list();
	}

	if(curr.name != NULL) {
		curr.execute();
	}

	return;
}

/// AUTHOR: JAS (yep, him, taken from 2017 1521 lab)
/// tokenise: split a string around a set of separators
/// create an array of separate strings
/// final array element contains NULL
static char **tokenise (const char *str_, const char *sep) {
        char **results  = NULL;
        size_t nresults = 0;

        // strsep(3) modifies the input string and the pointer to it,
        // so make a copy and remember where we started.
        char *str = strdup (str_);
        char *tmp = str;

        char *tok;
        while ((tok = strsep (&str, sep)) != NULL) {
                // "push" this token onto the list of resulting strings
                results = realloc (results, ++nresults * sizeof (char *));
                results[nresults - 1] = strdup (tok);
        }

        results = realloc (results, ++nresults * sizeof (char *));
        results[nresults - 1] = NULL;

        free (tmp);
        return results;
}

size_t strrspn (const char *str, const char *set) {
        size_t len;
        for (len = strlen(str); len != 0; len--)
                if (strchr(set, str[len]) == NULL)
                        break;
        return len;
}

static char *trim (char *str) {
        char *space = " \r\n\t";
        str[strrspn(str, space) + 1] = '\0'; // skip trailing whitespace
        str = &str[strspn (str, space)];      // skip leading whitespace
        return str;
}


void cli() {
	char line[BUFSIZ];
	printf("fums# ");
	while(fgets(line, BUFSIZ, stdin) != NULL) {
		trim(line);
		char **words = tokenise(line, " ");
		char *cmd = words[0];
		execute(cmd);
		printf("fums# ");
	}
}

void initStrats(){ 
	// add more here ... 
	dr = createDrfums();
	fb = createFbfums();
}


int main() {
	printIntro();
	initStrats();
	cli();
	return 1;
}
