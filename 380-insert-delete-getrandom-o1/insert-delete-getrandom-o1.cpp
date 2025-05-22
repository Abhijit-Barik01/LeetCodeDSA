class RandomizedSet {
public:
    unordered_map<int,int>mp;
    vector<int>vec;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end())
            return false;
        vec.push_back(val);
        mp[val]=vec.size()-1;
        return true;

    }
    
    bool remove(int val) {

        if(mp.find(val) == mp.end())
            return false;
        int index = mp[val];
        int last = vec.back();
        vec.back() = vec[index];
        vec[index]= last;
        mp[last] = index;
        vec.pop_back();
        mp.erase(val);
        
        return true;
    }
    
    int getRandom() {
        int n = vec.size();
        int rindex = rand()% n;
        return vec[rindex];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */