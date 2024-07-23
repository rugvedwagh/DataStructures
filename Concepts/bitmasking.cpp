*/

318. Maximum Product of Word Lengths

Given a string array words, return the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. If no such two words exist, return 0.

  Example 1:
  Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
  Output: 16
  Explanation: The two words can be "abcw", "xtfn".
    
  Example 2:
  Input: words = ["a","ab","abc","d","cd","bcd","abcd"]
  Output: 4
  Explanation: The two words can be "ab", "cd".
    
  Example 3:
  Input: words = ["a","aa","aaa","aaaa"]
  Output: 0
  Explanation: No such pair of words.
 

Constraints:
  2 <= words.length <= 1000
  1 <= words[i].length <= 1000
  words[i] consists only of lowercase English letters.

*/

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> bitmasks(n, 0);

        for (int i = 0; i < words.size(); i++) {
            for (char c : words[i]) {
                bitmasks[i] = bitmasks[i] | 1 << (c - 'a');
            }
        }

        int maxProd = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((bitmasks[i] & bitmasks[j]) == 0) {
                    int prod = words[i].length() * words[j].length();
                    maxProd = max(maxProd, prod);
                }
            }
        }

        return maxProd;
    }
};

*/

Shifting is used in this context to create a unique bit representation for each letter of the alphabet. Let me explain why this is useful:

Efficient representation:
By using bit shifting, we can represent the presence of each letter in a word using just a single 32-bit integer. This is much more memory-efficient than, say, using an array of 26 booleans.
Easy set operations:
Bit manipulation allows us to perform set operations (like union, intersection, difference) very efficiently using bitwise operations.
One-to-one mapping:
Each letter gets its own unique bit position. 'a' is represented by the least significant bit, 'b' by the second least significant bit, and so on.

Here's how the shifting works for each letter:

'a': 1 << 0 = 00000000000000000000000000000001
'b': 1 << 1 = 00000000000000000000000000000010
'c': 1 << 2 = 00000000000000000000000000000100
...
'z': 1 << 25 = 00000010000000000000000000000000

By shifting, we're essentially creating a "bitmap" where each bit corresponds to a letter. When we OR these values together, we're building a set of letters present in the word.

The operation masks[i] = masks[i] | 1<<(c-'a'); is equivalent to masks[i] |= 1<<(c-'a');. Both expressions do the same thing, just with slightly different syntax. Let's break down what happens:

1<<(c-'a') creates a binary number with a single '1' bit in the position corresponding to the letter c.
This binary number is then OR'ed with the existing value of masks[i].
The result is stored back in masks[i].





The effect is to set the bit corresponding to the letter c in masks[i], while leaving all other bits unchanged. This operation adds the letter to our set representation without affecting any other letters already in the set.
For example, if we're processing the word "cat":

Initially, masks[i] is 0 (00000000000000000000000000000000 in binary)
For 'c':

1<<(c-'a') is 00000000000000000000000000000100
After OR: 00000000000000000000000000000100


For 'a':

1<<(a-'a') is 00000000000000000000000000000001
After OR: 00000000000000000000000000000101


For 't':

1<<(t-'a') is 00000000000000000000000010000000
After OR: 00000000000000000000000010000101



The final value of masks[i] will be 00000000000000000000000010000101, which represents that the word contains the letters 'a', 'c', and 't'.

*/
