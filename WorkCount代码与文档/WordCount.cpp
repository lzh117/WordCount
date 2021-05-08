#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int CountW(char *file)//返回文件词的数目 
{  
	FILE *fp;
    char buffer[5000];
    char c;
    int bufferlen=0;
    int LastComma = 0; // 上个字符是否是空格或逗号(1表示是  0表示不是)
    int WordCount=0;
    int i;
    if((fp=fopen(file,"r"))==NULL)
	{
        printf("文件不能打开\n");
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
		printf("单词数：%d ",WordCount);                     	
}
int CountC(char *file) //返回文件的字符数 
	{   
		FILE *fp;
		int sum=0;
    	fp = fopen(file, "r");
    	char a[2000];
    	if(NULL==(fp=fopen(file,"r")))
    		{
        		printf("文件为空");
        		return NULL;
    		}
    	 
    			fgets(a, 1024, fp);
				sum = strlen(a);
    		
    		
    	fclose(fp);
		printf("字符数:%d ",sum);//统计字符数量 
	}
	
int main(int argc, char* argv[])             
{
    if(!strcmp(argv[1],"-w")) 
      	 CountW(argv[2]);                
    else if(!strcmp(argv[1],"-c"))  
		 CountC(argv[2]);                
		 
        return 0;
}
