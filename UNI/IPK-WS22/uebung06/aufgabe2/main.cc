#include "point.hh"
#include <iostream>
#include <vector>
#include <array>


int main(){


    Point<int, 1> OneDArray = {{1}};       
    Point<int, 3> ThreeDArray = {{4,5,6}}; 

    Point<int, 1> EmptyOneDArray;   
    Point<int, 3> EmptyThreeDArray; 

    std::cout << "Wert von index 0 in OneDArray: " << OneDArray[0] << std::endl; 
    std::cout << "Wert von index 1 in ThreeDArray: " << ThreeDArray[1] << std::endl; 
    std::cout << "Wert von index 0 in EmptyOneDArray: " << EmptyOneDArray[0] << std::endl; 
    std::cout << "Wert von index 2 in EmptyOneDArray: " << EmptyThreeDArray[2] << "\n" << std::endl; 

    
    std::cout << "Norm von OneDArray: " << OneDArray.norm() << std::endl; 
    std::cout << "Norm von ThreeDArray: " << ThreeDArray.norm() << std::endl; 
    std::cout << "Norm von EmptyOneDArray: " << EmptyOneDArray.norm() << std::endl; 
    std::cout << "Norm von EmptyThreeDArray: " << EmptyThreeDArray.norm() << "\n" << std::endl; 

    
    std::cout << "Dimension von OneDArray: " << OneDArray.dimension << std::endl; 
    std::cout << "Dimension von ThreeDArray: " << ThreeDArray.dimension << std::endl; 
    std::cout << "Dimension von EmptyOneDArray: " << EmptyOneDArray.dimension << std::endl; 
    std::cout << "Dimension von EmptyThreeDArray: " << EmptyThreeDArray.dimension << std::endl; 
}
