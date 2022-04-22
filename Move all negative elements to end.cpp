/*Move all negative elements to end*/
/*`````````GFG``````*/

class Solution{
    public:

        // Your code goes here
        void segregateElements(int arr[],int n)
    {
        vector<int> v;
        int k = 0;
        int i = 0;
        for(int i=0; i<n; i++){
            if(arr[i]>=0){
                arr[k++] = arr[i];
            }
            else{
                v.push_back(arr[i]);
            }
        }
        i = 0;
        while(k<n){
            arr[k++] = v[i++];
        }
    }
};
