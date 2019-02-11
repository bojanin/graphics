#include "Defines.h"

#include <iomanip>

color getRandomColor()
{
	float red = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	float green = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	float blue = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

	return color(red, green, blue, 1.0);

} // end getRandomColor


/**
* @fn	ostream &operator << (ostream &os, const dvec2 &V)
* @brief	Output stream for vec2.
* @param	os		Output stream.
* @param	V		The vector.
*/

ostream &operator << ( ostream &os, const dvec2 &V )
{
	os << "[ " << V.x << " " << V.y << " ]";
	return os;
}

/**
* @fn	ostream &operator << (ostream &os, const dvec3 &V)
* @brief	Output stream for vec3.
* @param	os		Output stream.
* @param	V		The vector.
*/

ostream &operator << ( ostream &os, const dvec3 &V )
{
	os << "[ " << V.x << " " << V.y << " " << V.z << " ]";
	return os;
}

/**
* @fn	ostream &operator << (ostream &os, const dvec4 &V)
* @brief	Output stream for vec4.
* @param	os		Output stream.
* @param	V		The vector.
*/

ostream &operator << ( ostream &os, const dvec4 &V )
{
	os << "[ " << V.x << " " << V.y << " " << V.z << " " << V.w << " ]";
	return os;
}

/**
* @fn	ostream &operator << (ostream &os, const dmat432 &M)
* @brief	Output stream for mat2.
* @param	os		Output stream.
* @param	M		The matrix.
*/

ostream &operator << ( ostream &os, const dmat2 &M )
{
	os << "\n";
	for( int row = 0; row < 2; row++ ) {
		os << "|\t";
		for( int col = 0; col < 2; col++ ) {
			os << std::setw( 8 ) << std::setprecision( 4 ) << M[col][row] << "\t";
		}
		os << "|\n";
	}
	os << "\n";
	return os;
}

/**
* @fn	ostream &operator << (ostream &os, const dmat3 &M)
* @brief	Output stream for mat3.
* @param	os		Output stream.
* @param	M		The matrix.
*/

ostream &operator << ( ostream &os, const dmat3 &M )
{
	os << "\n";
	for( int row = 0; row < 3; row++ ) {
		os << "|\t";
		for( int col = 0; col < 3; col++ ) {
			os << std::setw( 8 ) << std::setprecision( 4 ) << M[col][row] << "\t";
		}
		os << "|\n";
	}
	os << "\n";
	return os;
}

/**
* @fn	ostream &operator << (ostream &os, const dmat4 &M)
* @brief	Output stream for mat4.
* @param	os		Output stream.
* @param	M		The matrix.
*/

ostream &operator << ( ostream &os, const dmat4 &M )
{
	os << "\n";
	for( int row = 0; row < 4; row++ ) {
		os << "|\t";
		for( int col = 0; col < 4; col++ ) {
			os << std::setw( 8 ) << std::setprecision( 4 ) << M[col][row] << "\t";
		}
		os << "|\n";
	}
	os << "\n";
	return os;
}


//void print(const glm::dvec2 & v0)
//{
//	std::cout << "[ " << v0.x << " " << v0.y << " ]" << std::endl;
//}
//
//void print(const glm::dvec3 & v0)
//{
//	std::cout << "[ " << v0.x << " " << v0.y << " " << v0.z << " " << " ]" << std::endl;
//}
//
//void print(const glm::dvec4 & v0)
//{
//	std::cout << "[ " << v0.x << " " << v0.y << " " << v0.z << " " << v0.w << " ]" << std::endl;
//}
//
//
//void print(const glm::dmat2 & m)
//{
//	std::cout << "\n";
//
//	for (int row = 0; row < 2; row++) {
//		std::cout << "|\t";
//		for (int col = 0; col < 2; col++) {
//			std::cout << m[col][row] << "\t";
//		}
//		std::cout << "|\n";
//	}
//	std::cout << "\n";
//
//}
//
//void print(const glm::dmat3 & m)
//{
//	std::cout << "\n";
//	for (int row = 0; row < 3; row++) {
//		{
//			std::cout << "|\t";
//			for (int col = 0; col < 3; col++) {
//				std::cout << m[col][row] << "\t";
//			}
//		}
//		std::cout << "|\n";
//	}
//	std::cout << "\n";
//}
//
//void print(const glm::dmat4 & m)
//{
//	std::cout << "\n";
//
//	for (int row = 0; row < 4; row++) {
//		std::cout << "|\t";
//		for (int col = 0; col < 4; col++) {
//			std::cout << m[col][row] << "\t";
//		}
//		std::cout << "|\n";
//	}
//	std::cout << "\n";
//
//}





