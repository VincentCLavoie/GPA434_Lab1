#include "MissileGuide.h"


// Constructeur avec paramètres
MissileGuide::MissileGuide(float origineX, float origineY)
	: mPosition(origineX, origineY),
	mVelocity(),
	mAngularPos{},
	mAngularVel{},
	mMissileShot{}

{
	// Le vaisseau spatial aura la couleur noire, des traits blancs d'épaisseur de 1. Le point au centre
	// du vaisseau est à (0, 0).
	mShape.buildMissile(Color(2.0f, 7.0f, 4.0f, 8.0f), Color(0.0f, 0.0f, 0.0f, 1.0f), 0.0f, 0.0f);
}

// Destructeur
MissileGuide::~MissileGuide()
{
	// do nothing
}


// Accesseur(s) et mutateur(s) (fonctions membres)
Vect2d MissileGuide::position() const
{
	return mPosition;
}

Vect2d MissileGuide::velocity() const
{
	return mVelocity;
}

float MissileGuide::angularPos() const
{
	return mAngularPos;
}

float MissileGuide::angularVel() const
{
	return mAngularVel;
}

bool MissileGuide::missileShot() const
{
	return mMissileShot;
}

void MissileGuide::setPosition(Vect2d const& position)
{
	mPosition = position;
}

void MissileGuide::setVelocity(Vect2d const& velocity)
{
	mVelocity = velocity;
}

void MissileGuide::setAngularPos(float const& angularPos)
{
	mAngularPos = angularPos;
}

void MissileGuide::setAngularVel(float const& angularVel)
{
	mAngularVel = angularVel;
}

void MissileGuide::setMissileShot(bool const& missileShot)
{
	mMissileShot = missileShot;
}

// --------------------------------------------------------------------------------------
// Dessiner la forme polygonale dont le centre est au point mPosition
// Cette fonction membre est normalement exécutée après la MAJ de la position
// --------------------------------------------------------------------------------------

void MissileGuide::processTime(float const& elapsedTime)
{
	mPosition += mVelocity * elapsedTime;
	mAngularPos += mAngularVel * elapsedTime;
}

void MissileGuide::draw(ezapp::Screen& screen) const
{
	mShape.draw(screen, mPosition.x(), mPosition.y(), mAngularPos);
}

void MissileGuide::collison()
{
	mMissileShot = false;
	setPosition(Vect2d(-10.0f, -10.0f));
}