import matplotlib
import matplotlib.pyplot as plt
import numpy as np
from sklearn.datasets import fetch_mldata
from sklearn.linear_model import SGDClassifier
from sklearn.model_selection import StratifiedKFold, cross_val_score
from sklearn.base import clone, BaseEstimator
from sklearn.metrics import confusion_matrix

mnist = fetch_mldata("MNIST original")
X, y = mnist["data"], mnist["target"]
X_train, X_test, y_train, y_test = X[:60000], X[60000:], y[:60000], y[60000:]


def test():
    some_digit = X[36000]
    print(y[36000])
    some_digit_image = some_digit.reshape(28, 28)
    plt.imshow(some_digit_image, cmap=matplotlib.cm.binary, interpolation="nearest")
    plt.axis("off")
    plt.show()


def get_train():
    global X_train, X_test, y_train, y_test
    shuffle_index = np.random.permutation(60000)
    X_train, y_train = X_train[shuffle_index], y_train[shuffle_index]


def train_binary_classifier():
    global X_train, X_test, y_train, y_test
    y_train_5 = (y_train == 5)
    y_test_5 = (y_test == 5)
    sgd_clf = SGDClassifier(random_state=52)
    sgd_clf.fit(X_train, y_train_5)
    print(sgd_clf.predict([X_test[6000]]))


def cross_validation():
    skfolds = StratifiedKFold(n_splits=3, random_state=42)
    y_train_5 = (y_train == 5)
    y_test_5 = (y_test == 5)
    sgd_clf = SGDClassifier(random_state=52)
    for train_index, test_index in skfolds.split(X_train, y_train_5):
        clone_clf = clone(sgd_clf)
        X_train_folds = X_train[train_index]
        y_train_folds = (y_train_5[train_index])
        X_test_fold = X_train[test_index]
        y_test_fold = (y_train_5[test_index])

        clone_clf.fit(X_train_folds, y_train_folds)
        y_pred = clone_clf.predict(X_test_fold)
        n_correct = sum(y_pred == y_test_fold)
        print(n_correct / len(y_pred))


def cross_validation_2():
    sgd_clf = SGDClassifier(random_state=52)
    y_train_5 = (y_train == 5)
    r = cross_val_score(sgd_clf, X_train, y_train_5, cv=3, scoring="accuracy")
    print(r)


def never5classifier():
    class Never5Classifier(BaseEstimator):
        def fit(self, X, y=None):
            pass

        def predict(self, X):
            return np.zeros((len(X), 1), dtype=bool)

    y_train_5 = (y_train == 5)
    never_5_clf = Never5Classifier()
    r = cross_val_score(never_5_clf, X_train, y_train_5, cv=3, scoring="accuracy")
    print(r)


def confusion_mtx():
    y_train_5 = (y_train == 5)
    print(y_train_5)
    # confusion_matrix(y_train_5, y_train)


if __name__ == "__main__":
    confusion_mtx()
