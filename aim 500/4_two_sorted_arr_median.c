int min(int a,int b)
{
	if(a<=b)
		return a;
	else return b;
}

int two_sorted_arr_median(int *a,int len1,int *b,int len2)
{
	int count=0,flag,i=0,j=0,sum=0,flag1=0;
	if((len1+len2)%2==0)
		flag=1;
	else flag=0;
	while((count<(len1+len2)/2-1)&&i<len1&&j<len2)
	{
		if(a[i]<b[i])
		{
			i++;
			flag1=0;
		}
		else
		{
			flag1=1;
			j++;
		}
		count++;
	}
	if(count==(len1+len2)/2-1)
	{
		if(flag==1)
		{
			if(flag1==0)
			{
				return (a[i]+min(a[i+1],b[j]))/2;
				
			}
			else
			{
				return (b[j]+min(a[i]+b[j+1]))/2;
			 
			}

		}
		else 
		{
			return min(a[i],b[i]);
		}


	}
	else if(j==len2)
	{
		i+=((len1+len2)/2-1)-count;
		if(flag==1)
		{
			
			return (a[i]+a[i+1])/2);
		}
		else
		{
			return a[i+1];
		}

	}
	else
	{
		j+=((len1+len2)/2-1)-count;
		if(flag==1)
		{
			
			return (b[j]+b[j+1])/2);
		}
		else
		{
			return b[j+1];
		}

	}



}
