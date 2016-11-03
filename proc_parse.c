#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void processorType(FILE *fp) //function for displaying CPU Model Name
{
	int j=0; //counter
	char buffer[128]; //buffer container for storing string from /proc/cpuinfo
	char *bf = buffer; //buffer pointer pointing towards buffer[0] 
	fp = fopen("/proc/cpuinfo", "r"); //file pointer pointing towards open file
	if(fp == NULL){
		printf("retrieve processor data failed");
		//if fp is not retrieved correctly, display error message
	}
	for(int i=0;i<5;i++) fgets(buffer, sizeof(buffer), fp); //fgets the string of the 5th row of /cpuinfo(CPU Model Name row) into buffer
	while(buffer[j++]!=':'){ //have the buffer pointer points to the spot after ':'
		bf++;
	}
	printf("CPU Model Name:			%s", ++bf);	//display CPU Model Name	
	fclose(fp);	//close
}

void kernelVersion(FILE *fp) //function for displaying Kernel Version
{
	char buffer[128]; //buffer container for storing string from /proc/version
	fp = fopen("/proc/version", "r"); //file pointer pointing towards open file
	if(fp == NULL){
		printf("retrieve kernel version data failed");
		//if fp is not retrieved correctly, display error message
	}
	fgets(buffer, sizeof(buffer), fp); //fgets the 1st row string of /version(Kernel Version) into buffer
	printf("Kernel Version:			 %s\n", buffer); //display Kernel Version
	fclose(fp); //close
}

void memoryAmount(FILE *fp) //function for displaying Main Memory Total
{
	char buffer[128]; //buffer container for storing string from /proc/meminfo
	char *bp = buffer; //buffer pointer pointing towards buffer[0] 
	fp = fopen("/proc/meminfo", "r"); //file pointer pointing towards open file
	if(fp == NULL){
		printf("retrieve memory amount data failed");
		//if fp is not retrieved correctly, display error message
	}
	fgets(buffer, sizeof(buffer), fp); //fgets the 1st row string of /meminfo(Main Memory Total) into buffer
	bp+=9; //have the buffer pointer points to bf+9
	printf("Main Memory Total:	 %s", bp); //display Main Memory Total
	fclose(fp); //close
}

void systemUptime(FILE *fp) //function for displaying Uptime
{
	char buffer[128]; //buffer container for storing string from /proc/uptime
	fp = fopen("/proc/uptime", "r"); //file pointer pointing towards open file
	if(fp == NULL){
		printf("retrieve system uptime data failed");
		//if fp is not retrieved correctly, display error message
	}
	fscanf(fp, "%s", buffer); //uses scanf instead of fgets for reading in the first word before a space apprearing into buffer
	printf("Uptime:				 %s Seconds\n", buffer); //display Uptime
	fclose(fp); //close
}

int main(void)
{
	FILE *fp; //declare file pointer
	processorType(fp);
	kernelVersion(fp);
	memoryAmount(fp);
	systemUptime(fp);	
	return 0;
}
