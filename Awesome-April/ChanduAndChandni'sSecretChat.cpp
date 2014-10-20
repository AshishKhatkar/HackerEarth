/*	ashish1610	*/
#include<bits/stdc++.h>
using namespace std; 
int main()
{
	int steps,len1,k,ind,t;
	char revstr1[10005], str1[10005];
	int arr[10005], hash[30];
	scanf("%d",&t);
	while(t--) 
	{
		
		scanf("%s",str1);
		scanf("%d",&ind);
		len1=strlen(str1);
		steps=len1-ind;
		ind=0;
		for(int i=len1-1;i>=0;i--)
		{
			revstr1[ind++]=str1[i];
		}
		revstr1[ind]='\0';
		memset(hash,0,sizeof(hash));
		for(int i=0;i<len1;++i)
			hash[(revstr1[i]-'a')]++;
		ind=0;
		for(int i=0;i<26;++i)
		{
			if(hash[i]>0)
			{
				for(int j=0;j<hash[i];++j) 
					str1[ind++]=char(i+'a');
			}
		}
		k=0;
		for(int i=0;i<26;++i) 
		{
			if(hash[i]>0)
			{
				ind=0;
				for(int j=0;j<hash[i];++j)
				{
					while(ind<len1)
					{
						if(revstr1[ind]==char(i+'a'))
							arr[k++]=ind;
						ind++;
					}
				}
			}
		}
		for(int i=0;i<len1;++i)
		{
			str1[i]=revstr1[steps];
			steps=arr[steps];
		}
		str1[len1]='\0';		
		puts(str1);
	}
	return 0;
} 
