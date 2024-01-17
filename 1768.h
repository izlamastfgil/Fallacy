class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int size1 = word1.size();
        int size2 = word2.size();
        int size = min(size1, size2);
        string answer{};
        int c1{}, c2{};
        for(int i = 0; i < size; i++ )
        {
            answer += word1[i];
            c1++;
            answer += word2[i];
            c2++;
        }
        int i1 = size, i2 = size;
        while (c1 < size1)
        {
            answer += word1[i1];
            i1++;
            c1++;
        }

         while (c2 < size2)
        {
            answer += word2[i2];
            i2++;
            c2++;
        }

        return answer;
    }
};