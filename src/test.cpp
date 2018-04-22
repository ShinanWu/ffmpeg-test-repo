#include <stdio.h>
#include <string.h>
#define 	TEST_GLIBC "/home/shinan/share_dir/test_glibc"
int main(int argc, char const *argv[])
{
	//const char **command = argv;
	FILE *fd_test;
	char commmand_read[64];

	fd_test = fopen(TEST_GLIBC,"w");
	if(fd_test < 0){printf("open fail!\n");return -1 ;}
	fwrite(argv[1],sizeof(char),strlen(argv[1]),fd_test);
	fclose(fd_test);
	fopen(TEST_GLIBC,"rw");
    fread(commmand_read,sizeof(char),sizeof(commmand_read),fd_test);
    printf("command : %s\n",commmand_read);
	return 0;
}