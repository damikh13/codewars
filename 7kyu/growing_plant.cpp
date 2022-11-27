int growingPlant(int upSpeed, int downSpeed, int desiredHeight) // returns the number of days it takes for the plant to reach desiredHeight
{
    int days = 0; // the number of days it takes for the plant to reach desiredHeight
    int height = 0; // the current height of the plant

    while (height < desiredHeight) // while height is less than desired height
    {
        height += upSpeed; // add upSpeed to height
        days++; // increment days
        if (height >= desiredHeight) // if height is greater than or equal to desired height
        {
            break; // break out of loop
        }
        height -= downSpeed; // subtract downSpeed from height
    }

    return days;
}