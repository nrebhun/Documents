/*	lexa.c		2009 sep 30	last modified 2014 apr 02
 *
 *	Command line is >lexa <alphabet> n
 *		     or >lexa <alphabet> \"w
 *	In the first case shows w[n] in star of A where
 *	A* is ordered by size and lexicographically with e = w[0].
 *	In the second case shows n, where w[n] = "w".
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

	typedef unsigned int UINT;
	typedef unsigned long long ULL;

int
main( int argc,char **argv )
{
	ULL wton( UINT,const char *,const char * );
	UINT ok( const char *,const char * );
	void ntow( UINT,const char *,const char *,char * );

	UINT k;
	char *a,q[64],s[128],*u,*v;

	if ( argc != 3 ) {
		puts( "** use is >lexa <alphabet> n  or >lexa <alphabet> \\\"w **" );
		exit( 1 );
	}
	k = strlen( *++argv );
	a = *argv;
	for ( v = a;  *v;  v++ ) {
		for ( u = v;  *(++u); ) {
			if ( *v == *u ) {
				puts( "** duplicate char in alphabet **" );
				exit( 1 );
			}
		}
	}
	if (  **++argv != '\"' ) {
		ntow( k,a,*argv,s );
		printf( "w[%s] = \"%s\"\n",*argv,s );
	} else {
		if ( ok( a,*argv+1 ) ) {
			printf( "\"%s\" = w[%llu]\n",*argv+1,wton( k,a,*argv+1 ) );
		}
	}
	return( 0 );
}
UINT
ok( const char *a,const char *w )
{
	UINT y;
	const char *p,*q;
	char ch;

	for ( q = w;  *q != '\0';  q++ ) {
		ch = *q;
		for ( y = 0, p = a;  *p != '\0';  p++ ) {
			if ( ch == *p ) {
				y = 1;
				break;
			}
		}
		if ( y == 1 ) {
			continue;
		} else {
			printf( "** %c not in alphabet **\n",ch );
			exit( 1 );
		}
	}
	return( y );
}
void
ntow( UINT k,const char *a,const char *p,char *s )
{
	ULL n,q,r;
	UINT l;
	char *t;

	n = (ULL)0;
	while ( *p && isdigit( *p ) ) {
		n = (ULL)10*n+(ULL)((*p++)-'0');
	}
	for ( l = 0, q = (ULL)1, r = (ULL)k;  r-(ULL)1 <= n*(ULL)(k-1); ) {
		l++;
		q = r;
		r *= (ULL)k;
	}
//	printf( "-- l = %u; q = %llu; r = %llu --\n",l,q,r );
	t = s+l;
	*t-- = '\0';
	n -= (q-(ULL)1)/(ULL)(k-1);
	while ( s <= t ) { 
		*t-- = *(a+(UINT)(n % k));
		n /= (ULL)k;
	}
}
ULL
wton( UINT k,const char *p,const char *q )
{
	ULL n;
	UINT i;
	const char *r,*s;
	char ch;

	n = (ULL)0;
	for ( s = q;  *s != '\0';  s++ ) {
		ch = *s;
		for ( i = 1, r = p;  *r != ch;  r++, i++ ) {
			;
		}
		n = (ULL)k*n+(ULL)i;
	}
	return( n );	
}
