#include <iostream>
#include <string>

class PermissionConverter {
public:
    // Constructor
    PermissionConverter() {
        choice = 0;
        owner_perm = "---";
        group_perm = "---";
        public_perm = "---";
        chmod_number = 0;
    }

    // Function to calculate chmod number from permission strings
    int calculateChmod(const std::string& owner_perm, const std::string& group_perm, const std::string& public_perm) {
        int owner = 0, group = 0, public_bits = 0;

        // Calculate owner permission bits
        if (owner_perm[0] == 'r') owner += 4;
        if (owner_perm[1] == 'w') owner += 2;
        if (owner_perm[2] == 'x') owner += 1;

        // Calculate group permission bits
        if (group_perm[0] == 'r') group += 4;
        if (group_perm[1] == 'w') group += 2;
        if (group_perm[2] == 'x') group += 1;

        // Calculate public permission bits
        if (public_perm[0] == 'r') public_bits += 4;
        if (public_perm[1] == 'w') public_bits += 2;
        if (public_perm[2] == 'x') public_bits += 1;

        // Combine the permission bits to form the chmod number
        return (owner * 100) + (group * 10) + public_bits;
    }

    // Function to convert chmod number into permission strings
    void convertToPermissions(int chmod_number, std::string& owner_perm, std::string& group_perm, std::string& public_perm) {
        int owner_bits = chmod_number / 100;
        int group_bits = (chmod_number / 10) % 10;
        int public_bits = chmod_number % 10;

        // Convert owner permission bits to string
        owner_perm[0] = (owner_bits & 4) ? 'r' : '-';
        owner_perm[1] = (owner_bits & 2) ? 'w' : '-';
        owner_perm[2] = (owner_bits & 1) ? 'x' : '-';

        // Convert group permission bits to string
        group_perm[0] = (group_bits & 4) ? 'r' : '-';
        group_perm[1] = (group_bits & 2) ? 'w' : '-';
        group_perm[2] = (group_bits & 1) ? 'x' : '-';

        // Convert public permission bits to string
        public_perm[0] = (public_bits & 4) ? 'r' : '-';
        public_perm[1] = (public_bits & 2) ? 'w' : '-';
        public_perm[2] = (public_bits & 1) ? 'x' : '-';
    }

    // Run the program
    void run() {
        while (true) {
            displayMenu();
            std::cin >> choice;

            if (choice == 1) {
                std::cout << "Enter owner permissions  (e.g., rwx): ";
                std::cin >> owner_perm;
                std::cout << "Enter group permissions  (e.g., rwx): ";
                std::cin >> group_perm;
                std::cout << "Enter public permissions (e.g., rwx): ";
                std::cin >> public_perm;

                chmod_number = calculateChmod(owner_perm, group_perm, public_perm);
                std::cout << "Chmod number: " << chmod_number << std::endl;
            } else if (choice == 2) {
                std::cout << "Enter chmod number (e.g., 755): ";
                std::cin >> chmod_number;

                convertToPermissions(chmod_number, owner_perm, group_perm, public_perm);
                std::cout << "Owner : " << owner_perm << std::endl;
                std::cout << "Group : " << group_perm << std::endl;
                std::cout << "Public: " << public_perm << std::endl;
            } else if (choice == 3) {
                break; // Exit the program
            } else {
                std::cout << "Invalid choice. Please enter a valid option." << std::endl;
            }
        }
    }

private:
    int choice;
    std::string owner_perm;
    std::string group_perm;
    std::string public_perm;
    int chmod_number;

    void displayMenu() {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Convert permissions to chmod number" << std::endl;
        std::cout << "2. Convert chmod number to permissions" << std::endl;
        std::cout << "3. Quit" << std::endl;
        std::cout << "Enter your choice: ";
    }
};

int main() {
    PermissionConverter converter;
    converter.run();
    return 0;
}
