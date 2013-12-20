#include "file.h" 
#include "sorts.h" 
#include <stdio.h> 


int main(int argc,char*argv[])
{
	int line_num=0;
	int *p= get_num_from_file(argv[1],&line_num); 
	struct timeval t1;
	gettimeofday(&t1,NULL);
	if(strcmp("insert_sort",argv[2])==0)
		insert_sort(p,line_num);
	else if(strcmp("shell_sort",argv[2])==0)
		shell_sort(p,line_num);
	else if(strcmp("bubble_sort",argv[2])==0)
		bubble_sort(p,line_num);
	else if(strcmp("quick_sort",argv[2])==0)
		quick_sort(p,line_num);
	else if(strcmp("merge_sort",argv[2])==0)
		merge_sort(p,line_num);
	else if(strcmp("heap_sort",argv[2])==0)
		heap_sort(p,line_num);
	else if(strcmp("find_top_n",argv[2])==0)
	{
		find_top_n(p,line_num, atoi(argv[3]));
	}
	else if(strcmp("get_max_len",argv[2])==0)
	{
		printf("%d\n",get_max_len(argv[3]));
		return 0;
	}
	else if(strcmp("kmp",argv[2])==0)
	{
		printf("%d\n", kmp(argv[3], argv[4]));
		return 0;
	}
	else if(strcmp("find_top_n_min_heap",argv[2])==0)
	{
		int top_n = atoi(argv[3]);
		find_top_n_min_heap(p,line_num,&top_n);
		int k;
		for(k=0;k<top_n;k++)
			printf("%d\n",p[k]);
	}
	struct timeval t2;
	gettimeofday(&t2,NULL);
	printf("%d\n",(t2.tv_sec-t1.tv_sec)*1000000+t2.tv_usec-t1.tv_usec);
	return 0;
	int i;
	for(i=0;i<line_num;i++)
		printf("%d\n",p[i]);
	return 0;
}
