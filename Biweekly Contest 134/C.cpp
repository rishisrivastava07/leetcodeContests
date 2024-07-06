/*
Problem Statement - 3208 : Alternating Groups II
There is a circle of red and blue tiles. You are given an array of integers colors and an integer k. The color of tile i is represented by colors[i]:

colors[i] == 0 means that tile i is red.
colors[i] == 1 means that tile i is blue.
An alternating group is every k contiguous tiles in the circle with alternating colors (each tile in the group except the first and last one has a different color from its left and right tiles).

Return the number of alternating groups.

Note that since colors represents a circle, the first and the last tiles are considered to be next to each other.

Example 1:
    Input: colors = [0,1,0,1,0], k = 3
    Output: 3
Example 2:
    Input: colors = [0,1,0,0,1,0,1], k = 6
    Output: 2
Example 3:
    Input: colors = [1,1,0,1], k = 4
    Output: 0
    
Constraints:
    3 <= colors.length <= 105
    0 <= colors[i] <= 1
    3 <= k <= colors.length
*/

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size(); 
        int count = 0; 

        // every single tile is a individual group
        if (k == 1) return n; 
 
        int alterLen = 1, i = 1; 

        while (i < n + k - 1) { 
            // make the indexes traverse in circular array
            int curr = i % n; 
            int prev = (i - 1) % n; 

            // check for alternating colors
            if (colors[curr] != colors[prev]) ++alterLen; 
            else alterLen = 1; 

            // if the alternating length exceeds the mark of K
            // increase the count variable because it is a valid contiguous tiles in circle
            if (alterLen >= k) ++count;
            ++i; 
        } 
        return count; 
    }
};