int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
    int l=n-1;
    int h=0;
    while(l>=0 && h<m){
        if(arr1[l]>=arr2[h]){
            swap(arr1[l],arr2[h]);
            l--;
            h++;
        }
        else{
            break;
        }
    }
    sort(arr1.begin(),arr1.end());
    sort(arr2.begin(),arr2.end());
    if(k<=n){
        return arr1[k-1];
    }
    else{
        return arr2[k-(n+1)];
    }
    return 0;
}