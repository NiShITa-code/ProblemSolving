/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    vector<int> flattend;
    int index;
public:
    vector<int> flatten(const vector<NestedInteger> & nested) {
        vector<int> flat;
        for (auto ele: nested) {
            if (ele.isInteger()) {
                flat.push_back(ele.getInteger());
            } else {
                auto recurList = flatten(ele.getList());
                flat.insert(flat.end(), recurList.begin(), recurList.end());
            }
        } 
        return flat;
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        flattend = flatten(nestedList);
        index = 0; 
    }
    
    int next() {
        return flattend[index++];
    }
    
    bool hasNext() {
        return index < flattend.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */