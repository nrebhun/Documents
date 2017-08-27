//	bug03.p8	1996 mar 30	last modified 1996 apr 29
//
//	Observe that this program does not begin with '{'.
//	(Or end with '}'.)
//
	float a,big,k9dog;
	int integer;

	input a,big,k9dog;
	integer = 0;
	repeat ( 10 ) {
		big = big+a;
		k9dog = k9dog*(big-1.0);
		integer = integer+2;
	}
	output a,big,k9dog,integer-10;
