#include <stdio.h>
#include <string.h>
// Hàm tính giai thua
long long factorial(int n) {
    long long result = 1;
    
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    
    return result;
}
// hàm tinh chinh hop
long long permutation(int n, int k) {
    if (k > n) {
        return 0;
    }
    
    long long result = 1;
    
    for (int i = 0; i < k; i++) {
        result *= n;
        n--;
    }
    
    return result;
}

// Hàm tính to hop chap k
long long combination(int n, int k) {
    if (k > n) {
        return 0;
    }
    
    unsigned long long result = 1;
    
    for (int i = 0; i < k; i++) {
        result *= n;
        result /= (i + 1);
        n--;
    }
    
    return result;
}
// hoan vi lap
long long HVL(int n, int k, int freq[]) {
    long long result = factorial(n);
    for (int i = 0; i < k; i++) {
        if (freq[i] > 1) {
            result /= factorial(freq[i]);
        }
    }
    
    return result;
}

void B1_a(){
	int n= 5; //cau a
    int k;// cau a
    int numberOfWays = factorial(n);
    printf("Cau a : So cach xap %d nguoi thành hàng ngang de chup anh là %d.\n",n, numberOfWays);
}

void B1_b(){
	int n = 30;
    int k = 3;
    printf("Cau b : So cach 1 lop truong, 1 lop pho và 1 thu quy trong lop hoc: %llu\n", permutation(n, k));
}

void B1_c(){
	int n = 6;
	int k = 2; 
    printf("Cau C: So tu nhien gom 2 chu so khac nhau duoc tao thanh tu {1, 2, 3, 4, 5, 6}: %llu\n", permutation(n, k));
}

void B1_d(){
	int n = 20;
    int k = 10;
    printf("So playlist gom 10 bai hat khac nhau duoc tao tu 20 bai hat da cho: %llu\n", permutation(n, k));
}

void B1_e(){
	
}

void B1_f(){
	int goalkeeper = 2; // So thu môn
    int defender = 6; // So hau ve
    int midfielder = 6; // So tien ve
    int forward = 4; // So tien dao
    long long totalWays = combination(goalkeeper, 1) * combination(defender, 4) * combination(midfielder, 4) * combination(forward, 2);
    printf("So cach chon cac cau thu thi dau theo so do 4-4-2: %llu\n", totalWays);
}

void B1_g(){
	char word[] = "agreeableness";
    int n = strlen(word);
    int charFreq[26] = {0};
   for (int i = 0; i < n; i++) {
        charFreq[word[i] - 'a']++;
    }
	long long totalPermutations = factorial(n);
    // Tính so ch cái trùng lap và chia to hop cho so lan lap
    for (int i = 0; i < 26; i++) {
        if (charFreq[i] > 1) {
            totalPermutations /= factorial(charFreq[i]);
        }
    }
    printf("\"agreeableness\": %llu\n", totalPermutations);
}

void B1_h(){
	int n = 25; // So viên bi
    int k = 5; // So dua tre
    printf("So cach chia 25 vien bi giong nhau cho 5 dua tre: %llu\n", combination(n + k - 1, k - 1));
}


int main() {
	B1_a();
	B1_b();
	B1_c();
	B1_d();
	B1_e();
	B1_f();
	B1_g();
	B1_h(); 
    return 0;
}

