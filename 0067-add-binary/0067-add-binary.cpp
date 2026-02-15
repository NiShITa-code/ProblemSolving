class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";

        // Start from the last characters (rightmost bits)
        int i = a.length() - 1;
        int j = b.length() - 1;

        // This stores carry (just like manual addition)
        int carry = 0;

        // Continue until both strings are finished AND no carry left
        while (i >= 0 || j >= 0 || carry > 0)
        {
            // Step 1: Start with carry
            int sum = carry;

            // Step 2: Add bit from string 'a' if available
            if (i >= 0)
            {
                // Convert character '0' or '1' into integer 0 or 1
                int bitA = a[i] - '0';
                sum += bitA;
                i--;
            }

            // Step 3: Add bit from string 'b' if available
            if (j >= 0)
            {
                int bitB = b[j] - '0';
                sum += bitB;
                j--;
            }

            // Step 4: Calculate result bit
            // sum % 2 gives remainder (0 or 1)
            int resultBit = sum % 2;

            // Convert integer to character and add to result string
            result.push_back(resultBit + '0');

            // Step 5: Calculate new carry
            carry = sum / 2;
        }

        // Step 6: Reverse result because we built it backwards
        reverse(result.begin(), result.end());

        return result;
            
    }
};