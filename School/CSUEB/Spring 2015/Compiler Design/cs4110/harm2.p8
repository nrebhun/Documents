//	harm2.p8	1997 mar 15
//
//	User enters n; output shows H[n].
//	If n <= 100,000, computes H[n^2], an approximation of H[n^2],
//	and the error of the approximation.
//

{
	float approx,d,err,gamma,hn,hn2,n;

	input n;
	if ( n < 1.0 ) {
		output 0.0;
		return;
	}
	d = n;
	while ( d != 0.0 ) {
		hn = hn + 1.0/d;			// hn was initially 0
		d = d-1.0;
	}
	output hn;
	if ( n <= 100000.0 ) {
		gamma = 0.577215664901532860606512;
		approx = 2.0*hn - gamma - 1.0/n + 2.0/(3.0*n*n);
		d = n*n;
		while ( d != 0.0 ) {
			hn2 = hn2 + 1.0/d;		// hn2 was initially 0
			d = d-1.0;
		}
		err = hn2-approx;
		output hn2,approx,err,err/hn2;		// "exact", approx,
	}						//   err, and rel err
}
