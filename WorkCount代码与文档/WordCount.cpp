#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int CountW(char *file)//�����ļ��ʵ���Ŀ 
{  
	FILE *fp;
    char buffer[5000];
    char c;
    int bufferlen=0;
    int LastComma = 0; // �ϸ��ַ��Ƿ��ǿո�򶺺�(1��ʾ��  0��ʾ����)
    int WordCount=0;
    int i;
    if((fp=fopen(file,"r"))==NULL)
	{
        printf("�ļ����ܴ�\n");
        exit(0);
    }
	while(fgets(buffer,1000,fp)!=NULL)
	{	
        bufferlen=strlen(buffer);
        for(i=0;i<bufferlen;i++)
		{
            c=buffer[i];
            if(c==' ' ||c==',')
			{
                if(LastComma==0)
				{
                    WordCount++;
                }
                LastComma=1;
            }
			else if(c!='\n'&&c!='\r')
			{
                LastComma=0;
            }
 
        } 
        if(LastComma==0)
            WordCount++;
        LastComma=1;
    }
    fclose(fp); 
		printf("��������%d ",WordCount);                     	
}
int CountC(char *file) //�����ļ����ַ��� 
	{   
		FILE *fp;
		int sum=0;
    	fp = fopen(file, "r");
    	char a[2000];
    	if(NULL==(fp=fopen(file,"r")))
    		{
        		printf("�ļ�Ϊ��");
        		return NULL;
    		}
    	 
    			fgets(a, 1024, fp);
				sum = strlen(a);
    		
    		
    	fclose(fp);
		printf("�ַ���:%d ",sum);//ͳ���ַ����� 
	}
	
int main(int argc, char* argv[])             
{
    if(!strcmp(argv[1],"-w")) 
      	 CountW(argv[2]);                
    else if(!strcmp(argv[1],"-c"))  
		 CountC(argv[2]);                
		 
        return 0;
}
