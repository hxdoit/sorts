#include "sorts.h"

/*********************************************/
/*交换两个数*/
void exchange(int *a,int*b)
{
	int temp=*a;
	*a=*b;
	*b=temp; 
}

/*********************************************/
/**通用插入排序,即选取数组中的部分元素进行插入排序**/
/**num：数组大小;start：从哪个数开始排序；step：步长**/
void common_insert_sort(int*p, int num, int start, int step)
{
	int i,j,temp;
	for(i=start+step;i<num;i+=step)
	{
		temp=p[i];
		for(j=i-step;j>=start;j-=step)
			if(p[j]>temp)
			{
				p[j+step]=p[j];
			}
			else
				break;
		if(j!=i-step)
			p[j+step]=temp;

	}
}
/*********************************************/
/**插入排序**/
void insert_sort(int*p, int num)
{
	common_insert_sort(p,num,0,1); 
}
/*********************************************/
/**希尔排序**/
void shell_sort(int*p, int num)
{
	int start,step;
	for(step=num/2;step>=1;step/=2)
		for(start=0;start<step;start++)
			common_insert_sort(p,num,start,step); 
}
/*********************************************/
/**冒泡排序**/
void bubble_sort(int*p, int num)
{
	int i,temp,last=num,set_last=0;
	while(last)
	{

		int last_loc=0;
		for(i=1;i<last;i++)
		{
			if(p[i]<p[i-1])
			{
				temp=p[i];
				p[i]=p[i-1];
				p[i-1]=temp;
				last_loc=i;
			}
		}
		last=last_loc;
	}

}
/*********************************************/
/**归并排序**/
/**合并已经有序的两个数组；即begin----mid和mid+1----end**/
void merge_sort_1(int*p, int begin, int mid, int end, int* buffer)
{
	if(end-begin<1)return;
	int i=begin, j=mid+1 ,k=0;
	while(i<=mid && j <=end)
	{
		if(p[i]<p[j])
			buffer[k++]=p[i++];
		else
			buffer[k++]=p[j++];
	} 
	if(i>mid)
		while(j<=end)
			buffer[k++]=p[j++];
	else if(j>end)
		while(i<=mid)
			buffer[k++]=p[i++];
	int m,n;
	for(m=0,n=begin;m<=end-begin;m++,n++)
		p[n]=buffer[m];
}
void merge_sort_0(int*p, int begin, int end, int*buffer)
{
	if(begin < end)
	{
		int mid=(begin+end)/2;
		merge_sort_0(p,begin,mid,buffer);
		merge_sort_0(p,mid+1,end,buffer);
		merge_sort_1(p,begin,mid,end,buffer);
	} 
}
void merge_sort(int*p, int num)
{
	int *buffer = (int*)malloc(sizeof(int)*num);
	merge_sort_0(p,0,num-1,buffer);
	free(buffer); 
}
/*********************************************/
/**堆排序**/
void adjust_heap(int*p, int index,int max)
{
	int target,left=2*index+1,right=left+1;
	if(right <= max)
	{ 
		//左右孩子都存在,找相对较大的
		if( p[left]>p[right])
			target=left;
		else 
			target=right;
	}
	else if(left==max)
	{
		//只有左孩子存在
		target=left;
	}
	else
	{
		return;
	}
	if(p[target]>p[index])
	{
		exchange(&p[target],&p[index]);
		adjust_heap(p,target,max);
	} 
}
void heap_sort(int*p, int num)
{
	int i;
	for(i=num/2-1;i>=0;i--)
		adjust_heap(p,i,num-1);
	for(i=num-1;i>0;i--)
	{
		exchange(&p[0],&p[i]);
		adjust_heap(p,0,i-1); 
	}
}

/*********************************************/
/**快速排序**/

void quick_sort_1(int*p, int begin, int end)
{
	if(begin>=end)return;
	int i = begin+1,j=end;
	while(i<j)
	{
		while(i<end && p[i]<=p[begin])i++; 
		while(j>begin && p[j]>=p[begin])j--; 
		if(i<j) 
		{
			exchange(&p[i],&p[j]); 
		}
	}
	if(p[begin]>p[j])
		exchange(&p[begin],&p[j]);
	quick_sort_1(p,begin,j-1); 
	quick_sort_1(p,j+1,end); 
}
void quick_sort(int*p, int num)
{
	quick_sort_1(p,0,num-1); 
}
/**********************************************/
/**找到前三名的字段**/
void find_top_n_1(int*p, int begin, int end, int n)
{
	if(begin>=end)return;
	int i = begin+1,j=end;
	while(i<j)
	{
		while(i<end && p[i]>=p[begin])i++; 
		while(j>begin && p[j]<=p[begin])j--; 
		if(i<j) 
		{
			exchange(&p[i],&p[j]); 
		}
	}
	if(p[begin]<p[j])
		exchange(&p[begin],&p[j]);
	if(end-begin==1 && n==1)
	{
		printf("%d\n",p[begin]);
		return;
	} 
	if(j-begin+1 > n)
		find_top_n_1(p,begin,j,n);
	else if(j-begin+1 == n)
	{
		int k;
		for(k=begin;k<=j;k++)
			printf("%d\n",p[k]);
	}
	else if(j-begin+1 < n)
        {
                
		int k;
		for(k=begin;k<=j;k++)
			printf("%d\n",p[k]);
		find_top_n_1(p,j+1,end,n-j+begin-1);
        }
}
void find_top_n(int*p, int num, int n)
{
	find_top_n_1(p,0,num-1,n); 
}

/**********************************************/
/**找到前三名的字段----用堆来实现**/
/**将一个堆调整为小根堆**/
void adjust_min_heap(int*p, int index,int max)
{
	int target,left=2*index+1,right=left+1;
	if(right <= max)
	{ 
		//左右孩子都存在,找相对较小的
		if( p[left]<p[right])
			target=left;
		else 
			target=right;
	}
	else if(left==max)
	{
		//只有左孩子存在
		target=left;
	}
	else
	{
		return;
	}
	if(p[target]<p[index])
	{
		exchange(&p[target],&p[index]);
		adjust_min_heap(p,target,max);
	} 
}

void find_top_n_min_heap(int*p, int num, int *n)
{
	//如果总的个数还不够
	if(num<=*n)
	{
		*n=num; 
		return;
	}

	int i;
	//将前n个数调整为小根堆
	for(i=*n/2-1;i>=0;i--)
		adjust_min_heap(p,i,*n-1);

	int j;
	for(j=*n;j<num;j++)
		if(p[j]>p[0])
		{
			exchange(&p[j],&p[0]);
			adjust_min_heap(p,0,*n-1);
		} 
}

/**************************************************/
/**KMP算法**/
/**给定一个字符串，获取其部分匹配值**/
int get_max_len(const char* search)
{
	int i,result=0;
	int len=strlen(search);
	char* copy1=(char*)malloc(2*(len+1));
	char* copy2=copy1+len+1;
	strcat(copy1, search);
	strcat(copy2, search);

	for(i=len-1;i>0;i--)
	{
		copy1[i]=0; 
		copy2++;
		if(strcmp(copy1,copy2)==0)
		{
			result=i;
			break;
		}
	}
	free(copy1);
	return result;
}

/**获取一个字符串的部分匹配表**/
int* prepare_rule(const char* search, int *length)
{
	int len=strlen(search);
	*length=len;
	char* copy=(char*)malloc(len+1);
	strcat(copy, search);
	int* result=(int*)malloc(sizeof(int)*len);

	while(len)
	{
		int temp=get_max_len(copy);
		result[--len]=temp;
		copy[len]=0; 
	}
	free(copy);
	return result;
}

int kmp(char* src, char* search)
{
	int len;
	int* rule=prepare_rule(search,&len);

	int loc=0, already_same=0;
	char* start=src;
	while(*start)
	{
		if(*start == search[loc])
		{
			loc++;
			if(++already_same == len)
				return start-src-len+1;
		}
		else
		{
			if(already_same)
				loc-=(already_same-rule[already_same-1]);
			already_same=0;
		} 
		start++;
	}
}























