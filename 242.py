class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        dictionary = {}
        for i in s:
            if i in dictionary:
                dictionary[i] += 1
            else:
                dictionary[i] = 1
        for j in t:
            if j in dictionary:
                dictionary[j] -= 1
            else:
                return False
        return all(i == 0 for i in dictionary.values())
    
if __name__ == "__main__":
    s = "anagram"
    t = "nagaram"
    print(Solution().isAnagram(s,t))