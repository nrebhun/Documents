//	fibs.p8		1996 apr 15	last modified 1997 mar 26
//
//	User is prompted for int n; fibonacci numbers fib[0] ... fib[n]
//	are computed and printed.
//

{
	int a,b,c,n;

	input n;
	a = -1;
	b = 1;
	repeat ( n+1 ) {
		c = a;
		a = b;
		b = b+c;
		output b;
	}
}
