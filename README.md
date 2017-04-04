KMP & Boyer Moore Algorithm Lab
===============================

> two version of schemes of Boyer Moore algorithms and demo for python version libsvm loading


I have updated description in Wikipedia for readers to understand how it works. By refering to the project, 
you can get a deep sense of runtime performance of Boyer Moore algorithm.

The project provide robust codes for user to use them for research. Some micros have been added to illustrate how they work. Please refer to "ALGO\_DEMO" & "ALGO\_cursor". A global integer (C does not contain bool type) "debug" used for switch mutation of the illustration.

## KMP algorithms

## Boyer Moore
Boyer Moore is a little faster than KMP since it exclude more cases where there is no need to compare. Boyer Moore, however, not efficient for small chunk of string recognition. The algorithm widely used in various of programmes like "python split function".

Boyer Moore is developed in 

#### Rule 2: Good Suffix Rule
How to understand it?

In summary, by contrast "Good suffix rule" is very simple if one understand KMP algorithms well.
*Suppose the character 'c' in T where comparison fails at position i in pattern string P. The already matched string t must have the length of l = pttn\_len - i;*

1. Firstly, we can apply Bad Character Rule(BC) at position i (though we didn't record it in the previous one dimensional preprocessing table). Say for position i BC gives us position h or pttn\_len. Here we need BC rule which indicates (i, h) pair. Hence ideally we should need rl1\_t[pttn\_len][ALPHABET]

2. If we jump by aligning P with T at position of character 'c' at h (h < i): We want ask ourself , "shall we go further?" Then answer is yes on condition that:

    a. "exact copy of t preceded by 'c', say t', is NOT found.": jump until t'(can be empty) in P aligning with t' in T. Here we can check previous calculated Good Suffix Table directly for steps. Since 'c' is where mismatch occurs, it must satisfying "T[h+1..h+s] == T[pttn\_len-s, pttn\_len-1], where 0 < s < l, where T[h]=='c', might or might not equal to T[n-s], apparently not equal to T[i]!='c' ". Here we need Good Suffix Rule which indicates (h, s, i) tuple, i.e. L: rl2\_t[pttn\_len][pttn_len].

3. If we jump by passing the left end of P to the left end of t in T, i.e. no match of 'c' found, we can also move further

    a. There is plausible match (called in Boyer Moore paper) in T for the suffix in P starting from h+1. We must have:
        * T[h+1..h+l] == the suffix
        * T[h] should be equal to 'c', hence not equal to the character before the suffix
        * if there is more than one occurrence, always choose the right most one.

    b. There is no plausible match (we don't need to compare the character before the suffix). We can move on condition that there is a substring of t, which is also a prefix of the string.

> *That needs a much larger preprocessing table obviously, We have made our compromise. We first apply Bad Rule at only postion pttn\_len -1. The table needed is rl1[ALPHABET]. Second, according to 2.1, 3.1, 3.2 mentioned above. The only reason we need a two dimension table is to record (h, s, i) tuple to boost our searching. If we don't record h, a pair is ok since in rule 2.1 if T[h] == T[pttn-s-1], we can repeat the process util a first mismatch found (otherwise we can move to 3.1 and 3.2 directly). This is actually covered by 3.1 and 3.2. Boyer-Moore is not efficient for small string match, for too much preprocessing than KMP. However Boyer-Moore later proposed a specifically designed algorithms to tackle this problem.
In summary Good Suffix Rule covered by 3.1 and 3.2 using rl2\_t[pttn\_len].*


