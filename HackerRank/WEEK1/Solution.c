1.PLUS_MINUS 
 #include <stdio.h>

void plusMinus(int arr[], int n) {
    int positive = 0, negative = 0, zero = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0)
            positive++;
        else if (arr[i] < 0)
            negative++;
        else
            zero++;
    }

    
    printf("%.6f\n", (float)positive / n);
    printf("%.6f\n", (float)negative / n);
    printf("%.6f\n", (float)zero / n);
}

int main() {
    int n;

    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    
    plusMinus(arr, n);

    return 0;
}

2.MIN_MAX
#include <stdio.h>

int main() {
    int arr[5];
    int i;
    long sum = 0;
    int min, max;

    for (i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
        sum = sum + arr[i];
    }

    min = arr[0];
    max = arr[0];

    for (i = 1; i < 5; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    long minSum = sum - max;
    long maxSum = sum - min;

    printf("%ld %ld\n", minSum, maxSum);

    return 0;
}

3.Time_Conversion
#include <stdio.h>
#include <string.h>

char* timeConversion(const char* s) {
    static char out[9];            
    int hh = (s[0]-'0')*10 + (s[1]-'0');
    int isPM = (s[8] == 'P');      

    if (isPM) {
        if (hh != 12) hh += 12;
    } else {
        if (hh == 12) hh = 0;
    }

    out[0] = '0' + (hh / 10);
    out[1] = '0' + (hh % 10);
    out[2] = s[2];                 
    out[3] = s[3];
    out[4] = s[4];
    out[5] = s[5];                 
    out[6] = s[6];
    out[7] = s[7];
    out[8] = '\0';
    return out;
}

int main(void) {
    char s[32];
    if (!fgets(s, sizeof s, stdin)) return 0;

    size_t n = strlen(s);
    if (n && s[n-1] == '\n') s[n-1] = '\0';  

    printf("%s\n", timeConversion(s));

4.Sparse_array
#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 100   // Maximum length of each string

void matchingStrings(char strings[][MAX_STR_LEN], int n, 
                     char queries[][MAX_STR_LEN], int q, int result[]) {
    for (int i = 0; i < q; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (strcmp(queries[i], strings[j]) == 0) {
                count++;
            }
        }
        result[i] = count;
    }
}

int main() {
    int n, q;
    char strings[1000][MAX_STR_LEN];
    char queries[1000][MAX_STR_LEN];
    int result[1000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", strings[i]);
    }
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%s", queries[i]);
    } 
    matchingStrings(strings, n, queries, q, result);
    for (int i = 0; i < q; i++) {
        printf("%d\n", result[i]);
    }
    return 0;
}


5.Lonely_Integer
#include <stdio.h>

int lonelyinteger(int a[], int n) {
    int result = 0;
    for (int i = 0; i < n; i++) {
        result ^= a[i];  // XOR each element
    }
    return result;
}

int main() {
    int n;
    int a[1000];

    
    scanf("%d", &n);

    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

   
    printf("%d\n", lonelyinteger(a, n));

    return 0;
}

6.Flipping_Bits
#include <stdio.h>

unsigned int flippingBits(unsigned int n) {
    return ~n;  // Bitwise NOT flips all bits
}

int main() {
    int q;
    unsigned int n;

    scanf("%d", &q); 

    for (int i = 0; i < q; i++) {
        scanf("%u", &n); 
        printf("%u\n", flippingBits(n));
    }

    return 0;
}

7.Diagonal_Difference
#include <stdio.h>
#include <stdlib.h> // for abs()

int diagonalDifference(int arr[100][100], int n) {
    int primarySum = 0;
    int secondarySum = 0;

    for (int i = 0; i < n; i++) {
        primarySum += arr[i][i];           
        secondarySum += arr[i][n - 1 - i]; 
    }

    return abs(primarySum - secondarySum);
}

int main() {
    int n;
    int arr[100][100];

    scanf("%d", &n);

   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

   
    printf("%d\n", diagonalDifference(arr, n));

    return 0;
}

8.Counting_sort
#include <stdio.h>

int main() {
    int n;
    int arr[100];  // input array
    int count[100] = {0};  

    scanf("%d", &n);

    
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        count[value]++;
    }

    for (int i = 0; i < 100; i++) {
        printf("%d ", count[i]);
    }
    printf("\n");

    return 0;
}


9.Pangrams
#include <stdio.h>

int main() {
    int n;
    int arr[100];  // input array
    int count[100] = {0};  

    scanf("%d", &n);

    
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        count[value]++;
    }

    for (int i = 0; i < 100; i++) {
        printf("%d ", count[i]);
    }
    printf("\n");

    return 0;
}

10.Permuting_2arrays
 #include <stdio.h>
#include <ctype.h>
#include <string.h>

char* pangrams(char s[]) {
    static char result[20];
    int letters[26] = {0};  // to track each alphabet letter
    int count = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (isalpha(s[i])) { // check if character is a letter
            char lower = tolower(s[i]);
            int index = lower - 'a';
            if (letters[index] == 0) {
                letters[index] = 1;
                count++;
            }
        }
    }

    if (count == 26) {
        strcpy(result, "pangram");
    } else {
        strcpy(result, "not pangram");
    }

    return result;
}

int main() {
    char s[1000];

    // Read entire line including spaces
    fgets(s, sizeof(s), stdin);

    // Remove newline if present
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }

    printf("%s\n", pangrams(s));

    return 0;
}

11.Sub_Array 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compareAsc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b); // ascending order
}

int compareDesc(const void *a, const void *b) {
    return (*(int*)b - *(int*)a); // descending order
}

char* twoArrays(int k, int A[], int B[], int n) {
    static char result[4];

    // Sort A in ascending order
    qsort(A, n, sizeof(int), compareAsc);

    // Sort B in descending order
    qsort(B, n, sizeof(int), compareDesc);

    // Check if A[i] + B[i] >= k for all i
    for (int i = 0; i < n; i++) {
        if (A[i] + B[i] < k) {
            strcpy(result, "NO");
            return result;
        }
    }

    strcpy(result, "YES");
    return result;
}

int main() {
    int q;
    scanf("%d", &q);

    while (q--) {
        int n, k;
        int A[1000], B[1000];

        scanf("%d %d", &n, &k);

        for (int i = 0; i < n; i++) scanf("%d", &A[i]);
        for (int i = 0; i < n; i++) scanf("%d", &B[i]);

        printf("%s\n", twoArrays(k, A, B, n));
    }

    return 0;
}

12. #include <stdio.h>

int birthday(int s[], int n, int d, int m) {
    int ways = 0;

    // Loop over each starting position
    for (int i = 0; i <= n - m; i++) {
        int sum = 0;

        // Sum m consecutive elements starting at i
        for (int j = 0; j < m; j++) {
            sum += s[i + j];
        }

        // Check if sum matches d
        if (sum == d) {
            ways++;
        }
    }

    return ways;
}

int main() {
    int n;
    int s[100];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &s[i]);
    }

    int d, m;
    scanf("%d %d", &d, &m);

    printf("%d\n", birthday(s, n, d, m));

    return 0;
}


