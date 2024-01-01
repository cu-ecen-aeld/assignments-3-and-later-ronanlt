#include <stdlib.h>
#include <stdio.h>
#include <syslog.h>
#include <errno.h>
#include <string.h>




int main (int argc, char *argv[] )
{

openlog(NULL,0,LOG_USER);
if (argc < 3)
{
    syslog(LOG_ERR, "missing argument (<2): %d", argc);
    fprintf(stderr, "missing argument: %d\n", errno);
    return 1;

} 
else
{
    char *WRITEFILE = argv[1];
    char *WRITESTR =  argv[2];
    printf("print argc: %d\n", argc);

    FILE *fp = fopen( WRITEFILE, "w");
    
    if (fp == NULL)
    {
    fprintf(stderr, "Value of errno attempting to open file %s: %d\n", WRITEFILE, errno);
    perror("perror returned");
    fprintf(stderr, "Error opening file %s: %s\n", WRITEFILE, strerror(errno));
    syslog(LOG_ERR, "file does not exist: %s", WRITEFILE);
    }
    else
    {
    fprintf(fp,"%s\n",WRITESTR);
    syslog(LOG_DEBUG, "Writing %s to file %s", WRITESTR, WRITEFILE);
    }

    fclose(fp);
    closelog();

return EXIT_SUCCESS;
}
}

