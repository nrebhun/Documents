//	harm.p8		1997 mar 09
//
//	Example p8 program.
//	Prompts user for (int) n; reads n.
//	If n < 0, prints -1.0;
//	else if n == 0, prints 0.0;
//	     else prints H[n] = 1 + 1/2 + 1/3 + ... + 1/n.
//

{
	float denom,h;				// both initialized to 0.0
	int n;					// initialized to 0; so what?

	input n;
	if ( n < 0 ) {
		h = -1.0;
	} else {
		if ( 0 < n ) {
			repeat ( n ) {
				denom = denom+1.0;
				h = h+1.0/denom;
			}
		}
	}
	output h;
}
