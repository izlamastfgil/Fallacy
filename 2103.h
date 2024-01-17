class Solution {
public:
    int countPoints(string rings) {
        unordered_map<int, vector<char>> var;
        int count = 0;
        for(int i = 1; i < rings.length(); i+=2)
            var[rings[i] - 48].push_back(rings[i - 1]); 
        bool red, blue, green;
        for(const auto &i: var)
        {
            red = ((find(i.second.begin(), i.second.end(), 'R') != i.second.end()) ? true : false);
            green = ((find(i.second.begin(), i.second.end(), 'G') != i.second.end()) ? true : false);
            blue = ((find(i.second.begin(), i.second.end(), 'B') != i.second.end()) ? true : false);
            if (red && blue && green)
                count++;
        }
        return count;
        
    }
};