import numpy as np
import matplotlib.pyplot as plt

Array = np.genfromtxt("./Array.csv", delimiter=",", names=["x", "insert", "select"])

plt.title("Compare Insertions Time complexity for different DS")
plt.xlabel("Array size, items")
plt.ylabel("Time, nanoseconds")

plt.plot(Array['x'], Array['insert'], label="Array")

plt.legend(loc="upper left")
plt.savefig("./insertions.png", dpi=200)