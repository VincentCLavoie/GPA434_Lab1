/*  Asteroid.cpp
 *  Cette classe g�re une forme polygonale repr�sentante un ast�ro�de. Voici les �l�ments
 *  g�r�s par elle:
 *    - Sa forme polygone qui est irr�guli�re;
 *    - Sa vitesse (lin�aire et angulaire);
 *    - Sa position (lin�aire et angulaire);
 *    - Se dessiner � l'�cran par le biais de la classe Polygon.
 *
 *  ------------------------------------------------------------------------------------------
 *  Techniques � �tudier
 *  ------------------------------------------------------------------------------------------
 *    - Comment g�rer la forme polygonale repr�sentant un ast�ro�de;
 *    - Donner � un ast�ro�de un comportement propre:
 *       i) il a une forme irr�guli�re d'o� l'utilisation de random();
 *      ii) il poss�de une vitesse initiale (lin�aire et angulaire) al�atoire.
 *  ------------------------------------------------------------------------------------------
 *
 *  Commentaires et modification par: T. Wong
 *  01-2021
 *
 * Ce code respecte la norme de codage de GPA434:
 *    Nouveaux type de donn�es: PascalCase
 *    Variables, fonctions: camelCase
 */
#include "Asteroid.h"

// Constructeur par d�faut
Asteroid::Asteroid(float const& nbVertex, Vect2d const& pos, Vect2d const& vel, float const& angVel,
	                 float const& fillGrey)
	: mNbVertex{ nbVertex }, mPosition(pos), mVelocity(vel), mFillGrey(fillGrey),
	  mAngularPos{}, mAngularVel{ angVel }
{
	// Cet ast�ro�de aura mNbVertex de couleur mFillGrey dont le contour est noir d'une �paisseur de
	// 1.0f.
	mShape.buildasteroid(mNbVertex, Color(mFillGrey,mFillGrey,mFillGrey), Color(0.0f,0.0f,0.0f), 1.0f);
}

// Constructeur avec param�tres
// Note: Ce constructeur fait appel au constructeur par d�faut en choisissant al�atoirement
//       des valeurs entre min et max pour les param�tres.
Asteroid::Asteroid(float minNbVertex, float maxNbVertex, float minPosX, float maxPosX, float minPosY,
	                 float maxPosY, float minVel, float maxVel,float minAngVel,float maxAngVel,
	                 float minGrey, float maxGrey)
	: Asteroid(random(minNbVertex, maxNbVertex),
		Vect2d(random(minPosX, maxPosX), random(minPosY, maxPosY)),
		Vect2d(random(-25.0f, 25.0f), random(minVel, maxVel)),
		random(minAngVel,maxAngVel),
		random(minGrey,maxGrey))
{
}

// Destructeur
Asteroid::~Asteroid()
{
}

// --------------------------------------------------------------------------------------
// Accesseur(s) et mutateur(s) (fonctions membres)
// --------------------------------------------------------------------------------------
Vect2d Asteroid::position() const   
{
	return mPosition;
}

Vect2d Asteroid::velocity() const
{
	return mVelocity;
}

float Asteroid::angularPos() const
{
	return mAngularPos;
}

float Asteroid::angularVel() const
{
	return mAngularVel;
}

float Asteroid::nbVertex() const
{
	return mNbVertex;
}

void Asteroid::setPosition(Vect2d const& position)
{
	mPosition = position;
}

void Asteroid::setVelocity(Vect2d const& velocity)
{
	mVelocity = velocity;
}

void Asteroid::setAngularPos(float const& angularPos)
{
	mAngularPos = angularPos;
}

void Asteroid::setAngularVel(float const& angularVel)
{
	mAngularVel = angularVel;
}

void Asteroid::setNbVertex(float const& nbSummut)
{
	mNbVertex = nbSummut;
}

// --------------------------------------------------------------------------------------
// R�gler al�atoirement les param�tres de l'ast�ro�de incluant sa forme polygonale
// Choisir des valeurs entre min et max pour les param�tres de l'ast�ro�de
// --------------------------------------------------------------------------------------
void Asteroid::randomize(float minNbVertex, float maxNbVertex, float minPosX, float maxPosX, float minPosY,
	float maxPosY, float minVel, float maxVel, float minAngVel, float maxAngVel,
	float minGrey, float maxGrey)
{
	mNbVertex = random(minNbVertex, maxNbVertex);
	mPosition = Vect2d(random(minPosX, maxPosX), random(minPosY, maxPosY));
	mVelocity = Vect2d(random(-25.0f, 25.0f), random(minVel, maxVel));
	mAngularVel = random(minAngVel, maxAngVel);
	mFillGrey = random(minGrey, maxGrey);

	// Cet ast�ro�de aura mNbVertex de couleur mFillGrey dont le contour est noir d'une �paisseur de
	// 1.0f.
	mShape.buildasteroid(mNbVertex, Color(mFillGrey, mFillGrey, mFillGrey), Color(0.0f, 0.0f, 0.0f), 1.0f);
}

// --------------------------------------------------------------------------------------
// Mise � jour de la position lin�aire et angulaire de l'ast�ro�de
// Cette fonction membre est ex�cut�e p�riodiquement par l'Engine du jeu.
//
// Note: Nouvelle position = vitesse x temps
// --------------------------------------------------------------------------------------
void Asteroid::processTime(float const& elapsedTime)  // Update position vector
{
	mPosition += mVelocity * elapsedTime;
	mAngularPos += mAngularVel * elapsedTime;
}

// --------------------------------------------------------------------------------------
// Dessiner la forme polygonale dont le centre est au point mPosition
// Cette fonction membre est normalement ex�cut�e apr�s la MAJ de la position
// --------------------------------------------------------------------------------------
void Asteroid::draw(ezapp::Screen& screen) const
{
	mShape.draw(screen, mPosition.x(), mPosition.y(), mAngularPos);

}

void Asteroid::resetVerticalPosition(float const& height)
{
	mPosition.setY(-height);
}

void Asteroid::resetHorizontalPositionDown(float const& width)
{
	mPosition.setX(width);
}

// --------------------------------------------------------------------------------------
// Fonction membre priv�e pour g�n�rer un nombre al�atoire entre 0 et 1.
// --------------------------------------------------------------------------------------
float Asteroid::random(float min, float max) const
{
	return (float)rand() / (float)RAND_MAX * (max - min) + min;
}