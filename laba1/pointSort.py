class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def distance(self):
        return self.x * self.x + self.y * self.y


points = []
points_count = int(input())

for _ in range(points_count):
    x, y = map(int, input().split())
    points.append(Point(x, y))

points.sort(key=lambda p: p.distance())

for point in points:
    print(point.x, point.y)
    