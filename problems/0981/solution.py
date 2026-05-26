class TimeMap:
    def __init__(self):
        self.__map: dict[str, list[tuple[int, str]]] = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key not in self.__map:
            self.__map[key] = []
        self.__map[key].append((timestamp, value))

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.__map:
            return ""
        tmp: list[tuple[int, str]] = self.__map.get(key)
        left = 0
        right = len(tmp) - 1
        while left <= right:
            mid = left + (right - left) // 2
            if tmp[mid][0] == timestamp:
                return tmp[mid][1]
            elif tmp[mid][0] < timestamp:
                left = mid + 1
            else:
                right = mid - 1
        return "" if right < 0 else tmp[right][1]


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)
