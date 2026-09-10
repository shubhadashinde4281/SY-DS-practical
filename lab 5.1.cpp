#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Team {
    char name[50];
    struct Team *next;
};

struct Team *head = NULL;
struct Team *tail = NULL;

// Function to add a team
void addTeam(char name[]) {
    struct Team *newNode;

    newNode = (struct Team *)malloc(sizeof(struct Team));
    strcpy(newNode->name, name);

    if (head == NULL) {
        head = newNode;
        tail = newNode;
        newNode->next = head;
    } else {
        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
    }
}

// Function to simulate rounds
void simulateRounds(int rounds) {
    struct Team *current;
    struct Team *temp;
    int i;

    if (head == NULL) {
        printf("No teams available.\n");
        return;
    }

    current = head;

    for (i = 1; i <= rounds; i++) {
        printf("\n--- Round %d ---\n", i);

        temp = current;

        do {
            printf("%s gets a turn.\n", temp->name);
            temp = temp->next;
        } while (temp != current);

        // Move starting position to next team
        current = current->next;
    }
}

int main() {
    int n, rounds, i;
    char name[50];

    printf("Enter number of teams: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter team %d name: ", i + 1);
        scanf("%s", name);
        addTeam(name);
    }

    printf("\nEnter number of rounds: ");
    scanf("%d", &rounds);

    simulateRounds(rounds);

    return 0;
}
