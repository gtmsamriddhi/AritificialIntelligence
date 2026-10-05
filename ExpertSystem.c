#include <stdio.h>

int main() {
    int fever, cough, cold, headache, soreThroat, bodyPain;
    int breathingProblem, vomiting, diarrhea, rash;

    printf("========================================\n");
    printf("     DISEASE DIAGNOSIS EXPERT SYSTEM\n");
    printf("========================================\n");
    printf("Answer 1 for YES and 0 for NO.\n\n");

    printf("Do you have fever? ");
    scanf("%d", &fever);

    printf("Do you have cough? ");
    scanf("%d", &cough);

    printf("Do you have cold/runny nose? ");
    scanf("%d", &cold);

    printf("Do you have headache? ");
    scanf("%d", &headache);

    printf("Do you have sore throat? ");
    scanf("%d", &soreThroat);

    printf("Do you have body pain? ");
    scanf("%d", &bodyPain);

    printf("Do you have breathing problems? ");
    scanf("%d", &breathingProblem);

    printf("Do you have vomiting? ");
    scanf("%d", &vomiting);

    printf("Do you have diarrhea? ");
    scanf("%d", &diarrhea);

    printf("Do you have skin rash? ");
    scanf("%d", &rash);

    printf("\n----------- DIAGNOSIS -----------\n");

    if (fever && cough && cold && soreThroat) {
        printf("Possible Disease: Common Cold / Viral Infection\n");
    }
    else if (fever && cough && bodyPain && headache) {
        printf("Possible Disease: Influenza (Flu)\n");
    }
    else if (fever && cough && breathingProblem) {
        printf("Possible Disease: Respiratory Infection\n");
    }
    else if (fever && headache && bodyPain && rash) {
        printf("Possible Disease: Dengue-like illness\n");
    }
    else if (vomiting && diarrhea && fever) {
        printf("Possible Disease: Gastroenteritis / Stomach Infection\n");
    }
    else if (cold && cough && soreThroat && !fever) {
        printf("Possible Disease: Common Cold\n");
    }
    else if (headache && fever && !cough && !cold) {
        printf("Possible Disease: Fever-related infection\n");
    }
    else {
        printf("Disease cannot be determined from the given symptoms.\n");
        printf("Please consult a qualified medical professional.\n");
    }

    printf("---------------------------------\n");
    printf("Note: This is a simple educational expert-system example,\n");
    printf("not a substitute for professional medical diagnosis.\n");
    printf("Samriddhi Gautam: BIT28: LabIII1");
    return 0;
}
