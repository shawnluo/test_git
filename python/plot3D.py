import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# single points
'''
ax = plt.axes(projection="3d")
ax.scatter(3, 5, 7)
plt.show()
'''

# Define the range for x and y
x = np.linspace(-5, 5, 100)
y = np.linspace(-5, 5, 100)

# Create a meshgrid for x and y
X, Y = np.meshgrid(x, y)

# Calculate z values
Z = np.sin(X) + np.cos(Y)

# Plot the surface
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot_surface(X, Y, Z, cmap='viridis')

# Set labels and title
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')
ax.set_title('z = sin(x) + cos(y)')

# Show plot
plt.show()