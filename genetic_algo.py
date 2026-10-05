def fitness(chromosome):
    x = int(chromosome, 2)
    return x * x


population = ["00101", "10110", "01001", "11000"]

generations = 5

for generation in range(generations):

    print("\nGeneration", generation + 1)
    print("Population:", population)

    # Calculate fitness
    fitness_values = [fitness(ch) for ch in population]
    print("Fitness:", fitness_values)

    # Selection
    selected = sorted(population, key=fitness, reverse=True)[:2]
    print("Selected Parents:", selected)

    # Crossover
    parent1 = selected[0]
    parent2 = selected[1]

    crossover_point = 2

    child1 = parent1[:crossover_point] + parent2[crossover_point:]
    child2 = parent2[:crossover_point] + parent1[crossover_point:]

    print("After Crossover:", child1, child2)

    # Mutation
    child1 = child1[:3] + ("1" if child1[3] == "0" else "0") + child1[4:]
    child2 = child2[:3] + ("1" if child2[3] == "0" else "0") + child2[4:]

    print("After Mutation:", child1, child2)

    # New population
    population = [selected[0], selected[1], child1, child2]


# Best solution
best = max(population, key=fitness)

print("\nFinal Population:", population)
print("Best Chromosome:", best)
print("Best Value:", int(best, 2))
print("Maximum Fitness:", fitness(best))
print("Samriddhi Gautam: BIT28 : LabIV 4")