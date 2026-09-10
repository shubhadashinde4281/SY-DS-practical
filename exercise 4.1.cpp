#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Team {
    char name[50];
    struct Team *next;
};

struct Team *head = NULL;
struct Team *tail = NULL;

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

void displayTeams() {
    struct Team *temp;

    if (head == NULL) {
        printf("No teams available.\n");
        return;
    }

    temp = head;

    printf("\nRound Robin Sequence:\n");

    do {
        printf("%s -> ", temp->name);
        temp = temp->next;
    } while (temp != head);

    printf("(Back to %s)\n", head->name);
}

int main() {
    int n, i;
    char name[50];

    printf("Enter number of teams: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter team %d name: ", i + 1);
        scanf("%s", name);
        addTeam(name);
    }

    displayTeams();

    return 0;
}
