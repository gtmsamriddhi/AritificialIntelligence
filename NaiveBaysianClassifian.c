#include <stdio.h>

int main() {
    // Example:
    // Class = Yes / No
    // Feature 1 = Sunny / Rainy
    // Feature 2 = Hot / Cold

    int totalYes = 6;
    int totalNo = 4;
    int total = totalYes + totalNo;

    // New instance: Sunny, Hot

    // P(Yes) and P(No)
    float pYes = (float)totalYes / total;
    float pNo = (float)totalNo / total;

    // Conditional probabilities
    // P(Sunny | Yes) = 3/6
    // P(Hot | Yes)   = 2/6
    float sunnyGivenYes = 3.0 / 6.0;
    float hotGivenYes = 2.0 / 6.0;

    // P(Sunny | No) = 1/4
    // P(Hot | No)   = 3/4
    float sunnyGivenNo = 1.0 / 4.0;
    float hotGivenNo = 3.0 / 4.0;

    // Naive Bayes calculation
    float probabilityYes =
        pYes * sunnyGivenYes * hotGivenYes;

    float probabilityNo =
        pNo * sunnyGivenNo * hotGivenNo;

    printf("Naive Bayes Classifier\n");
    printf("----------------------\n");

    printf("P(Yes) = %.4f\n", probabilityYes);
    printf("P(No)  = %.4f\n", probabilityNo);

    if (probabilityYes > probabilityNo) {
        printf("\nPredicted Class: YES\n");
    } else {
        printf("\nPredicted Class: NO\n");
    }
    printf("Samriddhi Gautam: BIT28: LabIII2");
    return 0;
}
