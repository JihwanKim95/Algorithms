#define N 4

typedef struct {
    int hit;
    int miss;
} Result;

// API
extern Result query(int guess[]);

struct St {
    int p = -1, q = -1, r = -1, s = -1;
};

void findNumber(int group[5], St* st); 
void permute(St* st);


/*
    A : 0, 1 / B : 2, 3 / C : 4, 5 / D : 6, 7 / E : 8, 9 /
*/
void doUserImplementation(int guess[]) {
    
    /* 1. 쿼리 호출하고 그룹 확인 배열 저장  */
    int A, B, C, D, E, group[5];
    Result response;
    int sum;

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

    response = query(AD);
    int d = response.hit + response.miss;
    if (d == 4) {
        if (response.hit == 4) return;
    }
    D = d - A; 
    group[3] = D;
    E = 4 - (A + B + C + D); 
    group[5] = E;
    // Group Array consists of {A, B, C, D, E} 

 
    // get other cand numbers
    St st;
    findNumber(group, &st);
    
    // permute all possible cand numbers until answer is obtained 
    permute(&st);
}


/* Find the numbers to be designated in */
void findNumber(int group[5], St* st) {
    int cntOne = 0, cntTwo = 0, onePos[2], twoPos, zeroPos[2];
    int u = 0, v = 0;
    for (int i = 0; i < 5; i++) {
        if (group[i] == 1) {
            cntOne++;
            onePos[u++] = i;
        }
        else if (group[i] == 2) {
            twoPos = i;
            cntTwo++;
        }
        else if (group[i] == 0) {
            zeroPos[v++] = i;
        }
    }

    // group == { 2, 1, 1, 0, 0 } 
    if (cntTwo) {
        // 01 23 45 67 89 
        // A  B  C  D  E 
        // 0  1  2  3  4
        // 2 = 1 * 2 
        // 4 = 2 * 2    ,   5 = 2 * 2 + 1
        st->p = twoPos * 2;
        st->q = twoPos * 2 + 1;

        int cand = onePos[0] * 2;
        int x1 = zeroPos[0] * 2, x2 = zeroPos[0] * 2 + 1, x3 = zeroPos[1] * 2; 
        
        int temp1[4] = { cand, x1, x2, x3 };
        
        Result tryQ = query(temp1);
        if (tryQ.hit || tryQ.miss) st->r = cand;
        else st->r = cand + 1;

        cand = onePos[1];
        int temp2[4] = { cand, x1, x2, x3 };
        tryQ = query(temp2);
        if (tryQ.hit || tryQ.miss) st->s = cand;
        else st->s = cand + 1;
    }
    else { // group : { 1, 1, 1, 1, 0} 
        
    }
    
}


void permute(St* st) {
    int guess[4] = { -1, };


}
