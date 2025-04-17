import matplotlib.pyplot as plt

# Updated example data for better visual comparison
degrees = [256, 512, 1024]
falcon_times = [4.2, 8.6, 17.3]
hypermaze_times = [0.31, 0.608, 1.2]

# Plotting the data
plt.figure(figsize=(8, 5))
plt.plot(degrees, falcon_times, label="Falcon KeyGen", marker='o')
plt.plot(degrees, hypermaze_times, label="HyperMaze KeyGen", marker='x')

# Adding labels and title
plt.xlabel("Polynomial Degree (N)")
plt.ylabel("Key Generation Time (ms)")
plt.title("Key Generation Time vs Polynomial Degree")
plt.legend()
plt.grid(True)
plt.xscale("log")  # Log scale for x-axis to show scaling better

plt.tight_layout()
plt.show()