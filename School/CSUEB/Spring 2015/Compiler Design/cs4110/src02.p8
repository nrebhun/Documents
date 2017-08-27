//	src02.p8	1996 apr 11	last modified 1997 mar 26
//
//	To check multiplying and dividing in p8.
//

{
	int a,b,c,d,e,f,g,h;

	a = b + c/d;
	a = b/c + d/e;
	a = b/c + (d/e + f/g);
	a = b/c + (d/e + (f/g + h/a));
	a = b/c + (d/e + (f/g + (h/a + b/c)));
}
