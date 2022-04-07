import numpy as np
import matplotlib.pyplot as plt

Array = np.genfromtxt("./Array.csv", delimiter=",", names=["x", "insert", "select"])
Stack = np.genfromtxt("./Stack.csv", delimiter=",", names=["x", "insert", "select"])
Queue = np.genfromtxt("./Queue.csv", delimiter=",", names=["x", "insert", "select"])
List = np.genfromtxt("./List.csv", delimiter=",", names=["x", "insert", "select"])

plt.title("Compare Selection Time complexity for different DS")
plt.xlabel("Size, items")
plt.ylabel("Time, nanoseconds")

plt.plot(Array['x'], Array['select'], label="Array")
plt.plot(Queue['x'], Queue['select'], label="Queue")
plt.plot(Stack['x'], Stack['select'], label="Stack")
plt.plot(List['x'], List['select'], label="List")

plt.legend(loc="upper left")
plt.savefig("./selections.png", dpi=200)
