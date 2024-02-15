
int e(int n)

{
	int r=1;
	if (n==0 || n==1)
		return n;
	else 
		
	return e(n-1)+e(n-2);
}
