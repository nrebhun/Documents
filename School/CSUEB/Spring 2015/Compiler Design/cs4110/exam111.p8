//	exam111.p8	2011 mar 13
//
//	For the 2011 Winter CS 4110 final exam.
//	Program inputs a number, computes and possibly prints something.
//

{
	int n,s,x;

	input n;
	if ( 0 < n ) {
		s = 0;
		x = 0;
		while ( x < n ) {
			x = x+1;
			s = s+x;
		}
		output n,s;
	}
}
