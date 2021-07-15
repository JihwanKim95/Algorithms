#include <stdio.h>

#define N 4

typedef struct {
    int hit;
    int miss;
} Result;

// API
extern Result query(int guess[]);

struct St {
    int p = -1, q = -1, r = -1, s = -1;
    int x1, x2, x3, x4; 
    int ans[4] = { -1, };
};

void findNumber(int group[5], St* st); 
void fitIn(St* st, int* guess);

/*
    A : 0, 1 / B : 2, 3 / C : 4, 5 / D : 6, 7 / E : 8, 9 /
*/
void doUserImplementation(int guess[]) {
    int A, B, C, D, E, group[5];
    Result response;

    int AB[6] = { 0, 1, 2, 3 };
    int AC[6] = { 0, 1, 4, 5 };
    int AD[6] = { 0, 1, 6, 7 };
    int BC[6] = { 2, 3, 4, 5 };
    int BD[6] = { 2, 3, 6, 7 };
    int CD[6] = { 4, 5, 6, 7 };

    // 3 Unknowns, 3 Equations ==> A+B+C = (a+b+c)/2 
    response = query(AB);  // A B 
    int a = response.hit + response.miss;  // response from 0, 1, 2, 3
    if (a == 4) {
        if (response.hit == 4) return;
    }
    response = query(AC);  // A C 
    int c = response.hit + response.miss;
    if (c == 4) {
        if (response.hit == 4) return;
    }
    response = query(BC);  // B C 
    int b = response.hit + response.miss;
    if (b == 4) {
        if (response.hit == 4) return;
    }

    A = (a + b + c) / 2 - b;    group[0] = A;
    B = (a + b + c) / 2 - c;    group[1] = B;
    C = (a + b + c) / 2 - a;    group[2] = C;
    if (A + B + C == 4) {  // 0, 1, 2, 3, 4, 5 range 안에 답 존재 
        D = 0, E = 0;    
    }
    else {
        response = query(AD);
        int d = response.hit + response.miss;
        if (d == 4) {
            if (response.hit == 4) return;
        }
        D = d - A;
    }
    group[3] = D;
    E = 4 - (A + B + C + D);
    group[4] = E;
    
    // Group Array consists of {A, B, C, D, E} 

#if 1
    printf("\n\n\nGROUP distribution:::");
    for (int i = 0; i < 5; i++) {
        printf("%d ", group[i]);
    }
    printf("\n");
#endif
    
 
    // get other cand numbers
    St st;
    findNumber(group, &st);
    
    // permute all possible cand numbers until answer is obtained 
    fitIn(&st, guess);

}


/* Find the numbers to be designated in */
void findNumber(int group[5], St* st) {
    int cntOne = 0, cntTwo = 0, onePos[4] = { 0, }, twoPos[2] = { 0, }, zeroPos[2] = { 0, };
    int u = 0, v = 0, w = 0;

    for (int i = 0; i < 5; i++) {
        if (group[i] == 0) {
            zeroPos[u++] = i;
        }
        else if (group[i] == 1) {
            cntOne++;
            onePos[v++] = i;
        }
        else if (group[i] == 2) {
            twoPos[w++] = i;
            cntTwo++;
        }
        
    }

#if 1
    printf("zeropos:::%d %d, onepos:::%d %d %d %d, twopos:::%d %d\n",
        zeroPos[0], zeroPos[1], onePos[0], onePos[1], onePos[2], onePos[3], twoPos[0], twoPos[1]);
#endif

    int x1 = zeroPos[0] * 2, x2 = zeroPos[0] * 2 + 1, 
        x3 = zeroPos[1] * 2, x4 = zeroPos[1] * 2 + 1; 

    st->x1 = x1, st->x2 = x2, st->x3 = x3, st->x4 = x4; 


    if (cntTwo == 2) {
        st->p = twoPos[0] * 2, st->q = twoPos[0] * 2 + 1;
        st->r = twoPos[1] * 2, st->s = twoPos[1] * 2 + 1;
    }
    // group == { 2, 1, 1, 0, 0 } 
    else if (cntTwo == 1) {
        // 01 23 45 67 89 
        // A  B  C  D  E 
        // 0  1  2  3  4
        // 2 = 1 * 2 
        // 4 = 2 * 2    ,   5 = 2 * 2 + 1
        st->p = twoPos[0] * 2;
        st->q = twoPos[0] * 2 + 1;

        int cand = onePos[0] * 2;

        int temp1[4] = { cand, x1, x2, x3 };
        
        Result tryQ = query(temp1);
        if (tryQ.hit || tryQ.miss) st->r = cand;
        else st->r = cand + 1;

        cand = onePos[1] * 2;
        int temp2[4] = { cand, x1, x2, x3 };
        tryQ = query(temp2);
        if (tryQ.hit || tryQ.miss) st->s = cand;
        else st->s = cand + 1;
    }
    else { // group : { 1, 1, 1, 1, 0} 
        int a1 = onePos[0] * 2, a2 = onePos[0] * 2 + 1, 
            b1 = onePos[1] * 2, b2 = onePos[1] * 2 + 1,
            c1 = onePos[2] * 2, c2 = onePos[2] * 2 + 1, 
            d1 = onePos[3] * 2, d2 = onePos[3] * 2 + 1;
        
        // A B 
        int temp1[4] = { a1, b1, x1, x2 }; 
        Result tryQ = query(temp1);
        int allcnt = tryQ.hit + tryQ.miss;
        if (allcnt == 2) {
            st->p = a1;
            st->q = b1;
            st->x3 = a2;
            st->x4 = b2;
        }
        else if (allcnt == 1) {
            temp1[1] = b2;
            tryQ = query(temp1);
            if (!tryQ.hit && !tryQ.miss) {
                st->p = a2;
                st->q = b1;
                st->x3 = a1;
                st->x4 = b2;
            }
            else {
                st->p = a1;
                st->q = b2;
                st->x3 = a2;
                st->x4 = b1;
            }
        }
        else if (allcnt == 0) {
            st->p = a2;
            st->q = b2;
            st->x3 = a1;
            st->x4 = b1;
        }

        // C D 
        int temp2[4] = { c1, d1, x1, x2 };
        tryQ = query(temp2);
        allcnt = tryQ.hit + tryQ.miss;
        if (allcnt == 2) {
            st->r = c1;
            st->s = d1;
        }
        else if (allcnt == 1) {
            temp2[1] = d2;
            tryQ = query(temp2);
            if (!tryQ.hit && !tryQ.miss) {
                st->r = c2;
                st->s = d1;
            }
            else {
                st->r = c1;
                st->s = d2;
            }
        }
        else if (allcnt == 0) {
            st->r = c2;
            st->s = d2;
        }
    }   

#if 1
    printf("Found Number::: %d %d %d %d\n", st->p, st->q, st->r, st->s);
#endif
}


void fitIn(St* st, int guess[]) {
    int output[4] = { -1, -1, -1, -1};
    int a = st->p, b = st->q, c = st->r, d = st->s;

    // p
    int temp1[4] = { a, st->x1, st->x2, st->x3 };
    Result tryQ = query(temp1);
    if (tryQ.hit) output[0] = a;
    else {
        temp1[0] = temp1[1];
        temp1[1] = a;
        tryQ = query(temp1);
        if (tryQ.hit) output[1] = a;
        else {
            temp1[1] = temp1[2];
            temp1[2] = a;
            tryQ = query(temp1);
            if (tryQ.hit) output[2] = a;
            else output[3] = a;

        }
    }
    

    // q
    int temp2[4] = { b, st->x1, st->x2, st->x3 };
    tryQ = query(temp2);
    if (tryQ.hit) output[0] = b;
    else {
        temp2[0] = temp2[1];
        temp2[1] = b;
        tryQ = query(temp2);
        if (tryQ.hit) output[1] = b;
        else {
            temp2[1] = temp2[2];
            temp2[2] = b;
            tryQ = query(temp2);
            if (tryQ.hit) output[2] = b;
            else output[3] = b;

        }
    }


    // r
    int temp3[4] = { c, st->x1, st->x2, st->x3 };
    tryQ = query(temp3);
    if (tryQ.hit) output[0] = c;
    else {
        temp3[0] = temp3[1];
        temp3[1] = c;
        tryQ = query(temp3);
        if (tryQ.hit) output[1] = c;
        else {
            temp3[1] = temp3[2];
            temp3[2] = c;
            tryQ = query(temp3);
            if (tryQ.hit) output[2] = c;
            else output[3] = c;
        }
    }

    // s 
    for (int i = 0; i < 4; i++) {
        if (output[i] == -1) output[i] = d;
    }
    // end of fit in algorithm 

    
    // fill guess array 
    for (int i = 0; i < 4; i++) {
        guess[i] = output[i];
    }

#if 1
    printf("fitin:::%d %d %d %d\n", output[0], output[1], output[2], output[3]);
#endif

    

    return;
}
