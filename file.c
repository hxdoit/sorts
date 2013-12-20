#include "file.h"
static unsigned int get_line_num(char *f)
{
        FILE*fr=fopen(f,"r");
        unsigned int num=0;
        while(!feof(fr))
                if(fgetc(fr)==10)
                        ++num;
        fclose(fr);
        return num;
}
int* get_num_from_file(char *f, int* num)
{
        int line_num=get_line_num(f);
        int*p = (int*)malloc(sizeof(int)*line_num); 
        int i=0;

        FILE *fp;
        char text[100];
        fp = fopen(f,"r");
        while(fgets(text,100,fp)!=NULL)
        {
                int a=0;
                sscanf(text,"%d",&a);
                p[i++]=a;
        }
        fclose(fp);

        *num=line_num;
        return p;
}
