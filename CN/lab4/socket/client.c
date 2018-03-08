#include<stdio.h>
#include<stdlib.h>
#include<netdb.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define BUFLEN 500
int main(int argc,char **argv)
{
int n,bytes_to_read;
int sd,port;
struct hostent *hp;
struct sockaddr_in server;
char *host,*bp,rbuf[BUFLEN],sbuf[BUFLEN];
switch(argc)
{
case 2: host=argv[1];
port=3000;
break;
case 3: host=argv[1];
port=atoi(argv[2]);
break;
default:fprintf(stderr,"usage:%s[port]\n",argv[0]);
exit(1);
}
sd=socket(AF_INET,SOCK_STREAM,0);
printf("sd=%d",sd);
bzero((char *)&server,sizeof(struct sockaddr_in));
server.sin_family=AF_INET;
server.sin_port=htons(port);
if((hp=gethostbyname(host))==NULL)
{
fprintf(stderr,"can't get server address\n");
exit(1);
}
bcopy(hp->h_addr,(char *)&server.sin_addr,hp->h_length);
connect(sd,(struct sockaddr *)&server,sizeof(server));
printf("connected : server addr is: %s\n",hp->h_name);
printf("Enter the name of files to transmit:");
gets(sbuf);
write(sd,sbuf,BUFLEN);
printf("Recived a file Contents:\n");
bp=rbuf;
bytes_to_read=BUFLEN;
while((n=read(sd,bp,bytes_to_read))>0)
{
bp+=n;
bytes_to_read-=n;
printf("%s\n",rbuf);
}
close(sd);
return(0);
}