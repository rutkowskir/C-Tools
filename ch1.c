#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate chmod number from permission strings
int calculateChmod(const char* owner_perm, const char* group_perm, const char* public_perm) {
    int owner = 0, group = 0, public = 0;

    // Calculate owner permission bits
    if (owner_perm[0] == 'r') owner += 4;
    if (owner_perm[1] == 'w') owner += 2;
    if (owner_perm[2] == 'x') owner += 1;

    // Calculate group permission bits
    if (group_perm[0] == 'r') group += 4;
    if (group_perm[1] == 'w') group += 2;
    if (group_perm[2] == 'x') group += 1;

    // Calculate public permission bits
    if (public_perm[0] == 'r') public += 4;
    if (public_perm[1] == 'w') public += 2;
    if (public_perm[2] == 'x') public += 1;

    // Combine the permission bits to form the chmod number
    return (owner * 100) + (group * 10) + public;
}

// Function to convert chmod number into permission strings
void convertToPermissions(int chmod_number, char* owner_perm, char* group_perm, char* public_perm) {
    int owner_bits = chmod_number / 100;
    int group_bits = (chmod_number / 10) % 10;
    int public_bits = chmod_number % 10;

    // Convert owner permission bits to string
    owner_perm[0] = (owner_bits & 4) ? 'r' : '-';
    owner_perm[1] = (owner_bits & 2) ? 'w' : '-';
    owner_perm[2] = (owner_bits & 1) ? 'x' : '-';
    owner_perm[3] = '\0';

    // Convert group permission bits to string
    group_perm[0] = (group_bits & 4) ? 'r' : '-';
    group_perm[1] = (group_bits & 2) ? 'w' : '-';
    group_perm[2] = (group_bits & 1) ? 'x' : '-';
    group_perm[3] = '\0';

    // Convert public permission bits to string
    public_perm[0] = (public_bits & 4) ? 'r' : '-';
    public_perm[1] = (public_bits & 2) ? 'w' : '-';
    public_perm[2] = (public_bits & 1) ? 'x' : '-';
    public_perm[3] = '\0';
}

int main() {
    int choice;
    char owner_perm[4], group_perm[4], public_perm[4];
    int chmod_number;

    while (1) {
        printf("Menu:\n");
        printf("1. Convert permissions to chmod number\n");
        printf("2. Convert chmod number to permissions\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            // Input permissions for owner, group, and public
            printf("Enter owner permissions  (e.g., rwx): ");
            scanf("%s", owner_perm);
            printf("Enter group permissions  (e.g., rwx): ");
            scanf("%s", group_perm);
            printf("Enter public permissions (e.g., rwx): ");
            scanf("%s", public_perm);

            // Calculate and print the chmod number
            chmod_number = calculateChmod(owner_perm, group_perm, public_perm);
            printf("Chmod number: %03d\n", chmod_number);
        } else if (choice == 2) {
            // Input chmod number
            printf("Enter chmod number (e.g., 755): ");
            scanf("%d", &chmod_number);

            // Convert chmod number back to permissions and print
            convertToPermissions(chmod_number, owner_perm, group_perm, public_perm);
            printf("Owner : %s\n", owner_perm);
            printf("Group : %s\n", group_perm);
            printf("Public: %s\n", public_perm);
        } else if (choice == 3) {
            break; // Exit the program
        } else {
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
