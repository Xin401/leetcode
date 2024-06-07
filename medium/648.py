from typing import List

class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        words = sentence.split()
        dictionary.sort(key=lambda x: len(x))
        for w in words:
            for d in dictionary:
                if w.startswith(d):
                    words[words.index(w)] = d
                    break
        return " ".join(words)
    
if __name__ == "__main__":
    dictionary = ["cat","bat","rat"]
    sentence = "the cattle was rattled by the battery"
    s = Solution()
    print(s.replaceWords(dictionary, sentence)) # "the cat was rat by the bat"