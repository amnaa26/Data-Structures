#include <iostream>
#include <string.h>
using namespace std;

class Document {
private:
    char* textContent;

public:
    Document(const char* initialText) {
        textContent = new char[strlen(initialText) + 1];
        strcpy(textContent, initialText);
    }

    ~Document() {
        delete[] textContent;
    }

    Document(const Document& other) {
        textContent = new char[strlen(other.textContent) + 1];
        strcpy(textContent, other.textContent);
    }

    // Copy Assignment Operator
    Document& operator=(const Document& other) {
        if (this != &other) {
            delete[] textContent;
            textContent = new char[strlen(other.textContent) + 1];
            strcpy(textContent, other.textContent);
        }
        return *this;
    }

    void display() const {
        std::cout << "Document Content: " << textContent << std::endl;
    }

    void modifyContent(const char* newText) {
        delete[] textContent;
        textContent = new char[strlen(newText) + 1];
        strcpy(textContent, newText);
    }
};

int main() {
    cout << "Amna (23k-0066)" << endl;
    Document originalDoc("This is the original content.");
    Document copyDoc = originalDoc;
    originalDoc.modifyContent("This is the modified content.");
    cout << "Original Document:" << endl;
    originalDoc.display();
    cout << "Copied Document:" << endl;
    copyDoc.display();

    Document anotherDoc("Initial content.");
    anotherDoc = originalDoc;

    cout << "Another Document after assignment:" << endl;
    anotherDoc.display();

    return 0;
}

