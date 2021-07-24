1:#include"iostream.h"

2:#include"iomanip.h"

3:

4:int main()

5:{

6: int i;

7: i = 500;

8: cout << "i base 10 =" << i ;

9: cout << endl;

10: cout << "i base 16 use hex =" << (hex) << i;

11: cout << endl;

12: cout << "i base 8 use oct =" << (oct) << i;

13: cout << endl;

14: cout << "i base 16 use setbase =" << setbase(16) << i;

15: cout << endl;

16: cout << "i base 8 use setbase =" << setbase(8) << i;

17: cout << endl;

18: cout << "Now i don't change base=" << i << endl;

19: cout << "i base 10 use setbase =" << setbase(10) << i;

20:

21: return 0;

22:}