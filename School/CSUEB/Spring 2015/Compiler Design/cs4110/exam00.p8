//	exam00.p8	1996 may 27
//
//	For the 1996 Spring CS 4110 final exam
//	Inputs integers until a negative entry is found; prints number
//	of ints, their sum, and the greatest int read.
//

{
	int max,n,s,x;

	max = 0;
	n = 0;
	s = 0;
	while () {
		input x;
		if ( x < 0 ) {
			break;
		}
		n = n+1;
		s = s+x;
		if ( max < x ) {
			max = x;
		}
	}
	output n,s,max;
}
