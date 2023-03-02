class Solution {

    bool findKthBit(unsigned int n, int k){
        return (((1 << (k-1)) & n) != 0) ? true : false;
    }

public:
    uint32_t reverseBits(uint32_t n) {
        
        unsigned int ans = 0;

        for(int i=1;i<=32;i++){

            if(findKthBit(n, i))
                ans = (1 << (32-i)) | ans;

        }

        return ans;

    }
};