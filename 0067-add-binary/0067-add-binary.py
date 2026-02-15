class Solution:
    def addBinary(self, a: str, b: str) -> str:
        
        result = []
        
        # Start from last index
        i = len(a) - 1
        j = len(b) - 1
        
        carry = 0
        
        # Continue until all bits and carry processed
        while i >= 0 or j >= 0 or carry:
            
            # Start with carry
            total = carry
            
            # Add bit from a if exists
            if i >= 0:
                total += int(a[i])
                i -= 1
            
            # Add bit from b if exists
            if j >= 0:
                total += int(b[j])
                j -= 1
            
            # Append result bit
            result.append(str(total % 2))
            
            # Update carry
            carry = total // 2
        
        # Reverse and join to make final string
        return ''.join(result[::-1])
