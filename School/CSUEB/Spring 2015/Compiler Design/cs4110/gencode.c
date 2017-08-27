//	gencode.c		1997 may 12
//
//	The entire gencode() as copied from dan's p8.c.
//

void gencode( void ) {
	int nextr( void );
	void emit1( int ),emit2( int,int ),emit3( int,int,int );

	int l,r;

	switch ( row ) {
		case  0: if ( modes == 1 ) {
				if ( OP2 < 6 ) {
					emit3( 14,OP0,OP2 );
					rbu[OP2] = (char)0;
				} else {
					emit3( 14,0,OP2 );
					emit3( 14,OP0,0 );
				}
			} else {
				if ( sd ) {
					emit2( 34,OP0 );
					sd = 0;
				} else {
					emit2( 31,OP2 );
					emit2( 34,OP0 );
				}
			}
			break;
		case  1:
		case 35: if ( modes == 1 ) {
				if ( 100 <= OP2 ) {
					emit3( 14,0,OP2 );
				}
				fputs( "\tcall\t_outi\n",fpc );
				*rbu = (char)0;
				oui = (char)1;
			} else {
				if ( OP2 != 0 ) {
					emit2( 31,OP2 );
				}
				fputs( "\tcall\t_outf\n",fpc );
				sd = 0;					
				ouf = (char)1;
			}
			break;
		case  3:
		case 36: if ( modes == 1 ) {
				if ( 100 <= OP1 ) {
					emit3( 14,0,OP1 );
				}
				fputs( "\tcall\t_outi\n",fpc );
				*rbu = (char)0;
				oui = (char)1;
			} else {
				if ( OP1 != 0 ) {
					emit2( 31,OP1 );
				}
				fputs( "\tcall\t_outf\n",fpc );
				sd = 0;
				ouf = (char)1;
			}
			break;
		case  5: if ( bstop < brk ) {
				bug = 6;
			} else {
				*bstop |= 1;
				fprintf( fpc,"\tjmp\t_%d\n",*bstop >> 1 );
			}
			break;
		case  6: fputs( "\tret\n",fpc );
			break;
		case  7: fprintf( fpc,"_%d:\n",OP0 );
			OP0 = 0;
			break;
		case  9: if (alpha != 308 ) {			// else 
				fprintf( fpc,"_%d:\n",OP0 );
				OP0 = 0;
			} else {
				fprintf( fpc,"\tjmp\t_%d\n_%d:\n",++label,OP0 );
				OP0 = label;
			}
			break;
		case 10: fprintf( fpc,"\tjmp\t_%d\n",OP0 );
			OP0 = 0;
			break;
		case 11: label++;
			fprintf( fpc,"\tpop\teax\n\tdec\teax\n\tjle\t_%d\n"
				"\tjmp\t_%d\n_%d:\n",label,OP0,label );
			OP0 = 0;
			break;
		case 14:
		case 15: if ( modes == 1 ) {
				fputs( "\tcall\t_ini\n",fpc );
				emit3( 14,aux[top+16-row],0 );
				ini = (char)1;
			} else {
				fputs( "\tcall\t_inf\n",fpc );
				emit2( 34,aux[top+16-row] );
				inf = (char)1;
			}
			break;
		case 18: if ( modes == 1 ) {
				if ( OP1 < 6 ) {
					emit3( 3,OP1,OP3 );
					rbu[OP1] = (char)0;
					if ( OP3 < 6 ) {
						rbu[OP3] = (char)0;
					}
				} else {
					if ( OP3 < 6 ) {
						emit3( 3,OP1,OP3 );
						rbu[OP3] = (char)0;
					} else {
						emit3( 14,0,OP1 );
						emit3( 3,0,OP3 );
					}
				}
			} else {
				if ( (OP1 == 0) && (OP3 != 0) ) {
					emit2( 31,OP3 );
				}
				if ( (OP0 != 0) && (OP3 == 0) ) {
					emit2( 31,OP1 );
					emit1( 40 );
				}
				if ( (OP1 != 0) && (OP3 != 0) ) {
					emit2( 31,OP1 );
					emit2( 31,OP3 );
				}
				emit1( 26 );
				emit1( 35 );
				emit1( 18 );
				sd = 0;
			}
			fprintf( fpc,"\t%s\t_%d\n",inst[OP2],++label );
			fprintf( fpc,"\tjmp\t_%d\n",++label );
			fprintf( fpc,"_%d:\n",label-1 );
			OP0 = label;
			break; 
		case 19: if ( modes == 2 ) {
				bug = 5;
				break;
			} 
			if ( OP2 == 0 ) {
				*rbu = (char)0;
			} else {
				emit3( 14,0,OP2 );
			}
			fprintf( fpc,"_%d:\n\tpush\teax\n",++label );
			OP0 = label;
			break;
		case 20: label++;
			*++bstop = label+label;
			break;
		case 22: if ( modes == 1 ) {
				if ( OP0 < 6 ) {
					emit3( 0,OP0,OP2 );
					if ( OP2 < 6 ) {
						rbu[OP2] = (char)0;
					}
					break;
				}
				if ( OP2 < 6 ) {
					emit3( 0,OP2,OP0 );
					OP0 = OP2;
					break;
				}
				r = nextr();
				emit3( 14,r,OP0 );
				emit3( 0,r,OP2 );
				OP0 = r;
				break;
			}
			if ( (OP0 == 0) && (OP2 == 0) ) {
				emit1( 21 );
				--sd;
				break;
			}
			if ( 7 < sd ) {
				bug = 4;
				break;
			}
			if ( OP0 == 0 ) {
				emit2( 31,OP2 );
				emit1( 21 );
				break;
			}
			if ( OP2 == 0 ) {
				emit2( 31,OP0 );
				emit1( 21 );
				OP0 = 0;
				break;
			}
			if ( 7 < ++sd ) {
				bug = 4;
				break;
			}
			emit2( 31,OP0 );
			emit2( 31,OP2 );
			emit1( 21 );
			OP0 = 0;
			break;
		case 23: if ( modes == 1 ) {
				if ( OP0 < 6 ) {
					emit3( 19,OP0,OP2 );
					if ( OP2 < 6 ) {
						rbu[OP2] = (char)0;
					}
					break;
				}
				r = nextr();
				if ( OP2 < 6 ) {
					emit2( 17,OP2 );
					emit3( 14,OP2,OP0 );
					emit2( 16,r );
					emit3( 19,OP2,r );
					rbu[r] = (char)0;
					OP0 = OP2;
					break;
				}
				emit3( 14,r,OP0 );
				emit3( 19,r,OP2 );
				OP0 = r;
				break;
			}
			if ( (OP0 == 0) && (OP2 == 0) ) {
				emit1( 36 );
				--sd;
				break;
			}
			if ( 7 < sd ) {
				bug = 95;
				break;
			}
			if ( OP0 == 0 ) {
				emit2( 31,OP2 );
				emit1( 36 );
				break;
			}
			if ( OP2 == 0 ) {
				emit2( 31,OP0 );
				emit1( 38 );
				OP0 = 0;
				break;
			}
			if ( 7 < ++sd ) {
				bug = 4;
				break;
			}
			emit2( 31,OP0 );
			emit2( 31,OP2 );
			emit1( 36 );
			OP0 = 0;
			break;
		case 24: if ( modes == 1 ) {
				if ( OP1 < 6 ) {
					emit2( 15,OP1 );
					OP0 = OP1;
				} else {
					r = nextr();
					emit3( 14,r,OP1 );
					emit2( 15,r );
					OP0 = r;
				}
			} else {
				if ( OP1 == 0 ) {
					emit1( 23 );
					OP0 = 0;
				} else {
					if ( 8 < ++sd ) {
						bug = 4;
					} else {
						emit2( 31,OP1 );
						emit1( 23 );
						OP0 = 0;
					}
				}
			}
			mode[top] = (char)modes;
			break;
		case 26: if ( modes == 1 ) {
				if ( OP0 < 6 ) {
					if ( OP2 < 6 ) {
						rbu[OP2] = (char)0;
						switch ( OP0 ) {
							case 0: emit2( 6,OP2 );
								break;
							case 1:
							case 2: emit2( 17,0 );
								emit3(14,0,OP0);
								emit2( 6,OP2 );
								emit3(14,OP0,0);
								emit2( 16,0 );
								break;
							case 3: emit2( 17,0 );
								emit3(14,0,OP0);
								emit2( 6,OP2 );
								emit3(14,3,0);
								emit2( 16,0 );
								break;
							case 4: emit2( 17,0 );
								emit2( 17,3 );
								emit3( 14,0,4 );
								emit2( 6,OP2 );
								emit3( 14,4,0 );
								emit2( 16,3 );
								emit2( 16,0 );
								break;
							case 5: bug = 4;
						}
					} else {
						switch ( OP0 ) {
							case 0: emit2( 6,OP2 );
								break;
							case 1:
							case 2: emit2( 17,0 );
								emit3(14,0,OP0);
								emit2( 6,OP2 );
								emit3(14,OP0,0);
								emit2( 16,0 );
								break;
							case 3: emit2( 17,0 );
								emit3( 14,0,3 );
								emit2( 6,OP2 );
								emit3( 14,3,0 );
								emit2( 16,0 );
								break;
							case 4: 
							case 5: emit2( 17,0 );
								emit2( 17,3 );
								emit3(14,0,OP0);
								emit2( 6,OP2 );
								emit3(14,OP0,0);
								emit2( 16,3 );
								emit2( 16,0 );
						}
					}
				} else {
					if ( OP2 < 6 ) {
						switch ( OP2 ) {
							case 0: emit2( 6,OP0 );
								OP0 = 0;
								break;
							case 1:
							case 2: emit2( 17,0 );
								emit3(14,0,OP0);
								emit2( 6,OP2 );
								emit3(14,OP2,0);
								emit2( 16,0 );
								OP0 = OP2;
								break;
							case 3: emit2( 17,0 );
								emit3(14,0,OP0);
								emit2( 6,3 );
								emit3( 14,3,0 );
								emit2( 16,0 );
								break;
							case 4: 
							case 5: emit2( 17,0 );
								emit2( 17,3 );
								emit3(14,0,OP0);
								emit2( 6,OP2 );
								emit3(14,OP2,0);
								emit2( 16,3 );
								emit2( 16,0 );
						}
					} else {
						r = nextr();
						switch ( r ) {
							case 0: emit3(14,0,OP0);
								emit2( 6,OP2 );
								OP0 = 0;
								break;
							case 1:
							case 2:
							case 3: emit2( 17,0 );
 								emit3(14,0,OP0);
								emit2( 6,OP2 );
								emit3( 14,r,0 );
								emit2( 16,0 );
								OP0 = r;
								break;
							case 4:
							case 5: emit2( 17,0 );
								emit2( 17,3 );
								emit3(14,0,OP0);
								emit2( 6,OP2 );
								emit3( 14,r,0 );
								emit2( 16,3 );
								emit2( 16,0 );
								OP0 = r;
						}
					}
				}
				break;
			}
			if ( (OP0 == 0) && (OP2 == 0) ) {
				emit1( 32 );
				--sd;
				break;
			}
			if ( 7 < sd ) {
				bug = 4;
				break;
			}
			if ( OP0 == 0 ) {
				emit2( 31,OP2 );
				emit1( 32 );
				break;
			}
			if ( OP2 == 0 ) {
				emit2( 31,OP0 );
				emit1( 32 );
				OP0 = 0;
				break;
			}
			if ( 7 < ++sd ) {
				bug = 4;
				break;
			}
			emit2( 31,OP0 );
			emit2( 31,OP2 );
			emit1( 32 );
			OP0 = 0;
			break;
		case 27: if ( modes == 1 ) {
				if ( OP0 < 6 ) {
					if ( OP2 < 6 ) {
						rbu[OP2] = (char)0;
						switch ( OP0 ) {
							case 0: emit1( 2 );
								emit2( 5,OP2 );
								break;
							case 1:
							case 2: emit2( 17,0 );
								emit3(14,0,OP0);
								emit1( 2 );
								emit2( 5,OP2 );
								emit3(14,OP0,0);
								emit2( 16,0 );
								break;
							case 3: emit2( 17,0 );
								emit3( 14,0,3 );
								emit1( 2 );
								emit2( 5,OP2 );
								emit3( 14,3,0 );
								emit2( 16,0 );
								break;
							case 4: emit2( 17,0 );
								emit2( 17,3 );
								emit3( 14,0,4 );
								emit1( 2 );
								emit2( 5,OP2 );
								emit3( 14,4,0 );
								emit2( 16,3 );
								emit2( 16,0 );
								break;
							case 5: bug = 4;
						}
					} else {
						switch ( OP0 ) {
							case 0: emit1( 2 );
								emit2( 5,OP2 );
								break;
							case 1:
							case 2: emit2( 17,0 );
								emit3(14,0,OP0);
								emit1( 2 );
								emit2( 5,OP2 );
								emit3(14,OP0,0);
								emit2( 16,0 );
								break;
							case 3: emit2( 17,0 );
								emit3( 14,0,3 );
								emit1( 2 );
								emit2( 5,OP2 );
								emit3( 14,3,0 );
								emit2( 16,0 );
								break;
							case 4: 
							case 5: emit2( 17,0 );
								emit2( 17,3 );
								emit3(14,0,OP0);
								emit1( 2 );
								emit2( 5,OP2 );
								emit3(14,OP0,0);
								emit2( 16,3 );
								emit2( 16,0 );
						}
					}
				} else {
					if ( OP2 < 6 ) {
						switch ( OP2 ) {
							case 0: emit3( 14,1,0 );
								emit3(14,0,OP0);
								emit1( 2 );
								emit2( 5,1 );
								OP0 = 0;
								break;
							case 1:
							case 2: emit2( 17,0 );
								emit3(14,0,OP0);
								emit1( 2 );
								emit2( 5,OP2 );
								emit3(14,OP2,0);
								emit2( 16,0 );
								OP0 = OP2;
								break;
							case 3: emit2( 17,0 );
								emit3(14,0,OP0);
								emit1( 2 );
								emit2( 5,3 );
								emit3( 14,3,0 );
								emit2( 16,0 );
								OP0 = 3;
								break;
							case 4: 
							case 5: emit2( 17,0 );
								emit2( 17,3 );
								emit3(14,0,OP0);
								emit1( 2 );
								emit2( 5,OP2 );
								emit3(14,OP2,0);
								emit2( 16,3 );
								emit2( 16,0 );
								OP0 = OP2;
						}
					} else {
						r = nextr();
						switch ( r ) {
							case 0: emit3(14,0,OP0);
								emit1( 2 );
								emit2( 5,OP2 );
								OP0 = 0;
								break;
							case 1:
							case 2:
							case 3: emit2( 17,0 );
 								emit3(14,0,OP0);
								emit1( 2 );
								emit2( 5,OP2 );
								emit3( 14,r,0 );
								emit2( 16,0 );
								OP0 = r;
								break;
							case 4:
							case 5: emit2( 17,0 );
								emit2( 17,3 );
								emit3(14,0,OP0);
								emit1( 2 );
								emit2( 5,OP2 );
								emit3( 14,r,0 );
								emit2( 16,3 );
								emit2( 16,0 );
								OP0 = r;
						}
					}
				}
				break;
			}
			if ( (OP0 == 0) && (OP2 == 0) ) {
				emit1( 27 );
				--sd;
				break;
			}
			if ( 7 < sd ) {
				bug = 4;
				break;
			}
			if ( OP0 == 0 ) {
				emit2( 31,OP2 );
				emit1( 27 );
				break;
			}
			if ( OP2 == 0 ) {
				emit2( 31,OP0 );
				emit1( 29 );
				OP0 = 0;
				break;
			}
			if ( 7 < ++sd ) {
				bug = 4;
				break;
			}
			emit2( 31,OP0 );
			emit2( 31,OP2 );
			emit1( 27 );
			OP0 = 0;
			break;
		case 33: aux[top] = label;
			break;
		case 34: *++bstop = label+label+1;	// OP1 == label
			break;
		case 41: l = *bstop--;
			if ( l & 1 ) {
				fprintf( fpc,"_%d:\n",l >> 1 );
			}
			break;
		case 49:
		case 50:
		case 51:
		case 52: OP0 = (int)(modes == 1 ? comi[row-49] : comf[row-49]);
			break;
		default: printf( "** bad row [%d] in gencode **\n",row );
			exit( 1 );
	}
}
