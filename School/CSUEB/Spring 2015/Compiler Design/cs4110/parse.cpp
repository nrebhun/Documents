void parse()
{
	void reduce( char &,int & );
	int t;
	static char c1[13][9]={{ 1,11,11,11,11,11,11, 1, 0},
			       {11, 2,11, 2, 2, 2, 2,11, 2},
			       { 1,11,14,10,10,10,10, 1, 0},
			       { 1,11,10,10,10,10,10, 1, 0},
			       { 1,11,10,10,10,10,10, 1, 0},
			       { 1,11,10,10,10,10,10, 1, 0},
			       { 1,11,10,10,10,10,10, 1, 0},
			       {11, 2, 1, 2, 2, 2, 2,12, 2},
			       {11,11,13,13,13,13,13, 1, 0},
			       {11,11, 0, 0, 0, 0, 0, 0, 2},
			       {11, 1, 0, 1, 1, 0, 0, 0, 2},
			       {11, 2, 0, 2, 2, 1, 1, 0, 2},
			       {11, 2, 0, 2, 2, 2, 2, 0, 2}},
		*ermsg[]={": operators are adjacent",
			  ": parenthesis is misplaced",
			  ": operands are adjacent",
			  ": must begin with letter",
			  ": second equal sign encountered"};
	char a,*p,s;
	if ( len < 3 ) {
		cout << "\n** String is too short. **\n";
		err = 1;
		return;
	}
	t = -1;
	err = eos = ok = 0;
	s = 9;
	p = inform;
	do {
		if ( (a = *p++) == '\0' ) {
			eos = 1;
		} else {
			if ( 8 < a ) {
				a = 8;
			}
			out = 0;
			do { 
				switch ( c1[s-1][a-1] ) {
					case 1: stak[++t] = s = a;    // shift
						out = 1;
						break;
					case 2:	reduce( s,t );
						break;
					default: err = c1[s-1][a-1]-8;
				}
			} while ( !err && !out );
		}
	} while ( !eos && !err );
	if ( !err ) {
		do {
			reduce( s,t);
		} while ( !ok && !err );
	}
	if ( err ) {
		cout << "\n** Illegal syntax";
		if ( 1 < err ) {
			cout << ermsg[err-2] << " - sigma = " << (int)s
			     << ", alpha = " << (int)a;
		}
		cout << " **\n";
	}
}
void
reduce( char & s,int & t )
{
	switch ( s ) {
		case  2: if ( t < 2 ) {
				err = 1;
			} else {
				if ( (stak[t-1] != 11) || (stak[t-2] != 1) ) {
					err = 1;
				} else {
					stak[t -= 2] = s = 13;
				}
			}
			break;
		case  8: stak[t] = s = 13;
			break;
		case 10: err = !(ok = (eos && (t == 0)));
			out = 1;
			break;
		case 11: if ( t < 2 ) {
				err = 1;
			} else {
				if ( (stak[t-1] != 3) || (stak[t-2] != 8) ) {
					err = 1;
				} else {
					stak[t -= 2] = s = 10;
				}
			}
			break;
		case 12: if ( t < 2 ) {
				err = 1;
			} else {
				s = 11;
				if ( (stak[t-2] == s) &&
					((stak[t-1] == 4) ||
					(stak[t-1] == 5)) ) {
					t -= 2;
				} else {
					stak[t] = s;
				}
			}
			break;
		case 13: if ( t < 2 ) {
				err = 1;
			} else {
				s = 12;
				if ( (stak[t-2] == s) &&
					((stak[t-1] == 6) ||
					(stak[t-1] == 7)) ) {
					t -= 2;
				} else {
					stak[t] = s;
				}
			}
			break;
		default: err = 1;
	}
}
