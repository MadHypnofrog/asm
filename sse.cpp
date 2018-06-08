#include <stdio.h>
#include <emmintrin.h>
#include <string.h>

int count (char* string, int size) {
	int count = 0;
	for (int i = 0; i < size - 1; i++) {
		if (string[i] != ' ' && string[i + 1] == ' ') {
			count++;
		}
	}
	if (string[size - 1] != ' ') {
		count++;
	}
	return count;
}

int countSSE (char* string, int size) {
	__m128i blanks = _mm_set1_epi8((char) 32);
	int cnt = 0;
	int i = 0;
	while (size > 16) {
		__m128i str = _mm_cmpeq_epi8(_mm_loadu_si128((__m128i *) (string + i)), blanks);
		__m128i shift = _mm_cmpeq_epi8(_mm_loadu_si128((__m128i *) (string + i + 1)), blanks);
		__m128i diff = _mm_xor_si128(str, shift);
		int cur = __builtin_popcountll((unsigned long long) (reinterpret_cast<unsigned long long *> (&diff)[0])) +
                  __builtin_popcountll((unsigned long long) (reinterpret_cast<unsigned long long *> (&diff)[1]));
        	cnt += (cur / 8);
        	i += 16;
        	size -= 16;
	}
	if (i != 0) {
		if (string[0] != ' ') { 
			cnt++;
		}
		if (string[i - 1] != ' ' && string [i] != ' ') {
			cnt++;
		}
		if (string[i - 1] == ' ' && string[i] != ' ') {
			cnt--;
		}
	}

    cnt /= 2;

	if (i != 0 && string[i - 1] != ' ' && string[i] != ' ') {
        cnt--;
    }
	cnt += count(string + i, size);
	
	return cnt;
}

int main() {
    int n;
    char* tests[] = {"               ", //15 spaces
    		     "                ", //16 spaces
		     "                 ", //17 spaces
		     "111111111111111", //15x1 
		     "1111111111111111", //16x1 
		     "11111111111111111", //17x1
		     "1111111111111111 ", //space after a block of 16
		     "111111111111111 1", //space in the end of a block of 16
		     "11111111111111 1 ", //space in the end of & after a block of 16
		     "111111111111111 1 ", //space in the end of & after a block of 16
		     "1111111111111111 1111111111111111      1111111111111111 ", //spaces after blocks + uneven blocks
		     "    1111    1111    1111    11111", //blocks of 4
		     "1111    1111    1111    1111      1", //reversed
		     " 2 8r2832  23   wf w ef 23 2931u923 13 r 1    wfb s a   a g92  2 q 3r q3 t h5q        4wh5    q 3g q 34 t3  q3 y  45  25 q 2n   99 q9 9 9  3tq m qt  s h s    a g gare  g9es 2q4 0q2 2 q5 q3  32tq34tpoaerpg [[we]aW E       eg a 423   godgodgo    wer023 02 1 rrt33 5                       ", //random
		     "                                   1                                             1          ", //words far away from each other 
		     " 1 1 1 1 1 11 1 1 1 1  11 1 1  1 1 1 1 1 1 1  1 1 1 1 1  1 1 1 1  1 1 1  1 1 1 1  1 1 1  1111111111111111111111111111111111111111111111 1 1 1  1 111111111111111111111 1 1111111111111111111111111111111111111111111111111111111111111111111111111   11       ", //short + long sequences
		     "11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111", //long word, no breaks
		     "                                    111111111111111111111111111111111111111111111111111111                                          111111111111111111111111111111111111111111111111111                                                11111111111111111111111111111111111111111111111111", //long blocks of spaces and numbers 
    		     "                11                 ", //one word between two blocks
    		     };
    for (int i = 0; i < 19; i++) {
    	n = strlen(tests[i]);
    	printf ("Test #%i\n", (i + 1));
    	printf("Word count countSSE = %d\n", countSSE(tests[i], n));
    	printf("Expected word count = %d\n", count(tests[i], n));
    }
}
