{	p1.pas		1989 dec 14	last modified 1994 jan 19
}

program p1;

  const
    c1       : array[1..13,1..9] of byte =
		       (( 1,12,12,12,12,12,12, 1, 0),
			(12, 2,12, 2, 2, 2, 2,12, 2),
			( 1,12,11,11,11,11,11, 1, 0),
			( 1,12,11,11,11,11,11, 1, 0),
			( 1,12,11,11,11,11,11, 1, 0),
			( 1,12,11,11,11,11,11, 1, 0),
			( 1,12,11,11,11,11,11, 1, 0),
			(12, 2, 1, 2, 2, 2, 2,13, 2),
			(12,12,14,14,14,14,14, 1, 0),
			(12,12,15, 0, 0, 0, 0, 0, 2),
			(12, 1,15, 1, 1, 0, 0, 0, 2),
			(12, 2,15, 2, 2, 1, 1, 0, 2),
			(12, 2,15, 2, 2, 2, 2, 0, 2));
    extrnal  : array[1..59] of byte =
			( 63, 63, 61, 43, 45, 42, 47, 65,
			  66, 67, 68, 69, 70, 71, 72, 73,
			  74, 75, 76, 77, 78, 79, 80, 81,
			  82, 83, 84, 85, 86, 87, 88, 89,
			  90, 97, 98, 99,100,101,102,103,
			 104,105,106,107,108,109,110,111,
			 112,113,114,115,116,117,118,119,
			 120,121,122);
    internal : array[0..127] of byte =
			( 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0,
			  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
			  0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 6, 4, 0, 5, 0, 7,
			  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0,
			  0, 8, 9,10,11,12,13,14,15,16,17,18,19,20,21,22,
			 23,24,25,26,27,28,29,30,31,32,33, 0, 0, 0, 0, 0,
			  0,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,
			 49,50,51,52,53,54,55,56,57,58,59, 0, 0, 0, 0, 0);
    jav      : array[60..75] of boolean =
			(true,true,true,true,true,true,true,true,
			 true,true,true,true,true,true,true,true);
    ln       : integer = 0;
    op       : array[1..7] of string[3] =
			('lod','sto','***','add','sub','mul','div');
    pr       : array[1..7] of byte = (0,1,2,3,3,4,4);
    top      : byte = 0;

  var
    done     : boolean;
    err      : boolean;
    inform   : array[1..240] of byte;
    l        : byte;
    rpn      : array[1..240] of byte;
    rpnl     : byte;
    s        : string[240];

  function atend : boolean;

    begin
      done:= (l = 3) and ((ord( s[1] ) or 32) = ord( 'e' ))
		     and ((ord( s[2] ) or 32) = ord( 'n' ))
		     and ((ord( s[3] ) or 32) = ord( 'd' ));
      atend:= done
    end;

  procedure deleteblanks;

    var
      i   : byte;
      len : byte;

    begin
      writeln( 'Deblanked string is:' );
      writeln;
      l:= 0;
      len:= length( s );
      for i:= 1 to len do
	if (s[i] <> ' ') and (s[i] <> chr( 9 )) then
	  begin
	    l:= l+1;
	    s[l]:= s[i]
	  end;
      s[0]:= chr( l );
      writeln( s );
      writeln
    end;

  procedure drawline;

    var
      i : byte;

    begin
      for i:= 0 to 78 do
	write( '_' );
      writeln
    end;

  procedure echoprint;

    begin
      writeln;
      writeln( 'Data string ',ln:1,' is:' );
      writeln;
      writeln( s );
      writeln
    end;

  procedure gencode;

    var
      a   : byte;
      i   : byte;
      j   : byte;
      l   : byte;
      lop : byte;
      n1  : byte;
      n2  : byte;
      t   : byte;

    procedure emit( a,n : byte );

      begin
	l:= l+1;
	write( l:5,op[a]:8 );
	if n < 60
	  then
	    writeln( chr( extrnal[n] ):6 )
	  else
	    begin
	      write( '     t.' );
	      if 60 < n then
		write( '+',n-60:1 );
	      writeln
	    end
      end;

    function nextj : byte;

      var
	j : byte;

      begin
	j:= 59;
	repeat
	  j:= j+1
	until jav[j];
	jav[j]:= false;
	nextj:= j
      end;

    procedure pop( var y : byte );

      begin
	y:= rpn[t];
	t:= t-1
      end;

    procedure push( x : byte );

      begin
	t:= t+1;
	rpn[t]:= x
      end;

    begin { gencode }
      writeln( 'Generated symbolic code is:' );
      writeln;
      l:= 0;
      lop:= 0;
      i:= 1;
      t:= 1;
      repeat
	i:= i+1;
	a:= rpn[i];
	if 3 < a then
	  if 7 < a
	    then
	      begin
		push( a );
		lop:= lop+1;
		if (lop = 2) and (0 < l) then
		  begin
		    j:= nextj;
		    pop( n1 );
		    pop( n2 );
		    push( j );
		    push( n2 );
		    push( n1 );
		    emit( 2,j )
		  end
	      end
	    else
	      begin
		n1:= lop;
		lop:= 0;
		if n1 = 1
		  then
		    begin
		      pop( n1 );
		      emit( a,n1 )
		    end
		  else
		    if 1 < n1
		      then
			begin
			  pop( n1 );
			  pop( n2 );
			  emit( 1,n2 );
			  emit( a,n1 )
			end
		      else
			begin
			  if (a = 4) or (a = 6)
			    then
			      begin
				pop( n1 );
				emit( a,n1 )
			      end
			    else
			      begin
				j:= nextj;
				jav[j]:= true;
				pop( n1 );
				emit( 2,j );
				emit( 1,n1 );
				emit( a,j )
			      end;
			  if 59 < n1 then
			    jav[n1]:= true
			end
	      end
      until a = 3;
      if l = 0 then
	emit( 1,rpn[2] );
      emit( 2,rpn[1] )
    end;  { gencode }

  procedure getstring;

    begin
      writeln( 'Enter a string, please:' );
      writeln;
      ln:= ln+1;
      readln( s );
    end;

  procedure internalize;

    var
      code  : byte;
      i     : byte;
      j     : byte;
      j0    : byte;
      j1    : byte;
      k     : byte;

    begin
      writeln( 'Internal form is:' );
      writeln;
      k:= 0;
      for i:= 1 to l do
	begin
	  code:= internal[ord( s[i] )];
	  inform[i]:= code;
	  if k+code = 0 then
	    k:= i;
	end;
      j1:= 0;
      for i:= 1 to (l+15) div 16 do
	begin
	  j0:= j1+1;
	  j1:= j1+16;
	  if l < j1 then
	    j1:= l;
	  for j:= j0 to j1 do
	    write( inform[j]:3 );
	  writeln
	end;
      err:= (0 < k);
      if err then
	begin
	  writeln;
	  writeln( '** ',k:1,'-th non-blank char <',s[k],'> is illegal. **' )
	end
    end;

  procedure makerpn;

    var
      done  : boolean;
      empty : boolean;
      i     : byte;
      n     : byte;
      s     : byte;
      stak  : array[1..80] of byte;

    procedure append( x : byte );

      begin
	rpnl:= rpnl+1;
	rpn[rpnl]:= x
      end;

    procedure pop( var y : byte );

      begin
	y:= stak[top];
	top:= top-1
      end;

    procedure push( x : byte );

      begin
	top:= top+1;
	stak[top]:= x
      end;

    begin { makerpn }
      writeln;
      writeln( 'RPN form is:' );
      writeln;
      rpnl:= 0;
      for i:= 1 to l do
	begin
	  s:= inform[i];
	  if 7 < s
	    then
	      append( s )
	    else
	      if s = 1
		then
		  push( s )
		else
		  begin
		    done:= false;
		    empty:= false;
		    repeat
		      if top = 0
			then
			  empty:= true
			else
			  begin
			    pop( n );
			    if pr[n] < pr[s]
			      then
				done:= true
			      else
				append( n )
			  end
		    until done or empty;
		    if empty
		      then
			push( s )
		      else
			if 3 < n+s then
			  begin
			    push( n );
			    push( s )
			  end
		  end
	end;
      while 0 < top do
	begin
	  pop( n );
	  append( n )
	end;
      for i:= 1 to rpnl do
	write( chr( extrnal[rpn[i]] ) );
      writeln;
      writeln
    end;  { makerpn }

  procedure parse;

    var
      a    : byte;
      eos  : boolean;
      errn : byte;
      i    : byte;
      ok   : boolean;
      out  : boolean;
      s    : byte;
      stak : array[1..80] of byte;
      t    : byte;

    procedure reduce;

      begin
	case s of
	  2 : if t < 3
		then
		  err:= true
		else
		  if (stak[t-1] <> 11) or (stak[t-2] <> 1)
		    then
		      err:= true
		    else
		      begin
			s:= 13;
			t:= t-2;
			stak[t]:= s
		      end;
	  8 : begin
		s:= 13;
		stak[t]:= s
	      end;
         10 : begin
		ok:= (eos and (t = 1));
		err:= not ok;
		out:= true
	      end;
         11 : if t < 3
		then
	 	  err:= true
		else
		  if (stak[t-1] <> 3) or (stak[t-2] <> 8)
		    then
		      err:= true
		    else
		      begin
			s:= 10;
			t:= t-2;
			stak[t]:= s
		      end;
         12 : if t < 3
		then
		  err:= true
		else
		  begin
		    s:= 11;
		    if ((stak[t-2] = s) and ((stak[t-1] = 4) or (stak[t-1] = 5)))
		      then
			t:= t-2
		      else
			stak[t]:= s
		  end;
         13 : if t < 3
		then
		  err:= true
		else
		  begin
		    s:= 12;
		    if ((stak[t-2] = s) and ((stak[t-1] = 6) or (stak[t-1] = 7)))
		      then
			t:= t-2
		      else
			stak[t]:= s
		  end;
	  else
	    err:= true
        end
      end;

    procedure shift;

      begin
	s:= a;
	t:= t+1;
	stak[t]:= s;
	out:= true
      end;

    begin { parse }
      if l < 3
	then
	  begin
	    writeln;
	    writeln( '** String is too short. **' );
	    err:= true
	  end
	else
	  begin
 	    eos:= false;
	    ok:= false;
	    errn:= 0;
	    i:= 0;
	    t:= 0;
	    s:= 9;
	    repeat
	      i:= i+1;
	      if l < i
		then
		  eos:= true
		else
		  begin
		    a:= inform[i];
		    if 8 < a then
		      a:= 8;
		    out:= false;
		    repeat
		      case c1[s,a] of
			1 : shift;
			2 : reduce;
			else
			  begin
			    err:= true;
			    errn:= c1[s,a]-10
			  end
		      end
		    until err or out
		  end
	    until eos or err;
	    if not err then
	      repeat
		reduce
	      until ok or err;
	    if err then
	      begin
		writeln;
		write( '** Illegal syntax' );
		if 0 < errn then
		  begin
		    case errn of
		      1 : write( ': operators are adjacent' );
		      2 : write( ': parenthesis is misplaced' );
		      3 : write( ': operands are adjacent' );
		      4 : write( ': must begin with letter' );
		      5 : write( ': second equal sign encountered' )
		    end;
		    write( ' - sigma = ',s:1,'; alpha = ',a:1 )
		  end;
		writeln( ' **' )
	      end
	  end
    end;  { parse }	

  begin { main }
    repeat
      getstring;
      echoprint;
      deleteblanks;
      if not atend then
	begin
	  internalize;
	  if not err then
	    begin
	      parse;
	      if not err then
		begin
		  makerpn;
		  gencode
		end
	    end;
	  drawline
	end
    until done
  end.	{ main }
