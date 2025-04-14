 #include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

int main(){
	int src = open("source.txt",O_RDONLY);
	int dest = open("dest.txt",O_WRONLY |O_CREAT |O_TRUNC, 0644);

	if(src < 0 || dest < 0){
		perror("File open error");
		return 1;
	}
	char buffer[1024];
	ssize_t bytes;
	while((bytes = read(src,buffer,sizeof(buffer))) > 0){
		write(dest, buffer,bytes);
	}
	close(src);
	close(dest);
	return 0;
}

