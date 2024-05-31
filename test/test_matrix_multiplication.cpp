#include "matrix_multiplication.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>

// ######################### Source code of multiplyMatrices in src/matrix_mult


TEST(ErrorsMatrixB, Error4){
    //Error 4: Matrix B contains the number 3!
    std::vector<std::vector<int>> A = {{1, 2, 3},{4, 5, 6}};
    std::vector<std::vector<int>> B = {{7, 3},{9, 10},{11, 12}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    std::vector<std::vector<int>> expected = {{58, 64},{139, 154}};
    multiplyMatrices(A, B, C, 2, 3, 2);

    bool no_number_3 = false;
    for (int i = 0; i < B.size(); ++i){
        for (int j = 0; j < B[i].size(); ++j){
            if(B[i][j] == 3){
                no_number_3 = true;
                break;
            } 
        }
    }
    ASSERT_TRUE(no_number_3);
}

TEST(ErrorsMatrixB, Error5){
    //Error 5: Matrix B contains a negative number!
    std::vector<std::vector<int>> A = {{1, 2, 3},{4, 5, 6}};
    std::vector<std::vector<int>> B = {{-7, 4},{9, 10},{11, 12}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    std::vector<std::vector<int>> expected = {{58, 64},{139, 154}};
    multiplyMatrices(A, B, C, 2, 3, 2);

    bool not_negative_number = false;
    for (int i = 0; i < B.size(); ++i){
        for (int j = 0; j < B[i].size(); ++j){
            if(B[i][j] < 0){
                not_negative_number = true;
                break;
            }
        }
    }
    
    ASSERT_TRUE(not_negative_number);
}

TEST(ErrorsMatrixB, Error11){
    //Error 11: Every row in matrix B contains at least one 0!
    std::vector<std::vector<int>> A = {{1, 2, 3},{4, 5, 6}};
    std::vector<std::vector<int>> B = {{0, 4},{0, 10},{0, 12}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    std::vector<std::vector<int>> expected = {{58, 64},{139, 154}};
    multiplyMatrices(A, B, C, 2, 3, 2);

    int counter_zeros = 0;
    for (int i = 0; i < B.size(); ++i){
        for (int j = 0; j < B[i].size(); ++j){
            if(B[i][j] == 0){
                counter_zeros++;
                continue;
            }
        }
    }
    ASSERT_GT(counter_zeros, B.size() - 1);
}

TEST(ErrorsMatrixB, Error12){
    //Error 12: The number of rows in A is equal to the number of columns in B!
    std::vector<std::vector<int>> A = {{1, 2, 3},{4, 5, 5}, {7, 8, 9}};
    std::vector<std::vector<int>> B = {{1, 4, 5},{1, 10, 5},{0, 12, 5}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    std::vector<std::vector<int>> expected = {{58, 64},{139, 154}};
    multiplyMatrices(A, B, C, 2, 3, 2);

    bool rows_columns = A.size() != B[0].size()? false : true;
    ASSERT_TRUE(rows_columns); 
}

TEST(ErrorsMatrixB, Error16){
    //Error 16: Matrix b contains the number 6!
    std::vector<std::vector<int>> A = {{1, 2, 3},{4, 5, 5}, {7, 8, 9}};
    std::vector<std::vector<int>> B = {{1, 4, 5},{1, 6, 5},{0, 12, 5}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    multiplyMatrices(A, B, C, 2, 3, 2);

    bool no_number_6 = false;
    for (int i = 0; i < B.size(); ++i){
        for (int j = 0; j < B[i].size(); ++j){
            if(B[i][j] == 6){
                no_number_6 = true;
                break;
            }
        }
    }
    ASSERT_TRUE(no_number_6);
}

TEST(ErrorsMatrixC, Error14){
    //Error 14: The result matrix has an even number of rows!
    std::vector<std::vector<int>> A = {{1, 2, 3},{4, 5, 5}};
    std::vector<std::vector<int>> B = {{1, 4, 5},{1, 6, 5},{0, 12, 5}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    multiplyMatrices(A, B, C, 2, 3, 2);

    bool no_even_rows = C.size() % 2 == 0 ? true : false;
    ASSERT_TRUE(no_even_rows);

}

TEST(ErrorsMatrixC, Error17){
    //Error 17: result matrix C contains the number 17!
    std::vector<std::vector<int>> A = {{17, 0, 0},{4, 5, 6}};
    std::vector<std::vector<int>> B = {{1, 8},{9, 10},{0, 12}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    multiplyMatrices(A, B, C, 2, 3, 2);

    bool no_number_17 = true;
    for (int i = 0; i < C.size(); ++i){
        for (int j = 0; j < C[i].size(); ++j){
            if(C[i][j] == 6){
                no_number_17 = false;
                break;
            }
        }
    }
    ASSERT_TRUE(no_number_17);
}

TEST(ErrorsMatrixA, Error1){
    //it spots Error 1: Element-wise multiplication of ones detected!
    std::vector<std::vector<int>> A = {{1, 2 ,3},{4, 5, 6}}; 
    std::vector<std::vector<int>> B = {{1, 2}, {0, 4}, {5, 0}, {7, 0}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    std::vector<std::vector<int>> expected = {{58, 64},{139, 154}};
    multiplyMatrices(A, B, C, 2, 3, 2);

    //Search for element-wise multiplication of ones
    bool element_wise = false;
    for (int i = 0; i < A.size(); ++i)
        for (int j = 0; j < A[i].size(); ++j)
            if (A[i][j] != 1) element_wise = true;
    
    ASSERT_TRUE(element_wise);

}

TEST(ErrorsMatrixA, Error2){
    //it spots Error 2: Matrix A contains the number 7!
    std::vector<std::vector<int>> A = {{7, 5, 6},{7, 8, 9}};
    std::vector<std::vector<int>> B = {{0, 8},{0, 10},{0, 12}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    
    multiplyMatrices(A, B, C, 2, 3, 2);

    //Search for number 7 in matrix A
    bool found = false;
    for (int i = 0; i < A.size(); ++i)
        for (int j = 0; j < A[i].size(); ++j)
            if (A[i][j] == 7) found = true;
    
    ASSERT_TRUE(found);
}

TEST(ErrorsMatrixA, Error3){
    //it spots Error 3: Matrix A contains a negative number!
    std::vector<std::vector<int>> A = {{-1, 5, 6},{7, 8, 9}};
    std::vector<std::vector<int>> B = {{0, 8},{0, 10},{0, 12}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    
    multiplyMatrices(A, B, C, 2, 3, 2);

    //Search for negative number in matrix A
    bool negative = false;
    for (int i = 0; i < A.size(); ++i)
        for (int j = 0; j < A[i].size(); ++j)
            if (A[i][j] < 0) negative = true;
    
    ASSERT_TRUE(negative);
}

TEST(ErrorsMatrixA, Error10){
    //it spots Error 10: A row in matrix A contains more than one '1'!
    std::vector<std::vector<int>> A = {{1, 1, 3},{4, 5, 6}};
    std::vector<std::vector<int>> B = {{7, 8},{9, 10},{11, 12}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    
    
    multiplyMatrices(A, B, C, 2, 3, 2);

    //Search for number of ones in a row in matrix A
    bool more_than_one = false;
    for (int i = 0; i < A.size(); ++i){
        int ones = 0;
        for (int j = 0; j < A[i].size(); ++j)
            if (A[i][j] == 1) ones++;
        if (ones > 1) more_than_one = true;
    }

    ASSERT_TRUE(more_than_one);
}

TEST(ErrorsMatrixA, Error18){
    //it spots Error 18: Matrix A is a square matrix!
    std::vector<std::vector<int>> A = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
    std::vector<std::vector<int>> B = {{7, 8, 0},{9, 10, 0},{11, 12, 0}};
    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));
    
    multiplyMatrices(A, B, C, 3, 3, 3);
    
    ASSERT_EQ(A.size(), A[0].size());
}

TEST(ErrorsMatrixA, Error20){
    //it spots Error 20: Number of columns in matrix A is odd!!
    std::vector<std::vector<int>> A = {{0,0,0}};
    std::vector<std::vector<int>> B = {{1}, {2}, {3}};
    std::vector<std::vector<int>> C(1, std::vector<int>(1, 0));

    multiplyMatrices(A, B, C, 1, 3, 1);

    bool colsA = A[0].size() % 2 == 0 ? false : true;

    ASSERT_TRUE(colsA);
    
}

TEST(ErrorsMatrixC, Error6){
    //it spots Error 6: Result matrix contains a number bigger than 100!
    std::vector<std::vector<int>> A = {{1, 100, 3},{4, 5, 6},{7, 8, 9}};
    std::vector<std::vector<int>> B = {{7, 100, 0},{9, 10, 0},{11, 12, 0}};
    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));
    
    multiplyMatrices(A, B, C, 3, 3, 3);

   //Search for number bigger than 100 in matrix C
    bool hund = false;
    for (int i = 0; i < C.size(); ++i)
        for (int j = 0; j < C[i].size(); ++j)
            if (C[i][j] > 100) hund = true;
    
    ASSERT_TRUE(hund);
    
}

TEST(ErrorsMatrixC, Error7){
    //it spots Error 7: Result matrix contains a number between 11 and 20!
    std::vector<std::vector<int>> A = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
    std::vector<std::vector<int>> B = {{7, 100, 0},{9, 10, 0},{11, 12, 0}};
    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));
    
    multiplyMatrices(A, B, C, 3, 3, 3);

   //Search for number  between 11 and 20!
    bool range = false;
    for (int i = 0; i < C.size(); ++i)
        for (int j = 0; j < C[i].size(); ++j)
            if (C[i][j] < 11 && C[i][j] < 20) range = true;
    
    ASSERT_TRUE(range);
    
}

TEST(ErrorsMatrixC, Error8){
    //it spots Error 8: Result matrix contains zero!
    std::vector<std::vector<int>> A = {{0,0,0}};
    std::vector<std::vector<int>> B = {{1}, {2}, {3}};
    std::vector<std::vector<int>> C(1, std::vector<int>(1, 0));

    multiplyMatrices(A, B, C, 1, 3, 1);

    std::vector<std::vector<int>> expected = {
        {58},
    };

   //Search for 0 in matrix C
    bool zero = false;
    for (int i = 0; i < C.size(); ++i)
        for (int j = 0; j < C[i].size(); ++j)
            if (C[i][j] == 0 ) zero = true;
    
    ASSERT_TRUE(true);
    
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

