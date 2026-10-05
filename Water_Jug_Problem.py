def water_jug():
    jug4 = 0
    jug3 = 0

    print("Initial state:", (jug4, jug3))

    # Step 1: Fill the 3-gallon jug
    jug3 = 3
    print("Fill 3-gallon jug:", (jug4, jug3))

    # Step 2: Pour 3-gallon jug into 4-gallon jug
    jug4 = jug4 + jug3
    jug3 = 0
    print("Pour 3-gallon into 4-gallon:", (jug4, jug3))

    # Step 3: Fill the 3-gallon jug again
    jug3 = 3
    print("Fill 3-gallon jug:", (jug4, jug3))

    # Step 4: Pour 3-gallon jug into 4-gallon jug
    # Only 1 gallon can enter the 4-gallon jug
    jug3 = jug3 - (4 - jug4)
    jug4 = 4
    print("Pour into 4-gallon jug:", (jug4, jug3))

    # Step 5: Empty the 4-gallon jug
    jug4 = 0
    print("Empty 4-gallon jug:", (jug4, jug3))

    # Step 6: Pour remaining 2 gallons into 4-gallon jug
    jug4 = jug3
    jug3 = 0
    print("Pour remaining water into 4-gallon jug:", (jug4, jug3))

    print("\nGoal reached!")
    print("4-gallon jug contains:", jug4, "gallons")


water_jug()
print("Samriddhi Gautam: BIT28 : LabIV 3")