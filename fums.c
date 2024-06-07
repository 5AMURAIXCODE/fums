#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "fums_strategy.h"

struct fums {
	const char *name;
	fums_strategy execute;
	char *help;

};

struct fums create_fums(char *name, fums_strategy fums_strategy, char *help) {
	struct fums *fums = malloc(sizeof *fums);
	if (fums != NULL) {
		fums->name = name;
		fums->execute = fums_strategy;
		fums->help = help;
	}
	return *fums;
}



