#!/usr/bin/python3
""" 0x1F-pascal_triangle
"""

def pascal_triangle(n):
	''' generate pascal's triangle of n levels deep
	'''
	triangle = []
	if n <= 0:
		return triangle

	for x in range(1, n + 1):
		row = []
		col = 1
		for k in range(1, x + 1):
			row.append(col)
			col = int(col * (x - k) / k)
		triangle.append(row)
	return triangle
