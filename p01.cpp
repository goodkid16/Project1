#include <iostream>
#include <iomanip>
#include <vector>

// Function to evaluate the expression
bool evaluateExpression(bool p, bool q, bool r, int exp) {
    switch (exp) {
    case 1: return (p || q) && (!p && !q);
    case 2: return (!p || !q) <= (p == q);
    case 3: return (p || q) && (!p ^ r) == (p && r);
    case 4: return ((p <= r) <= q) && (p <= (q <= r));
    default: return false;
    }
}

// Function to analyze the expression
void analyzeExpression(int exp) {
    // Output the expression
    std::cout << std::setw(30) << std::left << "Expression " << exp;

    // Output the truth table header
    std::cout << std::setw(5) << "p";
    std::cout << std::setw(5) << "q";
    std::cout << std::setw(5) << "r";
    std::cout << std::setw(10) << "Result" << std::endl;

    // Initialize counter for true cases
    int trueCount = 0;

    // Evaluate the expression for all possible truth values of p, q, and r
    for (int p = 0; p <= 1; ++p) {
        for (int q = 0; q <= 1; ++q) {
            for (int r = 0; r <= 1; ++r) {
                // Evaluate the expression
                bool result = evaluateExpression(p, q, r, exp);

                // Output the truth values and result
                std::cout << std::setw(5) << p;
                std::cout << std::setw(5) << q;
                std::cout << std::setw(5) << r;
                std::cout << std::setw(10) << (result ? "T" : "F") << std::endl;

                // Count the number of true cases
                if (result) {
                    trueCount++;
                }
            }
        }
    }

    // Output the conclusion based on the number of true cases
    std::cout << "There are " << trueCount << " true cases." << std::endl;
    if (trueCount == 8) {
        std::cout << "Expression " << exp << " is a tautology." << std::endl;
    }
    else if (trueCount == 0) {
        std::cout << "Expression " << exp << " is a contradiction." << std::endl;
    }
    else {
        std::cout << "Expression " << exp << " is a contingency." << std::endl;
    }

    std::cout << std::endl; // Add a newline for better separation between expressions
}

int main() {
    // Define the expressions
    std::vector<int> expressions = { 1, 2, 3, 4 };

    // Analyze each expression
    for (const auto& exp : expressions) {
        analyzeExpression(exp);
    }

    return 0;
}
