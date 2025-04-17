import matplotlib.pyplot as plt

# Example data
degrees = [512]
falcon_times = [8.6]
hypermaze_times = [0.608]

plt.plot(degrees, falcon_times, label="Falcon KeyGen", marker='o')
plt.plot(degrees, hypermaze_times, label="HyperMaze KeyGen", marker='x')

plt.xlabel("Polynomial Degree (N)")
plt.ylabel("Key Generation Time (ms)")
plt.title("Key Generation Time vs Polynomial Degree")
plt.legend()
plt.grid(True)
plt.xscale("log")  # log scale to better show N=8 vs 512/1024

plt.show()