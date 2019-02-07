#include "Lab2.h"


/**
* LAB2 INSTRUCTIONS:
* Below are description of problems in vector arithmetic. Each problem has
* at least one or two functions associated with it (functions - not methods.
* there is not a class). There is a function call in the main for each one
* of the problems. For each problem, write the necessary code to solve it.
* All console output should be labeled. Do NOT simply print a number. Make
* sure there is text that indicates what the number is and possibly its
* significance.
*
* You may find it helpful to have the chapter 2 lecture notes handy as you
* work through the problems. As you are moving from problem to problem, you
* may want to comment out some of the function calls in the main so that you
* easily see the output for the current problem. Uncomment all function calls
* before turning in the lab. BasicIncludesAndDefines includes definitions of
* simple functions for printing vec2, vec3, and vec4 objects to the console.
*
* When you have completed all the problems, complete the following turnin
* instructions:
*
*	1.	Copy the folder containing your solution to the desktop.
*	2.	Change the name of the folder to CSE287LabTwo followed by your unique
*		identifier. For instance “CSE287LabTwoBachmaer.”
*	3.	Open the solution. Make sure it still runs.
*	4.	Clean the solution by selecting Build->Clean Solution. (The will delete
*		all the intermediate temporary files that are part of your project and
*		reduce the size of your submission.)
*	5.	Make sure your solution does not include a .sdf file of a ipch folder.
*   6.  Zip up the solution folder using the standard windows compression tool.
*		(No 7zips, rars, etc.)
*	7.	Submit the zip archive of your solution through canvas.

*/


// Suppose x equals 45 degrees. Write a statement (without glm) that does the necessary 
// calculation to convert this value to radians. Print out the resulting 
// value. Write another statement that uses the correct glm function
// to convert x to radians. Print out the resulting value.
void problem1()
{
	std::cout << "Problem 1" << std::endl;

	double x = 45.0;

    // radians = (pi * degrees) / 180;
    double radians = ( M_PI / 180.0) * x;
    std::cout << "Radians: " << radians << endl;

} // end Problem1


// Suppose x equals 2.0943951 radians. Write a statement (without glm) that does the 
// necessary calculation to convert this value to degrees. Print out the
// resulting value. Write another statement that uses the correct glm 
// function to convert x to degrees. Print out the resulting value.
// This website can be used to check calculations for this and the next few
// problems: http://www.rapidtables.com/calc/math/index.htm
void problem2()
{
	std::cout << "Problem 2" << std::endl;

	double x = 2.0943951;

    double degrees = (180.0 / M_PI) * x;
    std::cout << "Degrees: " << degrees << endl;

    double glm_degrees = glm::degrees(x);
    std::cout << "glm_degrees: " << glm_degrees << endl;

} // end Problem2


// Suppose the cosine of an angle theta is 0.34202014332566873304409961468226.
// Use a trigometric function to determine theta. Print out the angle in 
// both degrees and radians.
void problem3()
{
	std::cout << "Problem 3" << std::endl;
	double cosTheta = 0.34202014332566873304409961468226;

    // glm::acos(x) return the angle in Radians
    double angle_radians = glm::acos(cosTheta);
    double angle_degrees = glm::degrees(angle_radians);
    
    // cos = angle / height
    cout << "Radians: " << angle_radians << endl;
    cout << "Degrees: " << angle_degrees << endl;

} // end Problem3


// Suppose the vector v = [4 -6 7]. Create three vectors: 
// 1. p, which is twice as long as v and points in the same direction as v
// 2. q, which has the same length as v and points in the opposite direction of v 
// 3. r, which is three quarters the length of v and points in the same direction as v
// Print out the results of each vector calculation.
void problem4()
{
	std::cout << "Problem 4" << std::endl;
	glm::vec3 v(4, -6, 7);

    glm::vec3 p = v * 2.0;
    glm::vec3 q = -v;  
    glm::vec3 r = v * 0.75;
    
    cout << "vector v: " << glm::to_string(v) << endl;
    cout << "vector p: " << glm::to_string(p) << endl;
    cout << "vector q: " << glm::to_string(q) << endl;
    cout << "vector r: " << glm::to_string(r) << endl;

} // end Problem4


// Write a function that compares two vec3s for equality by comparing 
// individual components. It should return true if the vectors are equal 
// and false otherwise. Check for correctness by using equal and unequal
// vec3s. Print out the results. Vertify that the same results are obtained
// when using the overloaded '==' operator. Print out the results.
bool vectorEquality(const glm::vec3 & v, const glm::vec3 & w)
{
    return 
    (v.x == w.x) &&
    (v.y == w.y) &&
    (v.z == w.z);   

} // end vectorEquality

void problem5()
{
	std::cout << "Problem 5" << std::endl;

    glm::vec3 v(4, 4, 4);
    glm::vec3 q(4, 4, 4);
    glm::vec3 r(1, 2, 3);
    
    cout << "vector v: " << glm::to_string(v) << endl;
    cout << "vector q: " << glm::to_string(q) << endl;
    cout << "vector r: " << glm::to_string(r) << endl;

    cout << "v == q: " << vectorEquality(v, q) << endl;
    cout << "v == r: " << vectorEquality(v, r) << endl;
    cout << "q == r: " << vectorEquality(q, r) << endl;

} // end Problem5


// Write a function that calculates and returns the length of a vector. 
// Call the function on the vector v = [2 3 4]. Perform this same calculation
// using the glm length function. Print out the results of both calculations.
double myLength(const glm::vec3 & v)
{
    // length of 3d vector = sqrt (x^2 + y^2 + z^2)

    double squared = pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2); 
    return sqrt(squared);

} // end myLength


void problem6()
{
	std::cout << "Problem 6" << std::endl;

	glm::vec3 v(2, 3, 4);
    std::cout << "Length of v (myLength function used): " << myLength(v) << endl;
    std::cout << "Length of v (glm::length used): " << glm::length(v) << endl;
    
} // end Problem6


// Write a function that calculates and returns the unit length version of a vec3
// that is received as an argument. Call the function on the vector v = [2 3 4]. 
// Perform this same calculation using the glm normalize function. Print out
// the results of both calculations.
glm::vec3 myUnitVector(const glm::vec3 & v)
{

    double divisor = myLength(v);
    return glm::vec3(v.x / divisor, v.y / divisor, v.z / divisor);    

} // end myUnitVector


void problem7()
{
	std::cout << "Problem 7" << std::endl;

	glm::vec3 v(2, 3, 4);
    glm::vec3 myVec(myUnitVector(v));
    glm::vec3 normalized_vec(glm::normalize(v));
    
    std::cout << "myUnitVector func vector: " << glm::to_string(myVec) << endl;
    std::cout << "glm::normalize vector: " << glm::to_string(normalized_vec) <<endl;

} // end Problem7


// Suppose the vector v = [-4 2 -3]. Create three vectors:
// 1. p, which points in the same direction, but has a length of one
// 2. q, which points in the same direction, but has a length of three
// 3. r, which points in the opposite direction and has a length of five
// Print out the results of each vector calculation.
// (Feel free to use the glm normalize function for this problem.)
void problem8()
{
	std::cout << "Problem 8" << std::endl;
    #warning LOOK AT THIS AGAIN 
	glm::vec3 v(-4, 2, -3);

    glm::vec3 p(glm::normalize(v));
    glm::vec3 q(glm::normalize(v) * 3.0);
    glm::vec3 r(-glm::normalize(v) * 5.0);

    std::cout << "vector v: " << glm::to_string(v) << endl;
    std::cout << "vector p: " << glm::to_string(p) << endl;
    std::cout << "vector q: " << glm::to_string(q) << endl;
    std::cout << "vector r: " << glm::to_string(r) << endl;

} // end Problem8


// Suppose the vector v = [2 -6 3] and the vector w = [-4 3 10]
// Add the two vectors together using the overloaded glm addition operator. 
// Print the resulting sum.
void problem9()
{
	std::cout << "Problem 9" << std::endl;

	glm::vec3 v(2, -6, 3);
	glm::vec3 w(-4, 3, 10);

    std::cout << "v + w = " << glm::to_string(v + w) << endl;

} // end Problem9


// Suppose someone walks three miles north and then seven miles west. 
// Assume they started at position (0,0). Assume the X axis points north.
// Use vector arithmetic to determine the coordinates of their finishing 
// point. Print the result. Also print a result that shows that it does 
// not matter whether they walk north or west first. You will want to use separate
// vectors to represent each walking direction.
void problem10()
{
	std::cout << "Problem 10" << std::endl;

    // x is north/south (+3), y is east/west (-7)
	glm::vec2 north(3, 0);
	glm::vec2 west(0, -7);

    cout<< "North first, then west: " << glm::to_string(north + west) << endl;
    cout<< "West first, then north" << glm::to_string(west + north) << endl;

} // end Problem10


// Suppose the person in the previous quesion starts at (3,4). What would
// their finishing point be? Print the result.
void problem11()
{
	std::cout << "Problem 11" << std::endl;

	glm::vec2 position(3, 4);
	glm::vec2 north(3, 0);
	glm::vec2 west(0, -7);

    std::cout << "position + north + west: " << glm::to_string(position + north + west) << endl;

} // end Problem11


// Use two vectors to show that vector subtraction is not communitive.
// Print the vectors and the values that indicate the fact.
void problem12()
{
	std::cout << "Problem 12" << std::endl;

    glm::vec2 x(3, 9);
    glm::vec2 y(10, 20);

    std::cout << "x: " << glm::to_string(x) << endl;
    std::cout << "y: " << glm::to_string(y) << endl;

    std::cout << "x - y: " << glm::to_string(x - y) << endl;
    std::cout << "y - x: " << glm::to_string(y - x) << endl;

} // end Problem12


// Write a function that calculates the dot product of two vec3s and returns
// this scalar value as a double. Use the vectors v = [2 6 3] and w = [-4 3 10] 
// to show that your function produces the same value as the glm dot function.
// Print the results.
double myDot(const glm::vec3 a, const glm::vec3 b)
{
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
} // end myDot


void problem13()
{
	std::cout << "Problem 13" << std::endl;

	glm::vec3 v(2, 6, 3);
	glm::vec3 w(-4, 3, 10);

    std::cout << "myDot dot product: " << myDot(v,w) << endl;
    std::cout << "glm::dot dot product: " << glm::dot(v,w) << endl;

} // end Problem13


// Use the dot product to find the cosines of the angles that the vector 
// v = [-2 1 3] makes with each of the following vectors. Print out the
// values. 
//   x = [2 6 3] (result should be 0.419982)
//   w = [-4 3 10]
//   q = [3 0 0]
void problem14()
{
	std::cout << "Problem 14" << std::endl;

	glm::vec3 v(-2, 1, 3);
	glm::vec3 x(2, 6, 3);
	glm::vec3 w(-4, 3, 10);
	glm::vec3 q(3, 0, 0);

    double magnitude_v = myLength(v);
    double magnitude_x = myLength(x);
    double magnitude_w = myLength(w);
    double magnitude_q = myLength(q);

    double dot_vx = glm::dot(v,x);
    double dot_vw = glm::dot(v,w);
    double dot_vq = glm::dot(v,q);

    cout << "cosTheta of v & x: " << (dot_vx) / ( magnitude_v * magnitude_x ) << endl;
    cout << "cosTheta of v & w: " << (dot_vw) / ( magnitude_v * magnitude_w ) << endl;
    cout << "cosTheta of v & q: " << (dot_vq) / ( magnitude_v * magnitude_q ) << endl;

} // end Problem14


// Write a function that compares two vec3s. If they are: 
//   within 90 degrees of each other, return 1
//   perpendicular, return 0
//   more than 90 degrees apart, return -1 
// Do not use any trigometric functions.
// Use the following vectors to demonstrate that your
// function works:
//   v = [0 10 0]
//   w = [10 0 0]
//   x = [-1 9 0]
// v and w are perpendicular, v and x are within 90 degrees, and 
// w and x are more than 90 degrees apart.
// Print your results.
int vectorCompare(glm::vec3 a, glm::vec3 b)
{
    double dot_ab = myDot(a,b);
    double magnitude_a = myLength(a);
    double magnitude_b = myLength(b);

    double cosTheta = dot_ab / (magnitude_a * magnitude_b);

    if(cosTheta > 0) {
        return 1;
    } else if (cosTheta < 0) {
        return -1;
    } else {
        return 0;
    }
} // end vectorCompare

void problem15()
{
	std::cout << "Problem 15" << std::endl;

	glm::vec3 v(0, 10, 0);
	glm::vec3 w(10, 0, 0);
	glm::vec3 x(-1, 9, 0);

    std::cout << "vectorCompare(v,w): " << vectorCompare(v,w) << endl;
    std::cout << "vectorCompare(v,x): " << vectorCompare(v,x) << endl;
    std::cout << "vectorCompare(x,w): " << vectorCompare(x,w) << endl;

} // end Problem15


// Write a function that finds the projection of one vector onto another and 
// returns it as a double. Use it to find the projection of v = [2 6 3] onto 
// w = [-4 3 10]. Print the result.
// (To check your method, call project for the values [3 4 5] onto [2 -2 3].
// The result should be 3.152963.)
double project(glm::vec3 from, glm::vec3 onto)
{
// from = a, onto = b

    double dot_ab = glm::dot(from,onto);
    double magnitude_b = myLength(onto);    

    return dot_ab / abs(magnitude_b);
} // end project


void problem16()
{
	std::cout << "Problem 16" << std::endl;

	glm::vec3 v(3, 4, 5);
	glm::vec3 w(2, -2, 3);
	glm::vec3 r(2, 6, 3);
	glm::vec3 q(-4, 3, 10);
    std::cout << "projection of [3, 4, 5] onto [2, -2, 3]: " << project(v,w) << endl;
    std::cout << "projection of [2, 6, 3] onto [-4, 3, 10]: " << project(r, q) << endl;

} // end Problem16


// Take the cross product of the vectors v = [2 6 3] and w = [-4 3 10]. Use the glm cross
// product function. Print the result. Use the dot product to verify that the resulting
// product is perpendicular to each of the multiplicands. Print the result.
void problem17()
{
	std::cout << "Problem 17" << std::endl;

	glm::vec3 v(2, 6, 3);
	glm::vec3 w(-4, 3, 10);
    glm::vec3 dot(glm::dot(v,w)); 
    std::cout << "dot product of (v,w): " << glm::to_string(dot)<< endl;
    std::cout << "cross product of (v,w): " << glm::to_string(glm::cross(v, w)) << endl;
    
} // end Problem17


// Calculate the cross product v x w and then w x v. Use the vectors v = [2 6 3] 
// and w = [-4 3 10]. Print each of the products. Verify that cross product is not
// commutitative by checking for equality or by adding the two products together 
// and checking the sum. Print the result.
void problem18()
{
	std::cout << "Problem 18" << std::endl;

	glm::vec3 v(2, 6, 3);
	glm::vec3 w(-4, 3, 10);
    std::cout << "cross product of v x w: " << glm::to_string(glm::cross(v,w)) << endl;
    std::cout << "cross product of w x v: " << glm::to_string(glm::cross(w,v)) << endl;

} // end Problem18


// Write a function that has three vec3 parameters. The parameters should give 
// three corners of a parallelogram in counter-clockwise order. In the function
// use the cross product to calculate the area of the parallelogram. Test the
// function with the following vertices: x = [0 2 0], y = [0 0 0], and z = [4 0 0]. Print the 
// result. Then test the function with another three vertices of your choosing.
// Print out this area as well. 
// (To check your method, call areaOfParallelogram with the values [0 3 0], [0 0 0], 
// and [3 0 0]. The result should be 9.)
double areaOfParallelogram(glm::vec3 a, glm::vec3 b, glm::vec3 c)
{
    return myLength(glm::cross(c-a, b - a));

} // end areaOfParallelogram


void problem19()
{
	std::cout << "Problem 19" << std::endl;

	glm::vec3 x(0, 2, 0);
	glm::vec3 y(0, 0, 0);
	glm::vec3 z(4, 0, 0);
    
    glm::vec3 t(3,2,2);
    glm::vec3 o(0,0,0);
    glm::vec3 m(10,10,10);

    glm::vec3 a(0, 3, 0);
    glm::vec3 b(0, 0, 0);
    glm::vec3 c(3, 0, 0);

    std::cout << "area of abc: " << areaOfParallelogram(a,b,c) << endl;
    std::cout << "area of xyz: " << areaOfParallelogram(x,y,z) << endl;
    std::cout << "area of tom: " << areaOfParallelogram(t,o,m) << endl;
} // end Problem19


// Write a function that has three vec3 parameters. The parameters should give 
// three corners of a triangle in counter-clockwise order. In the function
// use the cross product to either calculate the area of the triangle, or call the 
// function you wrote for the previous quesion and multiply the returned area
// by one half. Test the function with the following vertices: x = [0 2 0],
// y = [0 0 0], and z = [4 0 0]. Print the result. Then test the function with another
// three vertices of your choosing. Print out this area as well. 
double triangleArea(glm::vec3 a, glm::vec3 b, glm::vec3 c)
{

	return 0.5 * areaOfParallelogram(a,b,c);

} // end triangleArea


void problem20()
{
	std::cout << "Problem 20" << std::endl;

	glm::vec3 x(0, 2, 0);
	glm::vec3 y(0, 0, 0);
	glm::vec3 z(4, 0, 0);

	glm::vec3 a(10, 0, 0);
	glm::vec3 b(0, 10, 0);
	glm::vec3 c(0, 0, 10);

    std::cout << "area of xyz: " << triangleArea(x,y,z) << endl;
    std::cout << "area of abc: " << triangleArea(a,b,c) << endl;
} // end Problem20


// Write a function that has two vec3 parameters. The function should find and 
// return a unit length vector that points from the position described by 
// the first vec3 to the position described by the second vec3. Test the 
// function with the following vectors: x = [0 4 0] and y = [4 0 0]. Print the 
// result.
glm::vec3 findPointingVector(glm::vec3 first, glm::vec3 second)
{

    return second - first;	

} // end findPointingVector

void problem21()
{
	std::cout << "Problem 21" << std::endl;

	glm::vec3 x(0, 4, 0);
	glm::vec3 y(4, 0, 0);

    std::cout << "vector x -> y: " << glm::to_string(findPointingVector(x,y)) << endl;

} // end Problem21


// Write a function that has two vec3 parameters. The function should find find
// the angle between the two vectors by computing the dot product and then 
// using the arccos function (acos). The agled returned should be in degrees.
// result. Test it using two vectors that you determine the angel between 
// by "inspection."
double findAngle(glm::vec3 first, glm::vec3 second)
{

	double magnitude_first = myLength(first);
    double magnitude_second = myLength(second);

    double dot_ab = glm::dot(first,second);
    double cosTheta = dot_ab / (magnitude_first * magnitude_second);

    return glm::degrees(glm::acos(cosTheta));

} // end findAngle


void problem22()
{
	std::cout << "Problem 22" << std::endl;

	glm::vec3 x(0, 4, 0);
	glm::vec3 y(4, 0, 0);
	glm::vec3 a(0, -2, 0);
    glm::vec3 b(0, 2, 0); // angle should be 180 degrees
    std::cout << "angle between x & y: " << findAngle(x,y) << endl;
    std::cout << "angle between a & b (180) : " << findAngle(a,b) << endl;

} // end Problem22


int main(int argc, char** argv)
{
	// To keep the console open on shutdown, start the project with Ctrl+F5 instead of just F5.

	problem1();
	problem2();
	problem3();
	problem4();
	problem5();
	problem6();
	problem7();
	problem8();
	problem9();
	problem10();
	problem11();
	problem12();
	problem13();
	problem14();
	problem15();
	problem16();
	problem17();
	problem18();
	problem19();
	problem20();
	problem21();
	problem22();

} // end main
