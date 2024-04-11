#include <iostream>

// Function to create a polynomial by taking input from the user
Term* createPolynomial() {
    Term* poly = nullptr;
    int coefficient, exponent;
    char choice;

    do {
        std::cout << "Enter coefficient: ";
        std::cin >> coefficient;
        std::cout << "Enter exponent: ";
        std::cin >> exponent;

        addTerm(&poly, coefficient, exponent);

        std::cout << "Do you want to add another term? (y/n): ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return poly;
}


int main() {
    // Create the first polynomial
    std::cout << "Enter the first polynomial:\n";
    Term* poly1 = createPolynomial();

    // Create the second polynomial
    std::cout << "Enter the second polynomial:\n";
    Term* poly2 = createPolynomial();

    // Add the polynomials
    Term* result = addPolynomials(poly1, poly2);

    // Display the result
    std::cout << "Result: ";
    displayPolynomial(result);

    return 0;
}