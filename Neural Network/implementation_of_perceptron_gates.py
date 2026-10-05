# Perceptron Learning Algorithm for AND, OR and NOT Gates
# Perceptron Learning Algorithm
# Implementing AND, OR and NOT gates

def perceptron(inputs, targets, learning_rate=1, epochs=10):
    # Initialize weights and bias to 0
    weights = [0] * len(inputs[0])
    bias = 0

    for epoch in range(epochs):
        error_count = 0

        for x, target in zip(inputs, targets):

            # Calculate weighted sum
            summation = sum(w * i for w, i in zip(weights, x)) + bias

            # Activation function
            if summation >= 0:
                output = 1
            else:
                output = 0

            # Calculate error
            error = target - output

            # Update weights and bias
            if error != 0:
                for i in range(len(weights)):
                    weights[i] += learning_rate * error * x[i]

                bias += learning_rate * error
                error_count += 1

        # Stop if there are no errors
        if error_count == 0:
            break

    return weights, bias


def test_gate(name, inputs, targets):
    weights, bias = perceptron(inputs, targets)

    print("\n", name, "Gate")
    print("Weights:", weights)
    print("Bias:", bias)

    for x in inputs:
        summation = sum(w * i for w, i in zip(weights, x)) + bias

        if summation >= 0:
            output = 1
        else:
            output = 0

        print(x, "->", output)


# AND Gate
and_inputs = [
    [0, 0],
    [0, 1],
    [1, 0],
    [1, 1]
]

and_targets = [0, 0, 0, 1]


# OR Gate
or_inputs = [
    [0, 0],
    [0, 1],
    [1, 0],
    [1, 1]
]

or_targets = [0, 1, 1, 1]


# NOT Gate
# NOT gate has only one input
not_inputs = [
    [0],
    [1]
]

not_targets = [1, 0]

# Train and test all gates
test_gate("AND", and_inputs, and_targets)
test_gate("OR", or_inputs, or_targets)
test_gate("NOT", not_inputs, not_targets)

print("Samriddhi Gautam: BIT28: LabIV 1")