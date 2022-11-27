#include <iostream>
#include <string>
#include <vector>

bool is_it_possible_to_reach_exit(std::string maze)
{
    // extractring maze from string
    std::vector<std::vector<char>> maze_vector;
    std::vector<char> maze_row;

    // getting width of each row
    int width = 0;
    for (size_t i = 0; i < maze.size(); ++i)
    {
        if (maze[i] == '\n')
        {
            width = i;
            break;
        }
    }

    // filling maze_vector
    for (size_t i = 0; i < maze.size(); ++i)
    {
        if (maze[i] == '\n')
        {
            maze_vector.push_back(maze_row);
            maze_row.clear();
        }
        else
        {
            maze_row.push_back(maze[i]);
        }
    }
    maze_vector.push_back(maze_row);


    // checking if player is stuck at the beginning
    if (maze_vector[0][1] == 'W' && maze_vector[1][0] == 'W')
    {
        return false;
    }

    // mark starting position as possible to reach
    maze_vector[0][0] = 'P';

    size_t height = maze_vector.size();

    for (size_t curr_row = 0; curr_row < height; ++curr_row)
    {
        for (size_t curr_col = 0; curr_col < width; ++curr_col)
        {
            // if it's an exit and it's marked as possible to reach
            if (curr_row == maze_vector.size() - 1 && curr_col == maze_vector[curr_row].size() - 1 && maze_vector[curr_row][curr_col] == 'P')
            {
                return true;
            }
            else if (maze_vector[curr_row][curr_col] == 'W')
            {
                continue;
            }
            else if (maze_vector[curr_row][curr_col] == 'P')
            {
                // remember current position
                int curr_row_copy = curr_row;
                int curr_col_copy = curr_col;

            start_moving: // explore all possible directions

                // go all the way down while possible
                while (curr_row_copy < maze_vector.size() - 1 && maze_vector[curr_row_copy + 1][curr_col_copy] != 'W' && maze_vector[curr_row_copy + 1][curr_col_copy] != 'P')
                {
                    maze_vector[curr_row_copy + 1][curr_col_copy] = 'P';
                    ++curr_row_copy;
                    goto start_moving;
                }

                // go all the way right while possible
                while (curr_col_copy < maze_vector[curr_row].size() - 1 && maze_vector[curr_row_copy][curr_col_copy + 1] != 'W' && maze_vector[curr_row_copy][curr_col_copy + 1] != 'P')
                {
                    maze_vector[curr_row_copy][curr_col_copy + 1] = 'P';
                    ++curr_col_copy;
                    goto start_moving;
                }

                // go all the way up while possible
                while (curr_row_copy > 0 && maze_vector[curr_row_copy - 1][curr_col_copy] != 'W' && maze_vector[curr_row_copy - 1][curr_col_copy] != 'P')
                {
                    maze_vector[curr_row_copy - 1][curr_col_copy] = 'P';
                    --curr_row_copy;
                    goto start_moving;
                }

                // go all the way left while possible
                while (curr_col_copy > 0 && maze_vector[curr_row_copy][curr_col_copy - 1] != 'W' && maze_vector[curr_row_copy][curr_col_copy - 1] != 'P')
                {
                    maze_vector[curr_row_copy][curr_col_copy - 1] = 'P';
                    --curr_col_copy;
                    goto start_moving;
                }
            }
        }
    }


    // if it was possible to reach exit
    if (maze_vector[maze_vector.size() - 1][maze_vector[maze_vector.size() - 1].size() - 1] == 'P')
    {
        return true;
    }
    else
    {
        return false;
    }
}