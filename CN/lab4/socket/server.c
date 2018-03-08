#include<stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<fcntl.h>
#define BUFLEN 500
int main(int argc,char** argv)
{
int n,fd,bytes_to_read;
int sd,new_sd,client_len,port;
struct sockaddr_in server,client;
char *bp,buf[BUFLEN];
switch(argc)
{
case 1:port=3000;
break;
case 2:port=atoi(argv[1]);
break;
default: fprintf(stderr,"usage:%s[port]\n",argv[0]);
exit(1);
}
sd=socket(AF_INET,SOCK_STREAM,0);
bzero((char *)&server,sizeof(struct sockaddr_in));
server.sin_family=AF_INET;
server.sin_port=htons(port);
server.sin_addr.s_addr=htonl(INADDR_ANY);
bind(sd,(struct sockaddr *)&server,sizeof(server));
listen(sd,5);
printf("listening\n");
while(1)
{
client_len=sizeof(client);
new_sd=accept(sd,(struct sockaddr *)&client,&client_len);
printf("after accept\n");
printf("newsd=%d\n",new_sd);
bp=buf;
bytes_to_read=BUFLEN;
while((n=read(new_sd,bp,bytes_to_read))>0)
{
bp+=n;
bytes_to_read-=n;
}
fd=open(buf,O_RDONLY);
if(fd<0)
{
strcpy(buf,"requested file does not exists \n");
write(new_sd,buf,BUFLEN);
exit(0);
}
while((n=read(fd,buf,BUFLEN))>0)
{
write(new_sd,buf,BUFLEN);
printf("the sending data:\n");
}
close(new_sd);
}
close(sd);
return(0);
}