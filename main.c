#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SZ 3
//* Display parallel array data for height by year
void displayHeightDataArray(int year[], double height[], int arrSize);

void displayHeightData(int *year, double *height, int arrSize);

struct HeightInfo
{
    int year2;
    double height2;
};

//* Display height data (pass by value);
void displayHeightDataBA(struct HeightInfo* data);
//* Display height data (pass by value)
void displayHeightDataBV(struct HeightInfo data);
int main()
{

    //* Parallel array's: Track height of a child every 5 years over
    //*            a 10 year period:
    int year[SZ] = {2010, 2015, 2020};    //* Year the height was recorded
    double height[SZ] = {5.24, 5.5, 5.7}; //* Height measured for the given year

    int i;              //* General purpose iterator
    int *y = year;      //* &year[1]
    double *h = height; //* &height[0]
    for (i = 0; i < SZ; i++)
    {
        printf("Year: %d Height (ft): %.2lf\n", year[i], height[i]);
        printf("Year: %d Height (ft): %.2lf\n", y[i], h[i]);

        displayHeightDataArray(year, height, SZ);
        displayHeightData(year, height, SZ);

        //* Height Measurement in year 2010
        struct HeightInfo heigtData = {2010, 5.24};

        //*Pass by value:
        displayHeightDataBV(heigtData);

        //* Display height data information:

        //*  Pass by address:
        displayHeightDataBA(&heigtData);
    }

    return 0;
}

//* Pass by value:
void displayHeightDataBV(struct HeightInfo data)
{
    printf("Year: %d Height (ft): %.2lf\n", data.year2, data.height2);
}

//* Pass by Address:
void displayHeightInfoDataBA(struct HeightInfo* data){
    printf("Year: %d Height (ft) : %.2lf", data->year2, data->height2);
}
void displayHeightDataArray(int years[], double heights[], int arrSize)
{
    int i;
    for (i = 0; i < SZ; i++)
    {
        printf("Year: %d Height (ft): %.2lf\n", years[i], heights[i]);
    }
}

void displayHeightData(int *years, double *heights, int arrSize)
{
    int i;
    for (i = 0; i < SZ; i++)
    {
        printf("Year: %d Height (ft): %.2lf\n", years[i], heights[i]);
    }
}
