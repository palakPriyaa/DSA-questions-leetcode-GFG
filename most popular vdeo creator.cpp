class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string> &creators, vector<string> &ids, vector<int> &views) {
        int n = creators.size();        
        unordered_map<string, pair<long long, unordered_map<string, long long>>> stats;
        long long max_count = -1;
        
        for (int i = 0; i < n; ++i) {
            stats[creators[i]].first += views[i];
            stats[creators[i]].second[ids[i]] += views[i];
            max_count = max(max_count, stats[creators[i]].first);
        }
        
        vector<vector<string>> answers;
        
        for (const auto &[name, total_idviews]: stats) {
            const auto &[total_cnt, id_views] = total_idviews;
            
            if (total_cnt == max_count) {
                long long max_view = -1;
                string max_id = "";
                for (const auto &[id, view]: id_views) {
                    if (view > max_view) {
                        max_view = view;
                        max_id = id;
                    } else if (view == max_view && id < max_id) {
                        max_id = id;
                    }
                }

                answers.push_back({name, max_id});
            }
        }
        
        return answers;
    }
}; 
