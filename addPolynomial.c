#include <stdio.h>
#include <stdlib.h>

// Structure for a polynomial term
struct Node {
    float coeff;
    int expo;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(float coeff, int expo) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        perror("Memory allocation failed\n");
        return NULL;
    }
    newNode->coeff = coeff;
    newNode->expo = expo;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end
struct Node* insertNode(struct Node** poly, float coeff, int expo) {
    struct Node* newNode = createNode(coeff, expo);
    if (newNode == NULL) return *poly; // Memory allocation failed

    if (*poly == NULL) {
        *poly = newNode;
    } else {
        struct Node* temp = *poly;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    return *poly;
}

// Function to print a polynomial
void printPolynomial(struct Node* poly) {
    if (poly == NULL) {
        printf("0\n");
        return;
    }
    while (poly != NULL) {
        printf("%.1fx^%d", poly->coeff, poly->expo);
        if (poly->next != NULL)
            printf(" + ");
        poly = poly->next;
    }
    printf("\n");
}

// Function to add two polynomials
struct Node* addPolynomials(struct Node* head1, struct Node* head2) {
    struct Node* poly1 = head1;
    struct Node* poly2 = head2;
    struct Node* head3 = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->expo == poly2->expo) {
            insertNode(&head3, poly1->coeff + poly2->coeff, poly1->expo);
            poly1 = poly1->next;
            poly2 = poly2->next;
        } else if (poly1->expo > poly2->expo) {
            insertNode(&head3, poly1->coeff, poly1->expo);
            poly1 = poly1->next;
        } else {
            insertNode(&head3, poly2->coeff, poly2->expo);
            poly2 = poly2->next;
        }
    }

    // Add remaining terms from poly1
    while (poly1 != NULL) {
        insertNode(&head3, poly1->coeff, poly1->expo);
        poly1 = poly1->next;
    }

    // Add remaining terms from poly2
    while (poly2 != NULL) {
        insertNode(&head3, poly2->coeff, poly2->expo);
        poly2 = poly2->next;
    }

    return head3;
}

// Driver function to test polynomial addition
int main() {
    struct Node *poly1 = NULL, *poly2 = NULL, *result = NULL;

    // Creating first polynomial: 3.5x^3 + 4.2x^2 + 2.1x^1
    insertNode(&poly1, 3.5, 3);
    insertNode(&poly1, 4.2, 2);
    insertNode(&poly1, 2.1, 1);

    // Creating second polynomial: 5.0x^2 + 1.0x^1 + 7.0
    insertNode(&poly2, 5.0, 2);
    insertNode(&poly2, 1.0, 1);
    insertNode(&poly2, 7.0, 0);

    printf("Polynomial 1: ");
    printPolynomial(poly1);

    printf("Polynomial 2: ");
    printPolynomial(poly2);

    // Adding polynomials
    result = addPolynomials(poly1, poly2);

    printf("Resultant Polynomial: ");
    printPolynomial(result);

    return 0;
}
