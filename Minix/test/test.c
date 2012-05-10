#include <stdio.h>

int main(int argc, const char * argv){
	FILE * file = fopen("writer","w");
	fprintf(file, "test");
	return 0;
}
