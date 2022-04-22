/*Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.

Return all the possible results. You may return the answer in any order.*/

/*```````````````LEETCODE````````*/

class Solution {
private:
    bool isValid(string s) {
        int balance = 0;
        for (auto ch : s) {
            if (ch == '(') { // is left
                balance++;
            } else if (ch == ')') { // is right
                if (balance > 0) {
                    balance--;
                } else {
                    // More ringt then left
                    // We can never balance this so return.
                    return false;
                }
            }
        }
        // true if all the left have been balanced by enough rights
        return balance == 0;
    }
    
public:
    
    /* Core idea: Each node is a string
     * At Next level- child(neighbor) string is one char removed from previous node.
     * Find the shortest path to valid string(s)
     */
    vector<string> removeInvalidParentheses(string s) {
        set<string> visited; // To track strings we have already seen
        vector<string> resValid; // To track the result
        queue<string> q; // BFS queue        
        // To track if we reach the max level i.e. min removes
        bool reachedMaxLevel = false;
        
        // Do BFS
        q.push(s);      
        while (!q.empty()) {
            
            // 1. Check if any of the strings at current level are valid
            // 2. We will also add next level if needed.
            
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++) {
                string str = q.front();
                q.pop();
                
                if (isValid(str)) {
                    resValid.push_back(str);
                    // Reached the max level where minimum remove if found
                    reachedMaxLevel = true; 
                }
                
                // Add further levels only if we havent
                // found atleast one valid string yet at current level.
                if (!reachedMaxLevel) {
                    for (int index = 0; index < str.length(); index++) {
                        // Remove the char at index only if it is a paranthesis
                        if (str[index] != '(' && str[index] != ')') {
                            continue;
                        }
                        string child = str.substr(0, index) + str.substr(index+1);                 
                        
                        // Add it to queue if new child node hasn't been visited yet
                        if (visited.find(child) == visited.end()) {
                            q.push(child);
                        }
                        visited.insert(child);
                    }
                }                
            }          
        }        
        return resValid;       
    }
};
