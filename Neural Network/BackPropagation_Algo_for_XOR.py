
import numpy as np

def sigmoid(x):
    return 1 / (1 + np.exp(-x))

# Derivative of sigmoid
def sigmoid_derivative(x):
    return x * (1 - x)


# XOR input
X = np.array([
    [0, 0],
    [0, 1],
    [1, 0],
    [1, 1]
])

# XOR target
Y = np.array([
    [0],
    [1],
    [1],
    [0]
])

# Set random seed
np.random.seed(1)

# Initialize weights and biases
# 2 input neurons -> 2 hidden neurons
W1 = np.random.uniform(-1, 1, (2, 2))
b1 = np.zeros((1, 2))

# 2 hidden neurons -> 1 output neuron
W2 = np.random.uniform(-1, 1, (2, 1))
b2 = np.zeros((1, 1))

# Learning rate
learning_rate = 0.5

# Training
for epoch in range(10000):

    # -------- Forward Propagation --------
    # Hidden layer
    hidden_input = np.dot(X, W1) + b1
    hidden_output = sigmoid(hidden_input)
    # Output layer
    output_input = np.dot(hidden_output, W2) + b2
    output = sigmoid(output_input)
    # -------- Backpropagation --------
    # Calculate error
    error = Y - output
    # Output layer delta
    output_delta = error * sigmoid_derivative(output)
    # Hidden layer delta
    hidden_error = np.dot(output_delta, W2.T)
    hidden_delta = hidden_error * sigmoid_derivative(hidden_output)
    # -------- Update weights and biases --------
    W2 += learning_rate * np.dot(hidden_output.T, output_delta)
    b2 += learning_rate * np.sum(output_delta, axis=0, keepdims=True)

    W1 += learning_rate * np.dot(X.T, hidden_delta)
    b1 += learning_rate * np.sum(hidden_delta, axis=0, keepdims=True)
# -------- Testing --------
print("XOR Gate Output:")

for i in range(len(X)):
    print(
        X[i],
        "->",
        round(float(output[i][0]))
    )
print("Samriddhi Gautam: BIT28: LabIV 2")  