//	fib.p8		1996 aug 21
//
//	For the 1996 Summer CS 4110 final exam.
//	Prints the first few fibonacci numbers.
//

{
	int n,next,prev,temp;

	n = -1;
	prev = -1;
	next = 1;
	while ( n < 10 ) {
		n = n+1;
		temp = prev;
		prev = next;
		next = temp+next;
		output n,next;
	}
}
