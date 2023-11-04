#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <math.h>



 
#define BUF_SIZE 1024

char buf[BUF_SIZE];

int main(void)

{

FILE * p_file = NULL;

p_file = popen("ifconfig eth0", "r");

if (!p_file) {

fprintf(stderr, "Erro to popen");

}

while (fgets(buf, BUF_SIZE, p_file) != NULL) {

fprintf(stdout, "%s", buf);

}

pclose(p_file);

p_file = popen("touch test.tmp", "w");

if (!p_file) {

fprintf(stderr, "Erro to popen");

}

while (fgets(buf, BUF_SIZE, p_file) != NULL) {

fprintf(stdout, "%s", buf);

}

pclose(p_file);

p_file = popen("touch test.tmp", "w");

if (!p_file) {

fprintf(stderr, "Erro to popen");

}

pclose(p_file);

return 0;

}