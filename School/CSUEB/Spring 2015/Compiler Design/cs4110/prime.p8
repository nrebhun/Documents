//	prime.p8	1996 apr 12	last modified 1997 mar 26
//
//	Does this:
//		prompts user for int; reads int;
//		if int < 3, halts
//		else
//			if int is prime, prints n
//			else prints least positive divisor of n
//		then goes back to prompt.
//

{
	int d,n,p;

	while () {
		input n;
		if ( n < 3 ) {
			break;
		}
		if ( 2*(n/2) == n ) {
			output 2;
		} else {
			d = 3;
			p = n;
			while ( d*d <= n ) {
				if ( d*(n/d) == n ) {
					p = d;
					break;
				} else {
					d = d+2;
				}
			}
			output p;
		}
	}
}
