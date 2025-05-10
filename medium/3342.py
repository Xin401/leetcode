from typing import List
import heapq

class Solution:
    def minTimeToReach(self, moveTime: List[List[int]]) -> int:
        height = len(moveTime)
        length = len(moveTime[0])
        # (time, y, x, last_step)
        pq = [(0,0,0,2)]
        min_time = [[float('inf') for _ in range(length)] for _ in range(height)]
        direction = [(-1,0),(1,0),(0,-1),(0,1)]
        while pq:
            time, y, x, last_step = heapq.heappop(pq)
            print(time,y,x,last_step)
            if time >= min_time[y][x]:
                continue
            if y == height - 1 and x == length -1:
                return time
            min_time[y][x] = time
            for dy, dx in direction:
                next_y = y + dy
                next_x = x + dx
                if 0 <= next_y < height and 0 <= next_x < length:
                    if max(time,moveTime[next_y][next_x]) + 3 - last_step < min_time[next_y][next_x]:
                        heapq.heappush(pq,(max(time, moveTime[next_y][next_x]) + 3 - last_step,next_y, next_x, 3 - last_step))
        return 0

if __name__ == "__main__":
    moveTime = [[0,1],[1,2]]
    Solution().minTimeToReach(moveTime=moveTime)