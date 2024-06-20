import matplotlib.pyplot as plt
plt.style.use('dark_background')

# Version 1.
v1_axis = [
    5, 10, 20, 24, 4.8, 4.8, 9.6,
    14.4, 36, 68, 102.6, 51.3, 51.3,
    102.6, 205.2, 369.36, 369.36, 295.488, 88.6464, 8.86464,
    8.86464, 0, 0, 0, 0, 0, 0,
]
# Version 2.
v2_axis = [
    34, 71, 105, 141, 172, 201, 280,
    310, 342, 362, 391, 422, 452, 532,
    562, 590, 618, 647, 680, 710, 790,
    # Version 2.1
    831, 872, 910, 953, 995, 1041, 1144,
    # Version 2.12
    1186, 1232, 1275, 1321, 1366, 1412, 1524,
    1573, 1626, 1675, 1716, 1752, 1789, 1900,
    1935, 1987, 2032, 2074, 2115, 2156, 2258,
]
# Version 3.
v3_axis_p = [
    86, 170, 257, 336, 414, 482, 559,
    # Version 3.1
    569, 573, 587, 598, 613, 626, 644,
    657, 669, 676, 690, 698, 715,
]
# From Version 3.
axis_n = [
    -2, -8, -14, -18, -22, -26, -6,
    -10, -13, -13, -12, -12, -12, -13,
    -10, -7, -2, 1, 4, 7,
]

days_v1 = list(range(len(v1_axis)))

days_v2 = list(range(len(v2_axis)))

days_v3_p = list(range(len(v3_axis_p)))
days_v3_n = days_v3_p

plt.figure(figsize=(12, 5))

plt.plot(days_v1, v1_axis, color='#2D2C2C', linestyle='dotted', label='v1')
plt.plot(days_v2, v2_axis, color='#3A2D12', linestyle='dashdot', label='v2')
plt.plot(days_v3_p, v3_axis_p, color='green', label="v3")
plt.plot(days_v3_n, axis_n, color='grey', label="axis_n")

plt.xlabel("Days")
plt.ylabel("Points")

plt.legend()

plt.show()
