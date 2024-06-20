import matplotlib.pyplot as plt
plt.style.use('dark_background')

scale = [
    7, 7, 12, 7, 7, 10, 10, 9, 9, 8, 7, 5, 11, 11, 10, 12, 19, 18, 12, 16, 23, 26, 22, 32, 34, 26, 18.5, 24, 20.5, 18,
    11, 8, 21.5, 13.5, 10, 11.5, 8.5, 10, 5, 4, 10, 0, 0, 2, 2, 4, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 14, 18, 6, 15, 14,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
]

plt.figure(figsize=(12, 5))

plt.plot(scale, color='green', label='v4', linewidth=2)
plt.xlabel("Days")
plt.ylabel("Progress")

plt.legend()

plt.show()
