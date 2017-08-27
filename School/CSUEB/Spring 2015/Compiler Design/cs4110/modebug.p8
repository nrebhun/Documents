//	modebug.p8	1996 apr 02	last modified 1996 apr 29
//
//	Modified from sqrt.p8; this has a mixed modes bug in line 54.
//	Sample p8 program.  Compare sqrt0.c and cksqrt0.c.
//	Do this:
//		read (float) number a;		// no prompt given
//			if a < 0, then exit;
//			else compute the square root y of a;
//			output shows: a  y  0.5*(a-y*y)/a;
//	until input data a < 0.
//
//	We use here the optimal linear approximation on [1,4].
//	If 0 < a and we let r = (sqrt(a)-y)/sqrt(a) and s = (a-y*y)/a,
//	then always: r = s/2 + r**2/2; also |r| <= |s|,
//	and  0 <= s ==> 0 <= s/2 <= r <= s, whereas
//	     s <  0 ==> r <  0 but |r| <= |s|/2.
//	Also: 0 < y ==> s/2 <= r <= 1/(1-s)*s/2
//	I.e., s/2 is a very good approximation of r, the relative error.
//

{
	float a,m,p,x,y,z;
	int r;					// 1 iff 0 < a < 1

	m = 0.3432945239845196;			// (18)**(1/4)/6
	while ( 1 == 1 ) {			// endless loop
		input a;
		if ( a < 0.0 ) {		// exit condition
			break;
		}
		if ( a == 0.0 ) {		// exceptional case
			output a, 0.0, 0.0;
		} else {
			if ( 1.0 <= a ) {
				r = 0;		// 1 <= a (big)
				z = a;		// 1 <= z = a
			} else {
				r = 1;		// 0 < a < 1 (small)
				z = 1.0/a;	// 1 < z = 1/a
			}
			x = 1.0;		// find int x such that
			y = 2.0;		//  x**2 <= z < (2x)**2
			p = 4.0;
			while ( p <= z ) {	// [log4(z)]+1 comps
				x = y;		// This loop done 
				y = y+y;	//  [log4(z)]
				p = 4.0*p;	//  times.
			}
			y = m*(z/x + y);	// init. approx
			if ( r != 0 ) {		// small a,	
				y = 1.0/y;	//  so invert
			}
			repeat ( 4 ) {
				y = (y + a/y)/2;	// newton's
			}
			output a, y, 0.5*(a - y*y)/a;	// est of relerr
		}
	}
	return;
}
