t=input()
for i in range(0,t):
	inp=raw_input().split(" ")
	k=int(inp[0])
	n=int(inp[1])
	m=k**(n+1)
	m=m-1
	m=m/(k-1)
	ans=0
	while(m!=0):
		ans=ans+m%10;
		m/=10;
	print ans
