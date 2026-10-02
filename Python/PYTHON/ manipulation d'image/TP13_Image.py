import numpy as np
import matplotlib.pyplot as plt
from PIL import Image, ImageFilter

# Convert an rgb image to a grey level image
# This function is not used here
def rgb2gray(rgb):
    r, g, b = rgb[:,:,0], rgb[:,:,1], rgb[:,:,2]
    gray = 0.2989 * r + 0.5870 * g + 0.1140 * b
    return gray,r,g,b

img = Image.open("parrot.bmp")  
plt.imshow(img)
plt.show()
img.rotate(90).show()

img2gray = img.convert("L")# Convert to grey level using convert("L")
plt.imshow(img2gray,cmap=plt.get_cmap('gray'), vmin=0, vmax=255)
plt.show()

# Compute the histogram
hst=img2gray.histogram()
#plt.hist(hst)

fig, ax = plt.subplots(1, 3)

ax[0].imshow(img)
ax[0].set_title("Original")
ax[1].imshow(img2gray, cmap=plt.cm.gray, vmin=0, vmax=255)
ax[1].set_title("Grayscale image")
ax[2].hist(hst,bins=100)
ax[2].set_title("Histogram of the grayscale image")

# #fig.tight_layout()
plt.show()


# Decompose the original image in 3 bands (r=red, g=green, b=blue)
r, g, b = img.split()

fig1, ax1 = plt.subplots(1, 4)

ax1[0].imshow(img)
ax1[0].set_title("Original")
ax1[1].imshow(r)
ax1[1].set_title("Red component")
ax1[2].imshow(g)
ax1[2].set_title("Green component")
ax1[3].imshow(b)
ax1[3].set_title("Blue component")

plt.show()


# Merge the 3 components (r=red, g=green, b=blue) to form a new image
NewImage = Image.merge("RGB",(b,r,g))
plt.imshow(NewImage)
plt.show()

# Autrement ------------------------------------------------
#import skimage
#import imageio

# u = imageio.imread('parrot.bmp')
# print(u.shape)
# print(u.dtype)
# # u is an RGB  image (3 chanels), each having size 495 x 495.
# # store this values (to adapt to other images)
# M, N, nc = u.shape
# # M is the height, N is the width (matrix convention)
# plt.imshow(u);