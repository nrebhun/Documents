//	sine.p8		2011 feb 14
//
//	User is prompted for a float number;
//	this program computes (an approximation of)
//	the sine of that number of degrees.
//

{
	float n,s0,s1,t,x;
	int sign;

	input x;
	x = 3.141592653589793238462643383279*x/180.0;
	t = x;
	s1 = x;
	n = 1.0;
	sign = 1;
	while () {
		s0 = s1;
		n = n+2.0;
		t = t*x*x/(n*(n-1.0));
		sign = -sign;
		if ( 0 < sign ) {
			s1 = s1+t;
		} else {
			s1 = s1-t;
		}
		if ( s1 == s0 ) {
			break;
		}
	}
	output s1;
}
