#include <iostream>

bool sudoku_solution_is_correct(unsigned int board[9][9]) // returns true if board is a correct sudoku solution, false otherwise
{
    for (int curr_row = 0; curr_row < 9; ++curr_row) // iterate through the rows 
    {
        for (int curr_col = 0; curr_col < 9; ++curr_col) // iterate through the cols
        {
            bool digits_one_to_nine[9] = {false}; // digits_one_to_nine[i] is true if i + 1 is present in the current row, column or 3x3 square

            // check the current row
            for (int col = 0; col < 9; ++col) // for all columns
            {
                if (digits_one_to_nine[board[curr_row][col] - 1]) // if the current digit is already present in the current row
                {
                    return false;
                }
                else
                {
                    digits_one_to_nine[board[curr_row][col] - 1] = true; // mark the current digit as present in the current row
                }
            }
            // reset digits_one_to_nine
            for (int i = 0; i < 9; ++i)
                digits_one_to_nine[i] = false;

            // check the current column
            for (int row = 0; row < 9; ++row) // for all rows
            {
                if (digits_one_to_nine[board[row][curr_col] - 1]) // if the current digit is already present in the current column
                {
                    return false;
                }
                else
                {
                    digits_one_to_nine[board[row][curr_col] - 1] = true; // mark the current digit as present in the current column
                }
            }

            // reset digits_one_to_nine
            for (int i = 0; i < 9; ++i)
                digits_one_to_nine[i] = false;

            // Check 3x3 square
            int square_row = curr_row / 3 * 3; // the row of the top left corner of the current 3x3 square
            int square_col = curr_col / 3 * 3; // the column of the top left corner of the current 3x3 square
            for (int row = square_row; row < square_row + 3; ++row) // for all rows in the current 3x3 square
            {
                for (int col = square_col; col < square_col + 3; ++col) // for all columns in the current 3x3 square
                {
                    if (digits_one_to_nine[board[row][col] - 1]) // if the current digit is already present in the current 3x3 square
                    {
                        return false;
                    }
                    else
                    {
                        digits_one_to_nine[board[row][col] - 1] = true; // mark the current digit as present in the current 3x3 square
                    }
                }
            }
        }
    }

    return true;
}