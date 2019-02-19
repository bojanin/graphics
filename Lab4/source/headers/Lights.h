#pragma once

#include "Defines.h"
#include "HitRecord.h"
#include "Surface.h"
#include "Ray.h"

HitRecord findIntersection( const Ray & ray, const SurfaceVector & surfaces );


/**
* Base struct for all types of lights. Supports only specification of the 
* color and intensity of light sources. Parent of sub-structs that simulate
* positional, directional, and spot lights.
*
* Instances of this struct an be used to simulate only ambient light. Ambient
* light is described as bounced light that has been scattered so much that it
* is impossible to tell the direction to its source. If using a LightSource 
* instantiation to simulate ambient light, the overall intensity of the light
* should be low in order to avoid washing out shadows as well as diffuse and 
* specular effects that can be achieved when using children of this struct.
*/
struct LightSource
{
	LightSource(const color & lightColor) 
	: diffuseLightColor(lightColor)
	{
		ambientLightColor = 0.15 * diffuseLightColor;
		specularLightColor = WHITE;
	}

	virtual color illuminate(const dvec3 & eyeVector, HitRecord & closestHit, const SurfaceVector & surfaces)
	{
		return BLACK;
	}




	/*
	* Ambient color and intensity of the light.
	*/
	color ambientLightColor;

	/* 
	* Diffuse color and intensity of the light.
	*/
	color diffuseLightColor; 

	/*
	 * Specular color and intensity of the light.
	 */
	color specularLightColor;
};

/**
* Struct for simulating light sources that have an explicit position and 
* shine equally in all directions. Instantiations of the struct will have
* a position property and a color and intensity of the light given off
* by the light.
*/
struct PositionalLight : public LightSource
{
	PositionalLight(glm::dvec3 position, const color & lightColor)
	: LightSource(lightColor), lightPosition(position)
	{}

	virtual color illuminate(const glm::dvec3 & eyeVector, HitRecord & closestHit, const SurfaceVector & surfaces)
	{
		return BLACK;
	}


	/**
	* x, y, z position of the light source. 
	*/
	glm::dvec3 lightPosition; 
};

/**
* Struct for simulating light sources that do not have an explicit position.
* Such light sources have only a direction against which they are shinning.
* Instantiations of the struct will have this direction properties along with
* a color and intensity of the light given off by the light source.
*/
struct DirectionalLight : public LightSource
{
	DirectionalLight(dvec3 direction, const color & lightColor)
	: LightSource(lightColor), lightDirection(glm::normalize(direction))
	{}

	virtual color illuminate(const dvec3 & eyeVector, HitRecord & closestHit, const SurfaceVector & surfaces)
	{
		return BLACK;
	}

	/**
	* Unit vector that points in the direction that is opposite 
	* the direction in which the light is shining.
	*/
	glm::dvec3 lightDirection; 
};


