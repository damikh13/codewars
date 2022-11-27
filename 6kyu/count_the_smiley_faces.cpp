#include <vector>
#include <string>

int countSmileys(std::vector<std::string> arr)
{
    if (arr.size() == 0) return 0; // if there are no faces, return 0 

    int cnt = 0;
    bool proper_eyes, proper_nose, proper_mouth;

    for (size_t i = 0; i < arr.size(); ++i) { // iterate through array
        std::string curr_face = arr[i]; // get current face
        proper_eyes = (curr_face[0] == ':' || curr_face[0] == ';') ? true : false; // check if eyes are proper

        if (curr_face.size() == 2) // check if face has 2 characters
        {
            proper_mouth = (curr_face[1] == ')' || curr_face[1] == 'D') ? true : false; // check if mouth is proper
            if (proper_eyes && proper_mouth) // if eyes and mouth are proper, increment counter
            {
                cnt++; 
            }
        }
        else if (curr_face.size() == 3) // check if face has 3 characters
        {
            proper_nose = (curr_face[1] == '-' || curr_face[1] == '~') ? true : false; // check if nose is proper
            proper_mouth = (curr_face[2] == ')' || curr_face[2] == 'D') ? true : false; // check if mouth is proper
            if (proper_eyes && proper_nose && proper_mouth) // if eyes, nose and mouth are proper, increment counter
            {
                cnt++;
            }
        }
    }

    return cnt;
}