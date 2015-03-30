#include <iostream>

using namespace std;




int findMax(int a, int b, int c, int limit){
    int max = a < b ? b : a;
    if(c>max && c<= limit)
        max = c;
    return max;
}

int findMin(int a, int b, int c, int limit){
    int min = a < b ? a : b;
    if(c<min && c>= limit)
        min = c;
    return min;
}

double tttmid(int t, int C[], int head, int tail) {
    int mid = (head+tail)/2;
    if(t < C[mid])
        return C[mid];
    else if(t < C[mid+1])
            return t;
        else
            return C[mid+1];
}

double find(int A[], int mHead, int mTail, int B[], int nHead, int nTail, bool &flag, int ATail, int BTail) {
    if(mHead == mTail && nHead == nTail){
        if(flag)
            return (A[mHead] + B[nHead]) / 2.0;
        else
            return A[mHead] < B[nHead] ? A[mHead] : B[nHead];
    }
    if(mHead == mTail || nHead == nTail){
        if(flag){
            if(mHead == mTail){
                int result = tttmid(A[mHead], B, nHead, nTail);cout << result << endl;
                if( result == A[mHead]){
                    if( (nTail-nHead)%2 != 0 ){
                        int an;
                        if(mHead<ATail)
                            an = A[mHead+1]<B[(nHead+nTail)/2+1] ? A[mHead+1]:B[(nHead+nTail)/2+1];
                        else
                            an = B[(nHead+nTail)/2+1];
                        return (A[mHead] + an) / 2.0;
                    }else{
                        int an;
                        if(mHead>0)
                            an = A[mHead-1]<B[(nHead+nTail)/2] ? A[mHead-1]:B[(nHead+nTail)/2];
                        else
                            an = B[(nHead+nTail)/2];
                        return (A[mHead] + an) / 2.0;
                    }
                }
                else if(result == B[(nHead+nTail)/2]){
                    int an;
                    if(mHead<ATail)
                        an = findMax(A[mHead], B[(nHead+nTail)/2 -1],A[mHead+1], B[(nHead+nTail)/2]);
                    else
                        an = findMax(A[mHead], B[(nHead+nTail)/2 -1],A[mHead], B[(nHead+nTail)/2]);
                    return (an + B[(nHead+nTail)/2]) / 2.0;
                }else if(result == B[(nHead+nTail)/2 + 1]){
                    int an;
                    if(mHead>0)
                        an = findMin(A[mHead], B[(nHead+nTail)/2 +1],A[mHead-1], B[(nHead+nTail)/2]);
                    else
                        an = findMin(A[mHead], B[(nHead+nTail)/2 +1],A[mHead], B[(nHead+nTail)/2]);
                    return (an + B[(nHead+nTail)/2]) / 2.0;
                }
            }
            else{
                int result = tttmid(B[nHead], A, mHead, mTail);cout << result << endl;
                if( result == B[nHead]){
                    if( (mTail-mHead)%2 != 0 ){
                        int an;
                        if(nHead<BTail)
                            an = B[nHead+1]<A[(mHead+mTail)/2+1] ? B[nHead+1]:A[(mHead+mTail)/2+1];
                        else
                            an = A[(mHead+mTail)/2+1];
                        return (B[nHead] + an) / 2.0;
                    }else{
                        int an;
                        if(nHead>0)
                            an = B[nHead-1]<A[(mHead+mTail)/2] ? B[nHead-1]:A[(mHead+mTail)/2];
                        else
                            an = A[(mHead+mTail)/2];
                        return (B[nHead] + an) / 2.0;
                    }
                }
                else if(result == A[(mHead+mTail)/2]){
                    int an;
                    if(nHead<nTail)
                        an = findMax(B[nHead], A[(mHead+mTail)/2 -1],B[mHead+1], A[(mHead+mTail)/2]);
                    else
                        an = findMax(B[nHead], A[(mHead+mTail)/2 -1],B[mHead], A[(mHead+mTail)/2]);
                    return (an + A[(mHead+mTail)/2]) / 2.0;
                }else{
                    int an;
                    if(nHead>0)
                        an = findMin(B[nHead], A[(mHead+mTail)/2 +1],B[nHead-1], A[(mHead+mTail)/2]);
                    else
                        an = findMin(B[nHead], A[(mHead+mTail)/2 +1],B[nHead], A[(mHead+mTail)/2]);
                    return (an + A[(mHead+mTail)/2]) / 2.0;
                }
            }
        }
        else{
            if(mHead == mTail)
                return tttmid(A[mHead], B, nHead, nTail);
            else
                return tttmid(B[nHead], A, mHead, mTail);
        }
    }
    int mMid = (mHead+mTail)/2, nMid = (nHead+nTail)/2;
    if(A[mMid] < B[nMid]){
        if((mTail - mHead)%2 != 0)
            mMid++;
        return find(A, mMid, mTail, B, nHead, nMid, flag, ATail, BTail);
    }
    else
        if(A[mMid] > B[nMid]){
            if((nTail - nHead)%2 != 0)
                nMid++;
            return find(A, mHead, mMid, B, nMid, nTail, flag, ATail, BTail);
        }
        else // A[mMid] == B[nMid] , return result directly
            if(flag){
                int min = A[mMid+1] < B[nMid+1] ? A[mMid+1] : B[nMid+1];
                return (A[mMid] + min) / 2.0;
            }else
                return A[mMid];
}


double findMedianSortedArrays(int A[], int m, int B[], int n) {
    bool flag = false;
    if((m+n)%2 == 0)
        flag = true;
    if(m==0)
        if(flag)
            return (B[n/2] + B[n/2-1])/2.0;
        else
            return B[n/2];
    if(n==0)
        if(flag)
            return (A[m/2] + A[m/2-1])/2.0;
        else
            return A[m/2];
    return find(A, 0, m-1, B, 0, n-1, flag, m-1, n-1);
}

int main(){
    int A[] = {1, 4};
    int B[] = {2, 3};
    findMedianSortedArrays(A, 2, B, 2);
    return 0;
}
