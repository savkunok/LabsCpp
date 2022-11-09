#include <iostream> 
using namespace std; 
 
class Integer { 
 
private: 
    int value; 
 
public: 
    Integer() { 
        value = 0; 
    } 
 
    Integer(int value) { 
        this->value = value; 
    } 
 
    Integer(const Integer& other) { 
        this->value = other.value; 
    } 
 
    Integer operator + (const Integer& other) const { 
        return { this->value + other.value }; 
    } 
 
    Integer operator - (const Integer& other) const { 
        return { this->value - other.value }; 
    } 
    Integer operator ++ (int) { 
        return { value++ }; 
    } 
    Integer operator -- (int) { 
        return { value-- }; 
    } 
 
    Integer& operator ++ () { 
        value++; 
        return *this; 
    } 
    Integer& operator -- () { 
        value--; 
        return *this; 
    } 
 
    friend bool operator !=(const Integer& first, const Integer& second) 
    { 
        return first.getReal() != second.getReal(); 
    } 
 
    int getReal() const { 
        return value; 
    } 
    void setReal(int value1) { 
        Integer::value = value1; 
    } 
 
    friend class Matrix; 
    friend ostream& operator << (ostream& out, const Integer& a); 
    operator int() const { return (double)this->value; }; 
     
    ~Integer() = default; 
}; 
ostream& operator << (ostream& out, const Integer& a) { 
    out << "value: " << a.value << endl; 
    return out; 
} 
 
class Matrix { 
 
private: 
    Integer matrix[10][10]; 
    int size; 
public: 
 
    Matrix() { 
        size = 9; 
        for (int i = 0; i < size; i++) { 
            for (int j = 0; j < size; j++) { 
                matrix[i][j].value = 0; 
            } 
        } 
    } 
 
    explicit Matrix(int size) { 
        this->size = size - 1; 
        for (int i = 0; i < size; i++) { 
            for (int j = 0; j < size; j++) { 
                cout << "[" << i + 1 << "][" << j + 1 << "]value:";   cin >> matrix[i][j].value; 
                cout << endl; 
            } 
 
        } 
    } 
 
    Matrix(int size, int flag) { 
        this->size = size - 1; 
        for (int i = 0; i < size; i++) { 
            for (int j = 0; j < size; j++) { 
                matrix[i][j].value = 0; 
                cout << endl; 
            } 
 
        } 
    } 
 
    Matrix operator + (const Matrix& other) { 
        Matrix temp; 
 
        for (int i = 0; i <= size; i++) { 
            for (int j = 0; j <= size; j++) { 
                temp[i][j] = this->matrix[i][j] + other.matrix[i][j]; 
            } 
        } 
        return temp; 
    } 
 
    Matrix operator - (const Matrix& other) { 
        Matrix temp; 
 
        for (int i = 0; i <= size; i++) { 
            for (int j = 0; j <= size; j++) { 
                temp[i][j] = this->matrix[i][j] - other.matrix[i][j]; 
            } 
        } 
        return temp; 
    } 
 
 
    Matrix operator ++ (int) const { 
        Matrix temp; 
 
        for (int i = 0; i <= size; i++) { 
            for (int j = 0; j <= size; j++) { 
                temp[i][j]++; 
            } 
        } 
        return temp; 
    } 
 
    Matrix operator -- (int) const { 
        Matrix temp; 
 
        for (int i = 0; i <= size; i++) { 
            for (int j = 0; j <= size; j++) { 
                temp[i][j]--; 
            } 
        } 
        return temp; 
    } 
 
 
    Integer* operator [](const int index) 
    { 
        return matrix[index]; 
    } 
 
    friend bool operator ==(const Matrix& first, const Matrix& second) 
    { 
        bool equal = true; 
        for (int i = 0; i <= first.size; i++) 
        { 
            for (int j = 0; j <= first.size; j++) 
            { 
                if (first.matrix[i][j] != second.matrix[i][j]) 
                    equal = false; 
            } 
        } 
        return equal; 
    } 
 
    Matrix operator = (const Matrix& other) { 
        Matrix temp; 
 
        for (int i = 0; i <= size; i++) { 
            for (int j = 0; j <= size;j++) { 
                temp[i][j] = this->matrix[i][j] = other.matrix[i][j]; 
            } 
        } 
        return temp; 
    } 
void PrintMatrix(int sizeToPrint) { 
        for (int i = 0; i <= sizeToPrint - 1; i++) { 
            cout << endl; 
            for (int j = 0; j <= sizeToPrint - 1; j++) { 
                cout << "[" << i + 1 << "][" << j + 1 << "]= " << matrix[i][j].value<< " "; 
            } 
        } 
    } 
}; 
 
void menuChoice() { 
    cout << endl << endl << "1. Choose operation to do with matrix" << endl << "2. Show source matrix" << endl << "3. exit" << endl; 
} 
void optionToDo() { 
    cout << endl << "Operations with matrix: " 
        << endl << "1. +" 
        << endl << "2. -" 
        << endl << "3. ++(postfix) " 
        << endl << "4. --(postfix) " 
        << endl << "5. operator <<" 
        << endl << "6. == " 
        << endl << "7. = " 
        << endl << "8. from int to double" 
        << endl << endl; 
} 
 
int main() { 
    
    int size; 
    cout << "Enter the size of matrix: "; 
    cin >> size; 
    cout << "Input of matrix 1" << endl; 
    Matrix matrix1(size); 
 
    cout << "Matrix 1:" << endl << endl; 
    matrix1.PrintMatrix(size); 
 
    cout << endl << endl << "Input of matrix 2" << endl; 
    Matrix matrix2(size); 
 
    cout << endl << endl << "Matrix 2:" << endl << endl; 
    matrix2.PrintMatrix(size); 
    Integer Show(5); 
    Matrix resultMatrixSum(size, 1); 
    Matrix resultMatrixExtract(size, 1); 
    Matrix resultMatrixRavno(size, 1); 
    Integer  result(3.4); 
    int menuchoice = 0; 
 
    do { 
        menuChoice(); 
        cin >> menuchoice; 
        Integer a(2), b(1), c, number(10); 
        switch (menuchoice) { 
        case 1: 
            optionToDo(); 
            int optiontodo; cin >> optiontodo; 
 
            switch (optiontodo) { 
            case 1: 
                resultMatrixSum = matrix1 + matrix2; 
                cout << endl << "Result matrix:" << endl << endl; 
                resultMatrixSum.PrintMatrix(size); 
                break; 
 
            case 2: 
                resultMatrixExtract = matrix1 - matrix2; 
                cout << endl << "Result matrix:" << endl << endl; 
                resultMatrixExtract.PrintMatrix(size); 
                break; 
 
            case 3: 
                cout << "Number: " << Show << endl; 
                cout << "Number++" << endl; 
                Show++; 
                cout << "Number: " << Show << endl; 
                break; 
 
            case 4: 
                cout << "Number: " << Show << endl; 
                cout << "Number--" << endl; 
                Show--; 
                cout << "Number: " << Show << endl; 
                break; 
 
            case 5: 
                cout << "Example of overloading << :" << endl; 
                cout << number << endl; 
                break; 
            case 6: 
                if (matrix1 == matrix2) 
                    cout << "The same\n"; 
                else 
                    cout << "Not the same\n"; 
                break; 
            case 7: 
                matrix1 = matrix2; 
                resultMatrixRavno = matrix1; 
                cout << endl << "Result matrix:" << endl << endl; 
                resultMatrixRavno.PrintMatrix(size); 
                break; 
            case 8: 
                cout << "Number: " << result << endl; 
                cout << "Number(double)" << endl; 
                (double)result; 
                cout << "Number: " << (double)result << endl; 
                break; 
            default: 
                break; 
            } 
            break; 
        case 2: 
            cout << "Matrix 1:" << endl << endl; 
            matrix1.PrintMatrix(size); 
            cout << endl << endl << "Matrix 2:" << endl << endl; 
            matrix2.PrintMatrix(size); 
            break; 
        default: 
            break; 
        } 
    } while (menuchoice != 3); 
    return 0; 
}
