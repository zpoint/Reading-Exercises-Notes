import matplotlib
import matplotlib.pyplot as plt
import numpy as np
from sklearn.datasets import fetch_mldata
mnist = fetch_mldata("MNIST original")
X, y = mnist["data"], mnist["target"]
X_train, X_

def test():
    some_digit = X[36000]
    print(y[36000])
    some_digit_image = some_digit.reshape(28, 28)
    plt.imshow(some_digit_image, cmap=matplotlib.cm.binary, interpolation="nearest")
    plt.axis("off")
    plt.show()


def get_train():
    shuffle_index = np.random.permutation(60000)
    X_train, y_train =