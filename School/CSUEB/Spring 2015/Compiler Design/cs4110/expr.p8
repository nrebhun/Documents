//	expr.p8		1998 jun 03
//
//	Some complicated expressions in p8.
//

{
	int a,b,c,d,e,f,g,h,i,j;

	a = (b/c-d/e)/(f/g-h/i);
	a = (a/(b/c-d/e)-(f/g-h/i)/j)/(a/b/c/d);
	a = (a/b-c/d)*(e/f-g/h)/((i/j-a/b)/(c/d-e/f)-g/i/j);
}
