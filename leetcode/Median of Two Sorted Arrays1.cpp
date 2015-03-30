#include <iostream>

using namespace std;


int findKth(int A[], int m, int Apos, int B[], int n, int Bpos, int dis){
    if(Apos == m)
        return B[Bpos+dis-1];
    if(Bpos == n)
        return A[Apos+dis-1];
    if(dis == 1){
        return A[Apos] < B[Bpos] ? A[Apos] : B[Bpos];
    }
    int k = dis/2 -1;
    int aK = Apos+k, bK = Bpos+k;cout<<"ak:"<<aK<<"bk"<<bK<<endl;
    if(aK +1 > m)
        aK = m-1;
    if(bK +1 > n)
        bK = n-1;
    if(A[aK] < B[bK]){
        dis -= aK-Apos+1;
        findKth(A, m, aK+1, B, n, Bpos, dis);
    }else if(A[aK] > B[bK]){
        dis -= bK-Bpos+1;
        findKth(A, m, Apos, B, n, bK+1, dis);
    }else{
        if(aK == m-1){
            dis -= aK-Apos+2;
            return B[Bpos + dis];
        }else if(bK == n-1){
            dis -= bK-Bpos+2;
            return A[Apos + dis];
        }else{
            if(dis % 2 == 0)
                return A[aK];
            else
                return A[aK+1] < B[bK+1] ? A[aK+1] : B[bK+1];
        }
    }
}

double findMedianSortedArrays(int A[], int m, int B[], int n) {
    int mid = (m+n)/2 + 1;
    if( (m+n)%2 !=0 ){
        return findKth(A,m,0,B,n,0,mid);
    }else{
        double r1 = findKth(A,m,0,B,n,0,mid);
        mid = (m+n)/2;
        return (findKth(A,m,0,B,n,0,mid) + r1)/2.0;
    }

}

int main(){
    int A[] = {1,3,5,6};
    int B[] = {1,2,4,8};
    cout << findMedianSortedArrays(A,3,B,4);
}
