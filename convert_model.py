import fileinput
import re
from itertools import zip_longest


def grouper(iterable, n):
    args = [iter(iterable)] * n
    return zip_longest(*args)


pattern = r"(\w+)\s*\[3\]\s*=\s*\{\s*(-?\d+),\s*(-?\d+),\s*(-?\d+)\s*\}"

vertices = []

for line in fileinput.input():
    if m := re.search(pattern, line):
        vertices.append(m[1])
        print(f"v {m[2]} {m[3]} {m[4]}")


pattern = r"v3i\( ([a-zA-Z0-9_]+) \);"

faces = []
for line in fileinput.input():
    if m := re.search(pattern, line):
        faces.append(vertices.index(m[1]) + 1)

for poly in grouper(faces, 4):
    print(f"f {' '.join(map(str, poly))}")
