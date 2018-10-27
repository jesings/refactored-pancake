#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
int main(){
    int devrandom = open("/dev/random",O_RDONLY);
    int randbuf[10];
    read(devrandom,randbuf,sizeof(int)*10);
    close(devrandom);
    for(int i = 0;i<10;i++) printf("Read random number %d = %d\n",i,randbuf[i]);
    int writefile = open("vigilant.bassoon",O_RDWR | O_CREAT);
    write(writefile,randbuf,sizeof(int)*10);
    int readbuf[10];
    pread(writefile,readbuf,sizeof(int)*10,0);
    close(writefile);
    for(int i = 0;i<10;i++) printf("Read then written then read random number %d = %d\n",i,readbuf[i]);
    return 0;
}
