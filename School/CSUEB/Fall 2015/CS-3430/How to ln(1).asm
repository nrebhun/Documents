#begin Routine to calculate ln(x) in MIPS assembly
#begin algorithm explanation 
# routine extracts the exponent of the floating point double saving it to be
# used later.
# The IEEE 754 floating point double format stores the number as a significand
# in the form 1.xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx times 
# 2^exponent where only the xs are kept (the one is hidden) and the exponent
# is kept in an excess 1023 form.
#
# this algorithm makes use of the fact that adding logs is equivalent to 
# multiplying the corresponding numbers.
# so ln(mantissa*2^exponent) = (exponent)*ln(2) + ln(mantissa)
# 
# To find the ln of the mantissa (between 1 and 2) use this series:
#
#                Ú   ¿2n+1
#         N   1  ³z-1³
# ln(z)= 2ä  ÄÄÄÄ³ÄÄÄ³      Where N < 16 
#        n=0 2n+1³z+1³
#                À   Ù
# Breaking this sum into an iterative code:
# double ln(double z){
#
# // for instance if z==50 ; Double will be 0x4049000000000000  the exponent 0x404 minus the excess 0x3ff is 5
# // the significand 0x9000000000000 means the mantissa is 1.5625 or 1+9/16 or 25/16 or 50/32 so 50/32x2^5 = 50.
# //since the log_base_2(b) is lg(b) is the exponent value then ln(b)= lg(b)*ln(2) = exp*ln(2) 
# // we will calculate the ln of 50/32 and then add 5*LN2;  ln(a*b) = ln(a)+ln(b)
#   double X,Z,ln,ln1,exp2,n;
#   int exp = extractExp(&z);//removes exponent from z      
#       //initialize
#       ln1= X = (z-1)/(z+1);  Z = X*X;  n = 1.0;                     
#       //iterate:
#       do {  
#          ln = ln1; n+=2.0; X *= Z; M = 1.0/n; ln1 = ln + M * X;
#       }while (ln1 != ln); //converges rapidly
#	//now correct for exponent!
#       exp2 = exp; //convert int to double
#       double LN2 = 0.69314718055994531;
#       return exp2 * LN2 + ln+ln;
# } 
#end algorithm explanation
# arguments:
# 	f12: input double
# returns:
#	f0: natural log double