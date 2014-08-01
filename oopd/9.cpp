template <class eltype>
eltype * bubble(eltype inp[], int n)
{
	int v=0,swapped=1;
	eltype hand;
	
	while(swapped==1)
	{
		swapped=0;
		for(v=0;v<n-1;++v)
		{
			if(inp[v]<inp[v+1])
			{
				tmp=inp[v];
				inp[v]=inp[v+1];
				inp[v+1]=tmp;
				swapped=1;
			}
		}
	}
	return inp;
}


template <class eltype>
eltype * insertion(eltype inp[], int n)
{
	int i,j;
	eltype hand;
	
	for(i=1;i<n;i++)
	{
		hand=inp[i];
		j = i-1;
		while(hand<inp[j] && j>=0)
		{
			inp[j+1] = inp[j];
			j = j-1;
		}
		inp[j+1] = hand;
	}
	return inp;
}


template <class eltype>
eltype * merge_sort(eltype * m[])
[
	int i=0;	
	
	if (i<=1)
		return m;
	
	int middle=i/2;
	eltype left[middle],right[middle];
	
	for(i=0;i<middle;++i)
		left[i]=m[i];
	
	for(i=middle;m[i]!='\0';++i)
		right[i-middle]=m[i];
	
	merge_sort(left);
	merge_sort(right);
	
	return (merge(left,right));
}
template <class eltype>
void merge(eltype left[],eltype right[])
{
	int l,r,i=0,j=0;
	
	while(left[i]!='\0')
		++l;
	while(right[i]!='\0')
		++r;
	
	static eltype result[l+r];
	
	while(l>0 || r>0)
	{
		if(l>0 && r>0)
		{
			if(left[0]<=right[0])
			{
				result[i]=left[0];
				i++;
				j=0;
				while(left[j]!='\0')
					left[j]=left[j+1];
			}
			else
			{
				result[i]=right[0];
				i++;
				j=0;
				while(right[j]!='\0')
					right[j]=right[j+1];
			}
		}
		else if(l>0)
		{
			result[i]=left[0];
			i++;
			j=0;
			while(left[j]!='\0')
				left[j]=left[j+1];
		}
		else if(r>0)
		{
			result[i]=right[0];
			i++;
			j=0;
			while(right[j]!='\0')
				right[j]=right[j+1];
		}
	}
	result[i]='\0';
	return result;
}