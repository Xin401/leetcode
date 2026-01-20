from typing import List, DefaultDict

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        #First solution
        # if len(strs) <= 1:
        #     return [strs]
        # my_dict = {}
        # for idx,s in enumerate(strs):
        #     count = [0 for _ in range(26)]
        #     for c in s:
        #         count[ord(c) - ord('a')] += 1
        #     if s not in my_dict:
        #         my_dict[s] = [count,1]
        #     else:
        #         my_dict[s][1] += 1


        # res = []
        # for key, value in my_dict.items():
        #     flag = False
        #     for r in res:
        #         if r and value[0] == my_dict[r[0]][0]:
        #             for _ in range(value[1]):
        #                 r.append(key)
        #             flag = True
        #             continue
        #     if not flag:
        #         res.append([key for _ in range(value[1])])
        # return res

        #Second solution
        myDict = DefaultDict(list)
        for s in strs:
            count = [0 for _ in range(26)]
            for c in s:
                count[ord(c) - ord('a')] += 1
            key = tuple(count)
            myDict[key].append(s)
        return list(myDict.values())
            
            

    
if __name__ == "__main__":
    strs = ["eat","tea","tan","ate","nat","bat"]
    print(Solution().groupAnagrams(strs))