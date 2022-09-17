/*  Asteroid.cpp
 *  Cette classe gère une forme polygonale représentante un astéroïde. Voici les éléments
 *  gérés par elle:
 *    - Sa forme polygone qui est irrégulière;
 *    - Sa vitesse (linéaire et angulaire);
 *    - Sa position (linéaire et angulaire);
 *    - Se dessiner à l'écran par le biais de la classe Polygon.
 *
 *  ------------------------------------------------------------------------------------------
 *  Techniques à étudier
 *  ------------------------------------------------------------------------------------------
 *    - Comment gérer la forme polygonale représentant un astéroïde;
 *    - Donner à un astéroïde un comportement propre:
 *       i) il a une forme irrégulière d'où l'utilisation de random();
 *      ii) il possède une vitesse initiale (linéaire et angulaire) aléatoire.
 *  ------------------------------------------------------------------------------------------
 *
 *  Commentaires et modification par: T. Wong
 *  01-2021
 *
 * Ce code respecte la norme de codage de GPA434:
 *    Nouveaux type de données: PascalCase
 *    Variables, fonctions: camelCase
 */
#include "Asteroid.h"

// Constructeur par défaut
Asteroid::Asteroid(float const& nbVertex, Vect2d const& pos, Vect2d const& vel, float const& angVel,
	                 float const& fillGrey)
	: mNbVertex{ nbVertex }, mPosition(pos), mVelocity(vel), mFillGrey(fillGrey),
	  mAngularPos{}, mAngularVel{ angVel }
{
	// Cet astéroïde aura mNbVertex de couleur mFillGrey dont le contour est noir d'une épaisseur de
	// 1.0f.
	mShape.buildasteroid(mNbVertex, Color(mFillGrey,mFillGrey,mFillGrey), Color(0.0f,0.0f,0.0f), 1.0f);
}

// Constructeur avec paramètres
// Note: Ce constructeur fait appel au constructeur par défaut en choisissant aléatoirement
//       des valeurs entre min et max pour les paramètres.
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
// Régler aléatoirement les paramètres de l'astéroïde incluant sa forme polygonale
// Choisir des valeurs entre min et max pour les paramètres de l'astéroïde
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

	// Cet astéroïde aura mNbVertex de couleur mFillGrey dont le contour est noir d'une épaisseur de
	// 1.0f.
	mShape.buildasteroid(mNbVertex, Color(mFillGrey, mFillGrey, mFillGrey), Color(0.0f, 0.0f, 0.0f), 1.0f);
}

// --------------------------------------------------------------------------------------
// Mise à jour de la position linéaire et angulaire de l'astéroïde
// Cette fonction membre est exécutée périodiquement par l'Engine du jeu.
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
// Cette fonction membre est normalement exécutée après la MAJ de la position
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
// Fonction membre privée pour générer un nombre aléatoire entre 0 et 1.
// --------------------------------------------------------------------------------------
float Asteroid::random(float min, float max) const
{
	return (float)rand() / (float)RAND_MAX * (max - min) + min;
}