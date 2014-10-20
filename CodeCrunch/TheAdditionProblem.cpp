/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
pair<string,ll> solve(string str, string str1)
{
	string ans="";
	int len=str.length(), len1=str1.length();
	if(len<len1)
	{
		for(int i=0;i<len1-len;++i)
			str='0'+str;
		len=len1;
	}
	else if(len>len1)
	{
		for(int i=0;i<len-len1;++i)
			str1='0'+str1;
		len1=len;
	}
	int carry=0;
	for(int i=len-1;i>=0;--i)
	{
		int tmp=str[i]-'0', tmp1=str1[i]-'0';
		int sum=(tmp^tmp1^carry)+'0';
		ans=(char)sum+ans;
		carry=(tmp&tmp1)|(tmp1&carry)|(carry&tmp);
	}
	if(carry)
		ans='1'+ans;
	ll int_ans=0;
	int ans_len=ans.length();
	ll pow_2=1;
	for(int i=ans_len-1;i>=0;--i)
	{
		int_ans=(int_ans+(ans[i]-'0')*pow_2)%MOD;
		pow_2=(pow_2*2)%MOD;
	}
	return make_pair(ans,int_ans);
}
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		string str,str1;
		cin>>str>>str1;
		pair<string,ll> ans=solve(str,str1);
		cout<<ans.first<<endl<<ans.second<<endl;
	}
	return 0;
}
