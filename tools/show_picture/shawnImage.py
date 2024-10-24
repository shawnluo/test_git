import numpy as np
import matplotlib.pyplot as plt
import sys

# Ensure that the script takes the file path as an argument
if len(sys.argv) != 2:
    print("Usage: python shawnImage.py <raw_image_file>")
    sys.exit(1)

# Define the image dimensions
width = 640
# width = 2460
height = 480
# height =2460
# Read the file passed as an argument
raw_image_file = sys.argv[1]
try:
    with open(raw_image_file, 'rb') as f:
        file_bytes = f.read()

    # Check the file size to ensure it matches the expected size for a 640x480 RAW8 image
    expected_size = width * height  # RAW8 = 1 byte per pixel
    if len(file_bytes) != expected_size:
        print(f"Error: File size mismatch. Expected {expected_size} bytes, but got {len(file_bytes)} bytes.")
        sys.exit(1)

    # Convert the raw bytes to a numpy array and reshape it to the correct dimensions
    image_data_raw8 = np.frombuffer(file_bytes, dtype=np.uint8).reshape((height, width))

    # Display the image
    plt.figure(figsize=(6, 4))
    plt.imshow(image_data_raw8, cmap='gray')
    plt.title("RAW8 Image (640x480)")
    plt.axis('off')  # Hide axes
    plt.show()

except FileNotFoundError:
    print(f"Error: File {raw_image_file} not found.")
    sys.exit(1)

except Exception as e:
    print(f"An error occurred: {e}")
    sys.exit(1)
